#include "encode.h"

bool encodeFile(std::string filename){
    std::vector<std::vector<char>> precodedArr = readFileChar(filename);
    std::map<char, int> probabilityDistribution = retrieveCharDistribution(precodedArr);
};

std::map<char, int> retrieveCharDistribution(std::vector<std::vector<char>> content){
    int totalSize = 0;

    for(int i = 0; i < content.size(); i++){
        totalSize += content.at(i).size();
    }

    
};