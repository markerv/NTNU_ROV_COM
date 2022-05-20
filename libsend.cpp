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
    janusxsdm::connection modem("192.168.0.189", JANUSPATH, SDMPATH, 9007, 9045); //Constructing a connection object;
    modem.sendSimple("KUK-asscock-Nudes");
    // modem.sendSimple("123456789123456789FinkenHaHA-fkjhdafkasndfaiunvsakjvndbvdrfnasouvnakjhfzlkdjhsakraiusnvkjdn");
    // modem.sendSimple("123456");
    // modem.sendSimple("");
    // modem.sendSimple("123456789123456789");
    std::cout << "Transmission done" << std::endl;
}