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
        for(const auto& pair : binaryDist){
            outputFile << pair.first;
            for(int i = 0; i < pair.second.size(); i++){
                outputFile << pair.second.at(i);
            }
            outputFile << std::endl;
        }
        outputFile << std::endl;
        outputFile << std::endl;

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

    return true;
}

std::map<std::string, char> retrieveBinaryDist(std::string filename){
    std::map<std::string, char> returnBinaryDist;

    std::ifstream fileReader(filename);

    if(fileReader.is_open()){
        std::string line;
        while(std::getline(fileReader, line)){
            if(line.size() > 1){
                char charIn = line.at(0);
                std::string binaryIn = line.substr(1);

                returnBinaryDist.insert({binaryIn, charIn});
            } else {
                break;
            }
        }
    }
    fileReader.close();

    return returnBinaryDist;
}

bool writeDecodedFile(std::map<std::string, char> binaryDist, std::string filename){
    std::ifstream inputFile(filename);
    std::vector<std::string> encodedVec;

    if(inputFile.is_open()){
        int i = 0;
        std::string line;
        while(std::getline(inputFile, line)){
            if(i >= binaryDist.size() + 2){
                encodedVec.push_back(line);
            }
            i++;
        }
        inputFile.close();
    } else {
        return false;
    }

    std::string editedFilename = splitString(filename, '_').at(1);
    std::ofstream outputFile("decoded_" + editedFilename);
    
    if(outputFile.is_open()){
        for (const std::string& encodedLine : encodedVec) {
            std::string buffer;
            for (char c : encodedLine) {
                buffer += c;
                if (binaryDist.count(buffer)) {
                    outputFile << binaryDist[buffer];
                    buffer.clear();
                }
            }
            outputFile << std::endl;
        }
    } else {
        return false;
    }

    return true;
}

std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}