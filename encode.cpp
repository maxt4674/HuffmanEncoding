#include "encode.h"

bool encodeFile(std::string filename){
    std::vector<std::vector<char>> precodedArr = readFileChar(filename);
    std::cout << precodedArr.size() << std::endl;
    std::map<char, float> probabilityDistribution = retrieveCharDistribution(precodedArr);

    for(const auto& pair : probabilityDistribution){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    if(probabilityDistribution.empty()){
        return false;
    } else {
        return true;
    }
};

std::map<char, float> retrieveCharDistribution(std::vector<std::vector<char>> content){
    int totalSize = 0;

    for(int i = 0; i < content.size(); i++){
        totalSize += content.at(i).size();
    }

    std::map<char, int> charCount;

    for(int i = 0; i < content.size(); i++){
        for(int j = 0; j < content.at(i).size(); j++){
            if(charCount.count(content.at(i).at(j)) > 0){
                charCount.at(content.at(i).at(j)) += 1;
            } else {
                charCount.insert({content.at(i).at(j), 1});
            }
        }
    }

    std::map<char, float> charProbability;

    for (const auto& pair : charCount){
        char charCounted = pair.first;
        int charCount = pair.second;

        float probability = charCount / float(totalSize);

        charProbability.insert({charCounted, probability});
    }
    
    return charProbability;
};