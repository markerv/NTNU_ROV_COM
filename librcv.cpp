// Simple code demonstrating how to recieve data using janusxsdm

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
    //std::cout << "Tester\n";
    janusxsdm::connection modem("192.168.0.199", JANUSPATH, SDMPATH, 9998, 9955); //Constructing a connection object;
    std::string returnMessage;

    while(true)
    {
        if(modem.listen(returnMessage, 5s))
        {
            std::cout << "Message was: " << returnMessage << std::endl;
        }
    }
    //std::cout << "rcv done" << std::endl;
}