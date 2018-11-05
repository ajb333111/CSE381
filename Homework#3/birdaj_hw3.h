// Copyright 2018 Alec Bird

#ifndef BIRDAJ_HW3_H
#define BIRDAJ_HW3_H
#include <vector>
#include <unordered_map>
#include <string>

class ProcessData{
public:
    // Constructor
    ProcessData();
    
    // Deconstructor
    ~ProcessData();
    
    void createMaps(std::istream& input);
    void createTree(const int pid);
    
private:
    std::unordered_map<int, int> map1;
    std::unordered_map<int, std::string> map2;
    std::vector<int> vec;
};



#endif /* BIRDAJ_HW3_H */

