#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
using namespace std;

//some paths to commonly used locations
string JANUSPATH = "../lib/janus-c-3.0.5/bin/";
string JANUS_TX_CONFIG = "txcfg_rawfile.ini";
string SCRIPTPATH = "../lib/tools/";

int janus_tx(string data) //function for sending data
{
    string command = "(cd " + JANUSPATH + " && ./janus-tx --config-file ../etc/" + JANUS_TX_CONFIG + " --packet-cargo '" + data + "')";
    system(command.c_str());
    return 1;
}



int main(){
    string input;
    while (true) //simple recurring loop for user input, this input is then passed to janus_tx
    {
        cout << endl << endl << "Enter data or command\nexit - stop transmissionscript\n";
        cin >> input;
        cout << endl << "Your command was: " << input << endl;
        if(input == "exit") //Terminate loop with exit command
        {
            break;
        }
        janus_tx(input);
        cout << "Data sent!";
    }
    
    return 0;
}