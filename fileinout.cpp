#include "fileinout.h"

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

    fileReader.close();

    return outputArray;
}

bool writeEncodedFile(std::map<char, std::vector<int>> binaryDist, std::string filename){
    std::ofstream outputFile("encoded_" + filename);
    std::vector<std::vector<char>> charFile = readFileChar(filename);

    if(outputFile.is_open()){
        for(int i = 0; i < charFile.size(); i++){
            for(int j = 0; j < charFile.at(i).size(); j++){
                std::vector<int> indvCode = binaryDist[charFile.at(i).at(j)];

                for(int x = 0; x < indvCode.size(); x++){
                    outputFile << indvCode.at(x);
                }
            }
            outputFile << std::endl;
        }

        outputFile.close();
    } else {
        return false;
    }
}