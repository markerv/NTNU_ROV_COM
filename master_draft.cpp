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
using namespace std::chrono_literals;

int array_length = 1;
int time_slot_duration;             //The duration of each time slot calculated from response-times, in ms
vector<string> nodes_addresses;     //Includes only the MAC-addresses fetched from content-array
vector<vector<string>> content;     //Includes the whole csv-file, 
bool check_complete=false;
bool node_check;
string fname = "info_files/nodes_lst.csv";
string master_mac = "48:0f:cf:01:f7:fc";

string data1;       //declarations for sensor data received from nodes
string data2;
string data3;
string data4;

//Globals
std::string JANUSPATH = "lib/janus-c-3.0.5/bin/";
std::string SDMPATH = "lib/sdmsh/";

int JANUS_RX_PORT = 9970;
int JANUS_TX_PORT = 9960;

janusxsdm::connection modem("192.168.0.189",JANUSPATH,SDMPATH, JANUS_RX_PORT,JANUS_TX_PORT);

int janus_tx(string data){
    std::this_thread::sleep_for(1000ms);
    modem.sendSimple(data);
    return 1;
}

string janus_rx(int timeOut_interval){
    std::chrono::duration<double> t;
    t = std::chrono::duration<double> {timeOut_interval};
    string response;
    modem.listen(response, t);
    std::cout << response << std::endl;
    return response;
}

int set_config(){       //sets the configurational parameters for the network, as well as node IDs
    for(int i  = 0; i < nodes_addresses.size();i++){
        string node_config_data = std::to_string(time_slot_duration) + "|" + std::to_string(i+1);
        string send_command = "//SUP-MC//"+nodes_addresses[i]+";" + node_config_data + ">>";
        janus_tx(send_command);
    }
    return 0;
}

void edit_nodes_lst(bool remove, string node){
    //code for adding/removing nodes from the csv
    if(!remove){
        //code for adding
        size_t spos = 0;
        size_t epos = node.find(";");
        string mac = node.substr(spos, epos-spos);
        spos = epos+1;
        epos = node.find(">>");
        string info_line = node.substr(spos,epos-spos);
        
        string tmp;
        stringstream ss(info_line);
        vector<string> words;
        while(getline(ss,tmp,'|')){
            words.push_back(tmp);
        }

        string add_line = mac + "," + words[0] + ","+ words[1] + ","+words[2]+","+words[3];

        std::ofstream my_file;
        my_file.open(fname, std::ios::out | std::ios::app);
        my_file << add_line << endl;
    }
    else if(remove){
        //code for removing
        string line;
        ifstream fin;
        string eraseLine = node;
        
        fin.open(fname);
        // contents of path must be copied to a temp file then
        // renamed back to the path file
        ofstream temp;
        temp.open("info_files/temp.csv");

        while (getline(fin, line)) {
            string token = line.substr(0, line.find(","));      //isolate first word of the current line
            // write all lines to temp other than the line marked for erasing (the line containing the token)
            if (token != eraseLine)
                temp << line << endl;
        }

        temp.close();
        fin.close();
        // required conversion for remove and rename functions
        const char * p = "info_files/nodes_lst.csv";
        std::remove(p);
        rename("info_files/temp.csv", p);
        cout << "Removing " << node << " from records.." << "\n";
    }
}

string response_check(string response,string mac){
    size_t spos = response.find("-");
    size_t epos;
    string command = response.substr(spos+1, 2);

    if(command == "NR"){
        spos = 10;          //Standard for every command received
        epos = response.find(">>");
        string node_mac = response.substr(spos,epos-spos);
        return node_mac;
    }
    else if (command == "NC"){
        spos = 10;
        epos = response.find(">>");
        string data_string = response.substr(spos, epos-spos);
        node_check = true;
        if(data_string != "OK"){
            edit_nodes_lst(false,data_string);
        }
        return "";
    }
    else if (command == "NT"){
        spos = 10;
        epos = response.find(";");
        string node_mac = response.substr(spos, epos-spos);
        if(node_mac==mac){
            spos = epos+1;
            epos = response.find(">>");
            string data_string = response.substr(spos, epos-spos);
            cout << data_string << "\n";

            string tmp;
            stringstream ss(data_string);
            vector<string> words;

            while(getline(ss,tmp,'|')){
                words.push_back(tmp);
            }
            data1 = words[0];
            data2 = words[1];
            data3 = words[2];
            data4 = words[3];
            cout << data1 <<endl;
            return "";
        }
        else{
            cout << "MAC-address not matching!\n";
            return "";
        }
    }
    else{
        cout << "Unknown command!" << "\n";
        return "";
    }
}

void network_transmission(){        //Network transmission commences here..
    cout << "Network transmission starting with time slot " << time_slot_duration << "ms.\n";
    //while(true){
        for(int i = 0; i<nodes_addresses.size();i++){
            int id = i+1;
            string master_ready_cmd = "//SUP-MT//"+nodes_addresses[i]+";"+ std::to_string(id) +">>";
            janus_tx(master_ready_cmd);
            string response = janus_rx(time_slot_duration/2);
            response_check(response,nodes_addresses[i]);
        }
    //}
}

void read_nodes_lst()
{
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
    cout << "Reading list of nodes.." << "\n";
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
        cout << "Node list saved" << "\n";
	}
	else
		cout<<"Could not open the file\n";
    array_length = content.size();
    for(int i=0;i<content.size();i++){
        nodes_addresses.push_back(content[i][0]);
    }
}

void nodes_check(){
    auto prev_time_elapsed = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now()-chrono::steady_clock::now());
    cout << "Check of nodes commencing.." << "\n";
    string send_command;
    for(int i = 0;i<nodes_addresses.size();i++){
        node_check = false;
        string response;      
        cout << "Checking node " << i+1 << ".\n";
        send_command = "//SUP-MD//"+nodes_addresses[i]+";" + master_mac + ">>";
        auto start = chrono::steady_clock::now();
        janus_tx(send_command);
        response = janus_rx(7);
        auto time_elapsed = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now()-start);
        if(time_elapsed>prev_time_elapsed){
            prev_time_elapsed = time_elapsed;
        }
        response_check(response, nodes_addresses[i]);
        if(!node_check){
            edit_nodes_lst(true,nodes_addresses[i]);
        }
    }
    cout << "All addresses tested." << "\n";
    time_slot_duration = prev_time_elapsed.count()*1.2;  //the calculated time-slot to be assigned to all nodes based on the longest response time +20%
    cout << "Time slot duration: " << std::to_string(time_slot_duration) << "ms" << endl;
    check_complete=true;
}

void node_interrogation(string mac){
    // string send_command = "//SUP-RA//"+mac+";"+master_mac+">>";
    // janus_tx(send_command);
    string response = response_check(janus_rx(7),mac);
    nodes_addresses.push_back(mac);
}

void master_ready(){
    string send_command;
    send_command = "//SUP-MR//"+master_mac+">>";
    janus_tx(send_command);
    string response = janus_rx(time_slot_duration);//fix listening and interruption after a given time period
    string new_node_mac = response_check(response,"");
    if(new_node_mac != ""){
        node_interrogation(new_node_mac);
    }
}

int main(){
    modem.sdmconf();
    std::this_thread::sleep_for(1000ms);
    modem.setPreamble();
    std::this_thread::sleep_for(500ms);
    cout << "Master commencing.." << "\n";
    read_nodes_lst();
    nodes_check();
    if(check_complete){         //master ready signal, if no response, proceed...
        master_ready();
        set_config();
        network_transmission();
    }
    return 0;
}