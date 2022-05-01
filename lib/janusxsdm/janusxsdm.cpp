// Library that simplifies interfacing with janus and sdm for subsea acoustic communication
// This library requires that sdmsh and janus is installed

//Authors:
//Markus Naess Ervik
//
//
//

//To the person reading this: Please improve this god-awfull library and maybe rename

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

#define SRV_PORT 9910 


using namespace std::chrono_literals;

namespace janusxsdm
{
    std::string janus::mIP, janus::JPATH, janus::SPATH;
    int janus::RX_PORT, janus::TX_PORT;
    uint8_t janus::SDM_FRAMEHEADER[] = {0x80, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00};

    janus::janus(std::string modemIP, std::string JANUSPATH, std::string SDMPATH, int rxPort, int txPort)
    {
        mIP = modemIP;
        JPATH = JANUSPATH;
        SPATH = SDMPATH;
        RX_PORT = rxPort;
        TX_PORT = txPort;
    }
    int janus::sdmconf()
    {
        std::string sdmcommand = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'stop;config 30 0 3 0')";
        FILE* terminal = popen(sdmcommand.c_str(), "r");
        pclose(terminal);
        return 1;
    }
    int janus::sendSimple(std::string message)
    {
        //std::cout << "Encoding and transmitting the message: " << message << " with janus..." << std::endl;
        std::string scmd = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'tx tcp:listen:127.0.0.1:" + std::to_string(TX_PORT) + "')";
        FILE* sterm = popen(scmd.c_str(), "r");
        std::string jcmd = "(cd " +  janus::JPATH + " && ./janus-tx  --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args connect:127.0.0.1:" + std::to_string(TX_PORT) + " --stream-fs 250000 --stream-format S16 --verbose 1)";
        FILE* jterm = popen(jcmd.c_str(), "r");
        pclose(sterm);
        pclose(jterm);
        return 1;
    }
    int janus::decode(int16_t buf[], std::string &message)
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
    int janus::listenSimple(std::string &message)
    {
        
        std::string jcmd = "(cd " + JPATH + " && ./janus-rx  --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args listen:127.0.0.1:" + std::to_string(RX_PORT) + " --stream-fs 250000 --stream-format S16 --verbose 1 --rx-once 2>&1)";
        FILE* jterm = popen(jcmd.c_str(), "r");

        std::string scmd = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'rx 1024 tcp:connect:127.0.0.1:" + std::to_string(RX_PORT) + "')";
        FILE* sterm = popen(scmd.c_str(), "r");
        
        //Dummyconfig for testing:
        /*
        std::string jcmd = "(cd " + JPATH + " && ./janus-rx  --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver raw --stream-driver-args ../data/janusMessage.raw --stream-fs 250000 --stream-format S16 --verbose 1 2>&1)";
        FILE* jterm = popen(jcmd.c_str(), "r");
        */
        char msgbuf[4000*sizeof(char)];
        if(fread(msgbuf, sizeof(char), 4000, jterm) >= 3999)
        {
            std::cout << "Warning: Read file is larger than assigned buffer, data may be incomplete" << std::endl;
        }
        //std::cout << "The message was:" << std::endl << msgbuf << std::endl;
        
        std::string msgstr = msgbuf;
        std::string str1 = "Packet         : Cargo (ASCII)                                : \"";
        size_t spos = msgstr.find(str1) + str1.length();
        //std::cout << "Cargo found in " << spos << std::endl;
        std::string str2 = "\"";
        size_t epos = msgstr.find(str2, spos);
        std::string cargo = msgstr.substr(spos, epos-spos);
        //std::cout << "Cargo is: " << cargo << std::endl;

        message = cargo; //Writing cargo to message argument
        return 1;
    }
    int janus::listen(std::string &message, std::chrono::duration<double> timeout)
    {
        
        pid_t ch_pid = fork();
        if(ch_pid == 0) //Child
        {
            setpgid(getpid(), getpid());
            
            std::string jcmd = "(cd " + JPATH + " && ./janus-rx  --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver tcp --stream-driver-args listen:127.0.0.1:" + std::to_string(RX_PORT) + " --stream-fs 250000 --stream-format S16 --verbose 1 --rx-once 2>&1)";
            FILE* jterm = popen(jcmd.c_str(), "r");

            std::string scmd = "(cd " + SPATH + " && ./sdmsh " + mIP + " -e 'rx 1024 tcp:connect:127.0.0.1:" + std::to_string(RX_PORT) + "')";
            FILE* sterm = popen(scmd.c_str(), "r");
        
            //Dummyconfig for testing:
            /*
            //std::this_thread::sleep_for(60000ms);

            std::string jcmd = "(cd " + JPATH + " && ./janus-rx  --pset-file ../etc/parameter_sets.csv --pset-id 2 --stream-driver raw --stream-driver-args ../data/janusMessage.raw --stream-fs 250000 --stream-format S16 --verbose 1 2>&1)";
            FILE* jterm = popen(jcmd.c_str(), "r");
            */
            char msgbuf[4000];
            if(fread(msgbuf, sizeof(char), 4000, jterm) >= 3999)
            {
                std::cout << "Warning: Read file is larger than assigned buffer, data may be incomplete" << std::endl;
            }
            //std::cout << "The message was:" << std::endl << msgbuf << std::endl;
        
            std::string msgstr = msgbuf;
            std::string str1 = "Packet         : Cargo (ASCII)                                : \"";
            if(msgstr.find(str1) == -1)
            {
                std::cout << "Error: no cargo or unable to open datastream" << std::endl;
            }
            else
            {
                size_t spos = msgstr.find(str1) + str1.length();
                //std::cout << "Cargo found in " << spos << std::endl;
                std::string str2 = "\"";
                size_t epos = msgstr.find(str2, spos);

                std::string cargo = msgstr.substr(spos, (epos-spos));
                //std::cout << "Cargo is: " << cargo << std::endl;

                message = cargo; //Writing cargo to message argument
                return 1;
            }            
        }
        else //Parent
        {
            
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            pid_t result;
            int status;
            while(true)
            {
                result = waitpid(ch_pid, &status, WNOHANG);//Get child status
                if(result == 0)//Child alive
                {
                    //Do nothing
                }
                else if(result == -1)//Error
                {
                    std::cerr << LIBNAME << ":An error occured when checking child status" << std::endl;
                    return 0;
                }
                else//Child exited
                {
                    //std::cout << "Child has exited!\n";
                    if(message == "")
                    {
                        return 0;
                    }
                }
                if(std::chrono::steady_clock::now() - start >= timeout)
                {
                    std::cerr << "Listener timed out, killing children.." << std::endl;
                    kill(-ch_pid, SIGINT);
                    return 0;
                }
            }
        }
        return 0; //Return value for child processes
    }
    int janus::printheader()
    {
        for(int i = 0; i <= 7; i++)
        {
            std::cout << std::hex << unsigned(SDM_FRAMEHEADER[i]);
            std::cout << " ";
        }
        std::cout << std::endl;
        return 1;
    }
    int janus::sdmStop()
    {
        return 0;
    }
}