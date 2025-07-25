#include "decode.h"

bool decodeFile(std::string filename){
    std::map<std::string, char> binaryDist = retrieveBinaryDist(filename);

    if(binaryDist.size() < 1){
        return false;
    }

    std::cout << "Binary Distribution of Characters Retreived!" << std::endl;
    std::cout << std::endl;

    for(const auto& pair : binaryDist){
        std::string BinaryIn = pair.first;
        char charIn = pair.second;

        std::cout << charIn << ": " << BinaryIn << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Decoding file..." << std::endl;

    if(!writeDecodedFile(binaryDist, filename)){
        return false;
    }

    std::cout << "File decoded and written to an output file!" << std::endl;

    return true;
}