// Library that simplifies interfacing with janus and sdm for subsea acoustic communication
// This library requires that sdmsh and janus is installed

// This library is not an ideal solution
// An ideal version was not chosen due to time-constraints, lack of experience and lack of documentation for both janus.h and sdm.h
// People seeking to implement an efficent version of JANUS with sdm should look into implementing the libraries directly

#define LIBNAME "janusxsdm"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<stdio.h>
#include<array>
#include<chrono>
#include<thread>
#include<mutex>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iterator>

#include "janusxsdm.h"

#include <fcntl.h> // library for fcntl function

#define SRV_PORT 9910 


using namespace std::chrono_literals;

namespace janusxsdm
{
    //std::string janus::mIP, janus::JPATH, janus::SPATH;
    //int janus::RX_PORT, janus::TX_PORT;
    uint8_t connection::SDM_FRAMEHEADER[] = {0x80, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00};

    connection::connection(std::string modemIP, std::string JANUSPATH, std::string SDMPATH, int rxPort, int txPort)
    {
        mIP = modemIP;
        JPATH = JANUSPATH;
        SPATH = SDMPATH;
        RX_PORT = rxPort;
        TX_PORT = txPort;
    }
    int connection::sdmconf()
    {
        //Could also add setting modem in "PHY" state here (nc $IP PORT +++ATP)
        std::string sdmcommand = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'stop;config 30 0 3 0')";
        FILE* terminal = popen(sdmcommand.c_str(), "r");
        pclose(terminal);
        std::cout << "Modem with IP: " << mIP << " configured." << std::endl;
        return 1;
    }
    int connection::setPreamble()
    {
        std::string sdmcommand = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'stop;ref preamble.raw')";
        FILE* terminal = popen(sdmcommand.c_str(), "r");
        pclose(terminal);
        std::cout << "Preamble set for modem with IP: " << mIP << std::endl;
        return 1;
    }
    void connection::sendSimple(std::string message)
    {
        std::cout << "Encoding and transmitting the message: " << message << " with janus..." << std::endl;
        int samples;
        if(message == "") //NB! Samples are hardcoded for sampling rate of 96kHz
        {
            samples = 55800;
        }
        else
        {
            samples = (message.length() * 4800 + 60600); 
        }
        int filedes[2];
        if(pipe(filedes) == -1) //Creating a pipe
        {
            perror("pipe");
            exit(1);
        }

        pid_t sdm_pid = fork(); //Creating a subprocess
        if(sdm_pid == -1) //Error handler
        {
            perror("fork");
            exit(1);
        }
        else if(sdm_pid == 0) //sdmsh child proc
        {
            while((dup2(filedes[1], STDOUT_FILENO) == -1) && (errno == EINTR)) {}
            close(filedes[1]);
            close(filedes[0]);

            char arg1[] = "sh";
            char arg2[] = "-c";
            std::string scmd = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'tx " + std::to_string(samples) + " tcp:listen:127.0.0.1:" + std::to_string(TX_PORT) + "' )";
            char* sdm_arg[] = {arg1, arg2, (char*)scmd.c_str(), NULL};
            //FILE* sterm = popen(scmd.c_str(), "r");
            //pclose(sterm);
            execvp(sdm_arg[0], sdm_arg);
            perror("execvp");
            _exit(1);
        } 
        else //Parent proc
        {
            std::this_thread::sleep_for(500ms); //Delay needed for sdmsh to establish tcp listener
            pid_t jns_pid = fork();
            if(jns_pid == -1) //Error handler
            {
                perror("fork");
                exit(1);
            }
            else if(jns_pid == 0) //janus child proc
            {
                char arg1[] = "sh";
                char arg2[] = "-c";
                std::string jcmd = "(cd " + JPATH + " && ./janus-tx --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args connect:127.0.0.1:"+std::to_string(TX_PORT)+" --stream-fs 96000 --stream-format S16 --verbose 9 --packet-cargo \""+message+"\" )";
                char* jns_arg[] = {arg1, arg2, (char*)jcmd.c_str(), NULL};
                execvp(jns_arg[0], jns_arg);
                perror("execvp");
                _exit(1);
            }
            else //Parent proc
            {
                char buffer[1024];
                while(true)
                {
                    std::cout << waitpid(jns_pid, 0, WNOHANG);
                    if(waitpid(jns_pid, 0, WNOHANG) == jns_pid)
                    {
                        std::cout << "Janus done, quitting\n";
                        break;
                    }
                    ssize_t count = read(filedes[0], buffer, sizeof(buffer));
                    if(count == -1)
                    {
                        if(errno == EINTR)
                        {
                            continue;
                        }
                        else
                        {
                            perror("read");
                            exit(1);
                        }
                    }
                    else if(count == 0)
                    {
                        std::cout << "EOF reached\n";
                        break;
                    }
                    else
                    {
                        
                        std::string dstr = buffer;
                        int j = dstr.find("TX_STOP after");
                        std::cout << "SDMSH(" << std::to_string(j) << "): " << dstr << std::endl;
                        if(j != std::string::npos)
                        {
                            std::cout << "exiting\n";
                            //while(read(filedes[0], buffer, sizeof(buffer)) != 0) {}
                            kill(jns_pid, SIGKILL);
                            //if(kill(jns_pid, 0) == 0)
                            // {
                            //     std::cout << "Unable to kill janus!" << std::endl;
                            //     kill(jns_pid, SIGKILL);
                            //     int i;
                            //     waitpid(jns_pid, &i, 0);
                            // }
                            kill(sdm_pid, SIGKILL);
                            //if(kill(sdm_pid, 0) == 0)
                            // {
                            //     std::cout << "Unable to kill sdm!" << std::endl;
                            //     kill(sdm_pid, SIGKILL);
                            //     int i;
                            //     waitpid(sdm_pid, &i, 0);
                            // }
                            close(filedes[1]);
                            close(filedes[0]);
                            wait(0);
                            //std::this_thread::sleep_for(2s);
                            break;
                        }
                    }
                }
                                
                
            }
            // std::string jcmd = "(cd " + JPATH + " && ./janus-tx --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args connect:127.0.0.1:"+std::to_string(TX_PORT)+" --stream-fs 96000 --verbose 9 --packet-cargo \""+message+"\")";
            // std::cout << jcmd << std::endl;
            // //FILE* jterm = popen(jcmd.c_str(), "r");
            //pclose(jterm);

        }
    }
    int connection::decode(int16_t buf[], std::string &message)
    {
        std::cerr << LIBNAME << ": Decode does nothing as it is unfinished" << std::endl;
        /*
        std::cout << "Decoding janus message" << std::endl;
        std::string command = "(cd " + JANUSPATH + " && ./janus-rx --config-file ../etc/" + JANUS_RX_CONFIG + " --verbose 1 --stream-driver-args listen:127.0.0.1:" + std::to_string(JANUS_RX_PORT) + " 2>&1)";
        std::FILE *JanusRX = popen(command.c_str(), "r");
        if(!JanusRX)
        {
            std::cout << "Could not open ./janus-rx" << std::endl;
            return 0;
        }
        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            std::cout << "Socket creation error" << std::endl;
            return 0;
        }
        
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(JANUS_RX_PORT);

        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
            std::cout << "Invalid address/ Address not supported" << std::endl;
            return 0;
        }

        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        {
            std::cout << "Connection failed" << std::endl;
            return 0;
        }
        send(sock, buf, sizeof(buf), 0);

        std::array<char, 128> rcvbuf;

        while(fgets(rcvbuf.data(), 128, JanusRX) != NULL)
        {
            std::cout << "Reading..." << std::endl;
            message += rcvbuf.data();
        }
        auto returnCode = pclose(JanusRX);
        std::cout << "The janus message was:" << std::endl << message << std::endl;
        return 1;
        */
        return 1;
    }
    int connection::listenSimple(std::string &message)
    {
        int filedes[2];
        if(pipe(filedes) == -1) //Creating pipe
        {
            perror("pipe");
            exit(1);
        }

        pid_t jns_pid = fork(); //Creating suprocess for janus-rx
        if(jns_pid == -1) //Error
        {
            perror("fork");
            exit(1);
        }
        else if(jns_pid == 0) //janus child process
        {
            std::cout << "Spawned janus child\n";
            while((dup2(filedes[1], STDOUT_FILENO) == -1) && (errno == EINTR)) {}
            close(filedes[1]);
            close(filedes[0]);

            char arg1[] = "sh";
            char arg2[] = "-c";
            //std::string jcmd = "(cd " + JPATH + " && ./janus-rx --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args listen:127.0.0.1:" + std::to_string(RX_PORT)+" --stream-fs 96000 --verbose 1 2>&1)";
            //Dummy for testing:
            std::string jcmd = "(cd " + JPATH + " && ./janus-rx  --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver raw --stream-driver-args ../data/janusMessage.raw --stream-fs 250000 --stream-format S16 --verbose 1 2>&1)";
            //
            //std::cout << jcmd << std::endl;
            char* jns_arg[] = {arg1, arg2, (char*)jcmd.c_str(), NULL};
            execvp(jns_arg[0], jns_arg);
            perror("execvp");
            _exit(1);
        }
        else //Parent process
        {
            std::this_thread::sleep_for(800ms); //Delay needed for janus to establish tcp listener
            pid_t sdm_pid = fork();
            if(sdm_pid == -1) //Error
            {
                perror("fork");
                exit(1);
            }
            else if(sdm_pid == 0) //sdmsh child proc
            {
                std::cout << "Spawned sdm child\n";
                char arg1[] = "sh";
                char arg2[] = "-c";
                std::string scmd = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'rx 0 tcp:connect:127.0.0.1:" + std::to_string(RX_PORT) + "')";
                char* sdm_arg[] = {arg1, arg2, (char*)scmd.c_str(), NULL};
                //execvp(sdm_arg[0], sdm_arg);
                //perror("execvp");
                //_exit(1);
            }
            else
            {
                //std::this_thread::sleep_for(500ms);
                char buffer[1];
                ssize_t count;
                std::string janusFrame;
                while(true)
                {                    
                    count = read(filedes[0], buffer, sizeof(buffer));
                    //std::cout << buffer;
                    if(count == -1)
                    {
                        if(errno == EINTR)
                        {
                            continue;
                        }
                        else
                        {
                            perror("read");
                            exit(1);
                        }
                    }
                    else if(count == 0)
                    {
                        std::cout << "EOF reached\n";
                        break;
                    }
                    else
                    {
                        janusFrame += buffer;
                        std::string idStr = "Packet         : Cargo (ASCII)                                : \"";
                        int j = janusFrame.find(idStr);
                        //std::cout << buffer;
                        //std::cout << "Reading";
                        if(waitpid(jns_pid, 0, WNOHANG) != 0)
                        {
                            std::cout << "Janus done, exiting\n";
                            break;
                        }
                        if(j != std::string::npos)
                        {
                            count = read(filedes[0], buffer, sizeof(buffer));
                            janusFrame += buffer;
                            std::cout << "\nFound cargo, exiting\n";

                            //std::cout << janusFrame << std::endl;
                            break;
                        }
                    }
                    //std::cout << "Buffering..\n";
                    
                }
                
                //std::cout << janusFrame << std::endl;
                //std::cout << "Done rcv\n";
                std::string idStr = "Packet         : Cargo (ASCII)                                : \"";
                idStr = "Packet         :   Payload                                    :";
                std::string endStr = "\"";
                endStr = "\n";

                size_t spos = janusFrame.find(idStr) + idStr.length();
                size_t epos;
                //std::cout << "Cargo found in " << spos << std::endl;
                if(spos != std::string::npos)
                {
                    epos = janusFrame.find(endStr, spos);
                    std::string cargo = janusFrame.substr(spos, epos-spos);
                    message = cargo;
                }
                else
                {
                    message = "n/a";
                }
                
                //std::cout << "Cargo is: " << cargo << std::endl;


                //Writing cargo to message argument
                //Terminating children
                kill(jns_pid, SIGTSTP);
                kill(sdm_pid, SIGTSTP);
                close(filedes[1]);
                close(filedes[0]);
                
                return 1;
            }
            return 0;
        }
    }
    int connection::listen(std::string &message, std::chrono::duration<double> timeout)
    {
        int fd[2];
        // 0 - Read
        // 1 - Write

        if(pipe(fd) == -1) //Error creating pipe
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        if (fcntl(fd[0], F_SETFL, O_NONBLOCK) < 0) //Making pipeRead non-blocking
        {
            exit(2);
        }

        pid_t jns_pid = fork(); //Creating suprocess for janus-rx
        if(jns_pid == -1) //Error
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if(jns_pid == 0) //janus child process
        {
            //std::cout << "Spawned janus child\n";
            while((dup2(fd[1], STDERR_FILENO) == -1) && (errno == EINTR)) {} //Redirecting stderr to pipe (erroroutput now goes to pipe)
            close(fd[1]);
            close(fd[0]);
            
            char arg1[] = "sh";
            char arg2[] = "-c";
            std::string jcmd = "(cd " + JPATH + " && ./janus-rx --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args listen:127.0.0.1:" + std::to_string(RX_PORT)+" --stream-fs 96000 --verbose 1 --rx-once 1)";
            
            char* jns_arg[] = {arg1, arg2, (char*)jcmd.c_str(), NULL};
            execvp(jns_arg[0], jns_arg);
            
            //This will have janus keep original pid but pathing gets broken
            // char *args[16];
            // std::string arg1 = JPATH + "janus-rx";
            // std::string arg3 = JPATH + "../etc/parameter_sets.csv";
            // std::string arg7 = "listen:127.0.0.1:" + std::to_string(RX_PORT);

            // args[0] = (char*)arg1.c_str();
            // args[1] = "--pset-file";
            // args[2] = (char*)arg3.c_str();
            // args[3] = "--pset-id";
            // args[4] = "2";
            // args[5] = "--stream-driver";
            // args[6] = "tcp";
            // args[7] = "--stream-driver-args";
            // args[8] = (char*)arg7.c_str();
            // args[9] = "--stream-fs";
            // args[10] = "96000";
            // args[11] = "--verbose";
            // args[12] = "1";
            // args[13] = "--rx-once";
            // args[14] = "1";
            // args[15] = NULL;
            // execvp(args[0], args);
            perror("execvp");
            _exit(EXIT_FAILURE);
        }
        else //Parent process
        {
            close(fd[1]);
            std::this_thread::sleep_for(500ms); //Delay needed for janus to establish tcp listener
            pid_t sdm_pid = fork();
            if(sdm_pid == -1) //Error
            {
                perror("fork");
                exit(1);
            }
            else if(sdm_pid == 0) //sdmsh child proc
            {
                // std::cout << "Spawned sdm child\n";
                char arg1[] = "sh";
                char arg2[] = "-c";
                std::string scmd = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'rx 0 tcp:connect:127.0.0.1:" + std::to_string(RX_PORT) + "' 2>&1 > rxlog.txt)";
                //Dummy for testing:
                //std::string scmd = "(cd " + JPATH + " && ./janus-tx --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args connect:127.0.0.1:" + std::to_string(RX_PORT) + " --stream-fs 96000 --verbose 1 --packet-cargo 'fakngay')";
                //
                //std::this_thread::sleep_for(2s);
                char* sdm_arg[] = {arg1, arg2, (char*)scmd.c_str(), NULL};
                execvp(sdm_arg[0], sdm_arg);
                perror("execvp");
                exit(0);
            }
            else
            {
                char ch;
                std::string janusframe;
                std::chrono::steady_clock::time_point start, now;
                start = std::chrono::steady_clock::now();

                while(true)
                {
                    int rdstat = read(fd[0], &ch, sizeof(char));
                    switch (rdstat)
                    {
                    case -1:
                        if(errno == EAGAIN)
                        {
                            //printf("Pipe empty\n");
                            break;
                        }
                        else
                        {
                            perror("read");
                            exit(4);
                        }
                    default: //Appending read char to janusframe
                        janusframe += ch; 
                        break;
                    }
                    
                    if(janusframe.find("Packet         : Cargo (ASCII)                                :") != std::string::npos)
                    {
                        //std::cout << "Found message!";
                        break;
                    }
                    now = std::chrono::steady_clock::now();
                    if(std::chrono::duration<double>(now - start).count() >= timeout.count())
                    {
                        std::cout << "listener: Timeout reached, terminating!\n";
                        //std::cout << "Killing " << jns_pid << " and " << sdm_pid << "\n";
                        close(fd[0]);
                        kill(jns_pid+1, SIGINT);
                        kill(jns_pid, SIGINT);
                        kill(sdm_pid+1, SIGINT);
                        kill(sdm_pid, SIGINT);
                        return 0;
                    }
                }
                //std::cout << janusframe << std::endl;
                close(fd[0]);
                kill(jns_pid, SIGINT);
                kill(jns_pid+1, SIGINT);
                kill(sdm_pid, SIGINT);
                //std::string idStr = "Packet         : Cargo (ASCII)                                : \"";
                std::string idStr = "Packet         :   Payload                                    : ";
                std::string endStr = "\n";

                size_t spos = janusframe.find(idStr) + idStr.length();
                //std::cout << "Cargo found in " << spos << std::endl;

                size_t epos = janusframe.find(endStr, spos);

                std::string cargo = janusframe.substr(spos, epos-spos);
                //std::cout << "Cargo is: " << cargo << std::endl;

                message = cargo; //Writing cargo to message argument
                return 1;
                /*
                pid_t rd_pid = fork();
                if(rd_pid == -1) //Error
                {
                    perror("fork");
                    exit(1);
                }
                else if(rd_pid == 0)
                {
                    char buffer[2048];
                    ssize_t count;
                    std::string janusFrame;
                    while(true)
                    {
                        if(janusFrame.find("Packet         :   Payload                                    :") != std::string::npos) //To catch EOF before read blocks
                        {
                            break;
                        }
                        count = read(filedes[0], buffer, sizeof(buffer));
                        //std::cout << buffer;
                        if(count == -1)
                        {
                            if(errno == EINTR)
                            {
                                continue;
                            }
                            else
                            {
                                perror("read");
                                exit(1);
                            }
                        }
                        else if(count == 0)
                        {
                            std::cout << "EOF reached\n";
                            break;
                        }
                        else
                        {
                            janusFrame += buffer;
                            std::string idStr = "Packet         : Cargo (ASCII)                                : \"";
                            int j = janusFrame.find(idStr);
                            //std::cout << buffer;
                            if(j != std::string::npos)
                            {
                                count = read(filedes[0], buffer, sizeof(buffer));
                                janusFrame += buffer;
                                std::cout << "\nFound cargo, exiting\n";

                                //std::cout << janusFrame << std::endl;
                                break;
                            }
                        }
                        //std::cout << "Buffering..\n";
                    }
                    //std::cout << janusFrame << std::endl;
                    //std::cout << "Done rcv\n";
                    std::string idStr = "Packet         : Cargo (ASCII)                                : \"";
                    idStr = "Packet         :   Payload                                    :";
                    std::string endStr = "\n";

                    size_t spos = janusFrame.find(idStr) + idStr.length();
                    //std::cout << "Cargo found in " << spos << std::endl;

                    size_t epos = janusFrame.find(endStr, spos);

                    std::string cargo = janusFrame.substr(spos, epos-spos);
                    //std::cout << "Cargo is: " << cargo << std::endl;

                    message = cargo; //Writing cargo to message argument
                    //Terminating children
                    kill(jns_pid, SIGKILL);
                    kill(sdm_pid, SIGKILL);
                    close(filedes[1]);
                    close(filedes[0]);
                    return 1;
                }
                else
                {
                    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
                    std::chrono::steady_clock::time_point now;
                    pid_t rdStat;
                    while(true)
                    {
                        now = std::chrono::steady_clock::now();
                        if(std::chrono::duration<double>(now - start).count() >= timeout.count())
                        {
                            std::cout << "Timeout reached, terminating!\n";
                            kill(sdm_pid, SIGKILL);
                            kill(jns_pid, SIGKILL);
                            
                            kill(rd_pid, SIGKILL);
                            close(filedes[1]);
                            close(filedes[0]);
                            wait(0);
                            return 0;
                        }
                        rdStat = waitpid(rd_pid, 0, WNOHANG);
                        if(rdStat == -1)
                        {
                            perror("waitpid");
                            exit(1);
                        }
                        else if(rdStat == rd_pid)
                        {
                            //std::cout << "Reader done\n";
                            exit(0);
                        }
                        //std::cout << "Timer_waitpid: " << waitpid(rd_pid, 0, WNOHANG) << "\n";
                        //else if(waitpid(jns_pid, 0, WNOHANG) != 0) {}
                        
                    }
                }
                */
            }
            return 0;
        }
    }
    int connection::printheader()
    {
        for(int i = 0; i <= 7; i++)
        {
            std::cout << std::hex << unsigned(SDM_FRAMEHEADER[i]);
            std::cout << " ";
        }
        std::cout << std::endl;
        return 1;
    }
    int connection::sdmStop()
    {
        return 0;
    }
}