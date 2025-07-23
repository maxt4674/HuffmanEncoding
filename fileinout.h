#ifndef FILEINOUT
#define FILEINOUT

#include <string>
#include <fstream>
#include <vector>

bool isFileValid(std::string filename){
    std::ifstream file(filename);
    if(file.good()){
        return true;
    } else {
        return false;
    }
}

std::vector<std::vector<char>> readFileChar(std::string filename){
    std::vector<std::vector<char>> outputArray;

    std::ifstream fileReader(filename);

    if(fileReader.is_open()){
        std::string line;
        while(std::getline(fileReader, line)){
            std::vector<char> lineVec;
            for(int i = 0; i < line.size(); i++){
                lineVec.push_back(line.at(i));
            }
            outputArray.push_back(lineVec);
        }
    }

    return outputArray;
}

#endif