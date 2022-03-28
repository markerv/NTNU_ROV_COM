#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
using namespace std;

string JANUSPATH = "/home/markerv/Documents/Bproject/janus-c-3.0.5/";

string SCRIPTPATH = "/home/markerv/Ros/NTNU_ROV_COM/lib/tools/";



int janus(){
    if(system(NULL) != 0)
    {
        string command = SCRIPTPATH + "janus-listen.sh";
        system(command.c_str());
        cout << "Janus: Data recieved and decoded" << "\n";
        
        ifstream input;
        size_t pos;
        string line;
        string messageFile = JANUSPATH + "myLog.txt";
        input.open(messageFile);
        //cout << messageFile << "\n";
        string payloadIdentifier = "Packet         :   Payload                                    : ";
        if(input.is_open())
        {
            cout << "File is opened\n";
            while (getline(input, line))
            {
                cout << "Readline: " << line << "\n";
                /*
                pos = line.find("Packet");
                if(pos != string::npos);
                {
                    //cout << line << "\n";
                    //line.erase(0, payloadIdentifier.length());
                    //cout << line << "\n";
                    break;
                }
                */
                
            }
            
        }

        return 1;
    }
    else return 0;
}

int main(){
    /*
    if(janus() <= 0){
        cout << "System not available, janus not ready\n";
        return -1;
    }
    */
    //cout << system("/home/markerv/Documents/Bproject/scripts/janus_listen.sh") << "\n";
    janus();
    return 0;
}