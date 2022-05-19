#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <stdio.h>

#include "lib/janusxsdm/janusxsdm.cpp"

using namespace std;

string fname = "info_files/node_info.csv";      //path for node info file
string JANUSPATH = "lib/janus-c-3.0.5/bin/";    //path to janus-folder
string SDMPATH = "lib/sdmsh/";                  //path to sdm-folder

bool master;
bool check_done = false;
bool config = false;

int time_slot_duration;
int node_id;

string master_mac;
string node_mac;
string node_alias;
string min_f;
string max_f;
string protocols;

janusxsdm::connection modem("192.168.0.199", JANUSPATH, SDMPATH, 9926, 9916); //Constructing a connection object;

string janus_rx(int timeOut_interval){
    string response;
    std::chrono::duration<double> t;
    t = std::chrono::duration<double> {timeOut_interval};
    if(modem.listen(response, t)){
        cout << "Cargo: " << response << endl;
    }
    return response;
}

int janus_tx(string command){
    cout << "Sending " << command << endl;
    std::this_thread::sleep_for(1000ms);
    modem.sendSimple(command);
    return 1;
}

void edit_node_info(string mac){
    string line;
    ifstream fin;
    string addLine = mac + ",master";
    
    fin.open(fname);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    ofstream temp;
    temp.open("temp.csv");
    temp << addLine << endl;
    while (getline(fin, line)) {
        if(line != ""){
            temp << line << endl;
        }
    }

    temp.close();
    fin.close();
    // required conversion for remove and rename functions
    const char * p = "info_files/node_info.csv";
    std::remove(p);
    rename("temp.csv", p);
}

void response_check(string response){
    if(response != ""){
        size_t spos = response.find("-");
        size_t epos;
        string command = response.substr(spos+1, 2);
        spos = 10;          //standard for all commands
        epos = response.find(";");
        string rec_mac = response.substr(spos, epos-spos);
        if(command == "MD"){
            spos = epos+1;
            epos = response.find(">>");
            string data_str = response.substr(spos, epos-spos);
            string tmp;
            stringstream ss(data_str);
            vector<string> words;
            while(getline(ss,tmp,'|')){
                words.push_back(tmp);
            }
            
            if(rec_mac == node_mac && node_alias == words[1] && min_f == words[2] && max_f == words[3]&&protocols==words[4]){
                string send_command = "//SUP-NC//OK;>>";
                janus_tx(send_command);
            }
            else {
                string send_command = "//SUP-NC//"+node_mac+";"+node_alias+"|" +min_f+"|"+max_f+"|"+protocols+">>";
                janus_tx(send_command);
            }
            check_done = true;
        }
        else if(command == "MR"){
            if(!master){
                string send_command = "//SUP-NC//"+node_mac+";"+node_alias+"|" +min_f+"|"+max_f+"|"+protocols+">>";
                janus_tx(send_command);
                edit_node_info(rec_mac);
            }
        }
        else if(command == "MC" && rec_mac == node_mac){
            spos = epos+1;
            epos = response.find(">>");
            string data_str = response.substr(spos, epos-spos);
            string tmp;
            stringstream ss(data_str);
            vector<string> words;
            while(getline(ss,tmp,'|')){
                words.push_back(tmp);
            }
            time_slot_duration = stoi(words[0]);
            node_id = stoi(words[1]);
            config = true;
        }
        else if(command == "MT" && rec_mac == node_mac){
            //her skal det sendes sensordata på en gitt form
        }
        else if(command == "RA" && rec_mac == node_mac){
            spos=epos+1;
            epos=response.find(">>");
            string master_mac = response.substr(spos,epos-spos);
            edit_node_info(master_mac);
            cout << master_mac << endl;
            string send_command = "//SUP-NC//"+node_mac+";"+node_alias+"|" +min_f+"|"+max_f+"|"+protocols+">>";
            janus_tx(send_command);
        }
        else if(command == "TS"){

        }
        else{
            cout << "Unknown command or wrong MAC-address!"<<endl;
        }
    }
    else{
        cout << "No response was given" << endl;
    }
}

void read_node_info(){
    vector<string> row;
	string line, word;
	fstream file (fname, ios::in);
    cout << "Reading node info.." << "\n";
	if(file.is_open()){
		while(getline(file, line)){
			stringstream str(line);
            row.push_back(line);
        }
        cout << "Node info retrieved" << "\n";
	}
	else{
		cout<<"Could not open the file\n";
    }
    for(int i = 0;i<row.size();i++){
        vector<string> words;
        string str = row[i];
        if(str != ""){
            string tmp;
            stringstream ss(str);
            while(getline(ss,tmp,',')){
                words.push_back(tmp);
                if(tmp == "master" && i==0){
                    master_mac = words[0];
                    master = true;
                }
            }
            if(i==1){
                node_mac = words[0];
                node_alias = words[1];
                min_f = words[2];
                max_f = words[3];
                protocols = words[4];
            }
        }
        else if(str=="" && i==0){
            cout << "No master detected" << endl;
            master = false;
        }  
    }
}

void network_transmission(){
    cout << "Transmission commencing" << endl;
    while(true){
        response_check(janus_rx(time_slot_duration));
    }
}

void pre_transmission(){
    read_node_info();
    while(!master){
        response_check(janus_rx(7));
        read_node_info();
    }
    while(!check_done){
        response_check(janus_rx(7));
        std::this_thread::sleep_for(1000ms);
    }
    while(!config){
        response_check(janus_rx(time_slot_duration));
    }
    if(master && check_done && config){
        network_transmission();
    }
}

int transmission(){
    cout << "Node starting.." << endl;
    pre_transmission();
    return 1;
}

int main(){
    modem.sdmconf();
    std::this_thread::sleep_for(1000ms);
    modem.setPreamble();
    std::this_thread::sleep_for(500ms);
    transmission();
    return 1;
}