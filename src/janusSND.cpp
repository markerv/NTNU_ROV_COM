#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
using namespace std;

//some paths to commonly used locations
string JANUSPATH = "/home/markerv/Documents/Bproject/janus-c-3.0.5/";
string SCRIPTPATH = "/home/markerv/Ros/NTNU_ROV_COM/lib/tools/";


int janus_tx(string data) //function for sending data
{
    string command = SCRIPTPATH + "janus-send.sh " + data;
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