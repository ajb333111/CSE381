// Copyright 2018 Alec Bird

#include <cstdlib>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "birdaj_hw3.h"


using namespace std;
using IntIntMap = std::unordered_map<int, int>;
using IntStrMap = std::unordered_map<int, std::string>;

    // Create an object to process a data file
    ProcessData::ProcessData(){}
    
    ProcessData::~ProcessData(){}
    
    /**
     * Creates two maps: one stores two number values,
     * the other stores a number and a string
     * @param input the file to read 
     */
    void ProcessData::createMaps(std::istream& input) {
    std::string line, uid, stime, tty, time, cmd, extra;
    int pid, ppid, c;
    
    // Read first line and ignore it (titles of columns)
    std::getline(input, line);
    
    // Read next lines into string
    while (std::getline(input, line)) {
        std::istringstream stream(line);
        stream >> uid >> pid >> ppid >> c >> stime >> tty >> time >> cmd;
        while (stream >> extra) {
            cmd.append(" " + extra);
        }
        map1[pid] = ppid;
        map2[pid] = cmd;
    }
}
    /**
     * Writes the correct order of input based on the pid
     * @param pid the process id
     */
    void ProcessData::createTree(const int pid) {
        int ppid = map1.at(pid);
        vec.push_back(pid);
        if (pid > 1) {
            createTree(ppid);
        }
        else{
            std::cout << "Process tree for PID: " << vec[0] << endl;;
            std::cout << "PID\tPPID\tCMD" << endl;
            for (int i = vec.size()-1; i >= 0; i--) {
                int p = map1.at(vec[i]);
                std::string cmd = map2.at(vec[i]);
                std::cout << std::to_string(vec[i]) + "\t" + std::to_string(p) + "\t " + cmd << endl;
            }
            
        }
        
    }

int main(int argc, char** argv) {

    std::ifstream in(argv[1]);
    int pid = (atoi(argv[2]));
    ProcessData data;
    data.createMaps(in);
    data.createTree(pid);
    
    return 0;
}

