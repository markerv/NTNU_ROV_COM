#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<chrono>
#include<unistd.h>
#include<signal.h>

#include "lib/janusxsdm/janusxsdm.cpp"

//Global
std::string JANUSPATH = "lib/janus-c-3.0.5/bin/";
std::string SDMPATH = "lib/sdmsh/";

int JANUS_RX_PORT = 9960;
int JANUS_TX_PORT = 9961;

using namespace std::chrono_literals;

int main()
{
    
    std::cout << "Tester\n";
    janusxsdm::connection modem2("192.168.0.199", JANUSPATH, SDMPATH, 9998, 9955); //Constructing a connection object;
    std::string returnMessage;
    //modem2.sdmconf();
    //std::this_thread::sleep_for(1000ms);
    while(true)
    {
        if(modem2.listen(returnMessage, 6s))
        {
            std::cout << "Message was: " << returnMessage << std::endl;
        }
    }
    
    //std::cout << "I swear i did not hit her, i swear.. i did noot..\n";
    //std::cout << "ohh, hi Mark!\n";
    
    /*
    std::string rcv;
    testCon.listenSimple(rcv);
    std::cout << rcv << std::endl;
    std::cout << "Testing sdmconf...\n";
    if(testCon.sdmconf())
    {
        std::cout << "Done\n";msgstr
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Testing sendSimple...\n";
    if(testCon.sendSimple("nudes"))
    {
        std::cout << "Done\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Testing listenSimple...\n";
    std::string rcvMessage;
    if(testCon.listenSimple(rcvMessage))
    {
        std::cout << "Done, the message was '" << rcvMessage << "'\n";
    }
    
    std::cout << "Tests done, exiting\n";
    
    testCon.printheader();
    }
    */
    


}