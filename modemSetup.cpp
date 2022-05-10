#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<chrono>
#include<unistd.h>
#include<signal.h>

#include "lib/janusxsdm/janusxsdm.cpp"

//Globals
std::string JANUSPATH = "lib/janus-c-3.0.5/bin/";
std::string SDMPATH = "lib/sdmsh/";

int JANUS_RX_PORT = 9988;
int JANUS_TX_PORT = 9977;

using namespace std::chrono_literals;

int main()
{
    
    std::cout << "Tester\n";
    janusxsdm::janus modem1("192.168.0.189", JANUSPATH, SDMPATH, 9007, 9045); //Constructing a connection object;
    janusxsdm::janus modem2("192.168.0.199", JANUSPATH, SDMPATH, 9027, 9065); //Constructing a connection object;
    modem1.sdmconf();
    std::this_thread::sleep_for(500ms);
    modem2.sdmconf();
    std::this_thread::sleep_for(500ms);
    modem1.setPreamble();
    std::this_thread::sleep_for(500ms);
    modem2.setPreamble();
}