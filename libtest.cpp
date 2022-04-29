#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<chrono>

#include "lib/janusxsdm/janusxsdm.cpp"

//Globals
std::string JANUSPATH = "lib/janus-c-3.0.5/bin/";
std::string SDMPATH = "lib/sdmsh/";

int JANUS_RX_PORT = 9988;
int JANUS_TX_PORT = 9977;

int main()
{
    
    std::cout << "Tester\n";
    janusxsdm::janus testCon("192.168.0.189", JANUSPATH, SDMPATH, 9988, 9977); //Constructing a connection object;

    std::string rcv;
    testCon.listenSimple(rcv);
    std::cout << rcv << std::endl;
    /*
    std::cout << "Testing sdmconf...\n";
    if(testCon.sdmconf())
    {
        std::cout << "Done\n";
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
    */
    testCon.printheader();    

}