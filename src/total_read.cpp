#include <iostream>
#include<chrono>
#include<thread>
#include <fstream>
#include <cstdlib>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;

std::string output_log;     //current package reading
std::string output_log_prev = "";  //previous package
bool r_flag = false;  //read-flag, in effect when package-data has been identified by ""

void packet_extraction(){       //extracting the packet cargo from the header
    std::string packet_line = "";       //line containing package data
    for(int i = 0; i < output_log.length(); i++){       //checking all symbols in the received package
        std::string tmp_string(1, output_log[i]);       //buffer for conversion of current symbol from char to string
        if(output_log[i] == '"' && r_flag == false){
            r_flag = true;
        }
        else if(output_log[i] == '"' && r_flag == true){
            r_flag = false;
        }
        if(r_flag == true){
            if(output_log[i] != '"'){
                packet_line.append(tmp_string);     //appending the symbol to the package data line if r_flag is active
            }
        }
        tmp_string = "";
    }
    r_flag = false;
    std::cout << packet_line << "\n";
}

void read_output(){         //reading the log file upon change
    ifstream indata; // indata is like cin
    std::string output = ""; // variable for input value
    output_log = "";
    indata.open("log_output.txt"); // opens the file
    if(!indata) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    indata >> output;
    while ( !indata.eof() ) { // keep reading until end-of-file
        indata >> output; // sets EOF flag if no value found
        output_log.append(output + " ");        //appending each word to the output log, and adding a space following
    }
    indata.close();
    std::ofstream file("log_output.txt");       //wipes the log file clean after reading, ready for new data
}

void wait(){
	std::this_thread::sleep_for(std::chrono::milliseconds(15000));  //wait interval
}

void output_comparison(){       //comparing current output to previous, and extracting the package data if new data has arrived
    if(output_log != output_log_prev){
        output_log_prev = output_log;
        packet_extraction();
    }
}

int main(){
    while(true){
        read_output();
        output_comparison();
        wait();
    }
    return 0;
}