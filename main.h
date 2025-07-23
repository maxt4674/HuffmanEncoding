#include <iostream>
#include <fstream>

void printStartMenu(){
    std::cout << std::endl;
    std::cout << "Huffman Encoding Console Program!" << std::endl;
    std::cout << std::endl;
    std::cout << "Only text files can be encoded and decoded" << std::endl;
    std::cout << "Please type an option out of the ones below:" << std::endl;
    std::cout << "\t1.Encode File" << std::endl;
    std::cout << "\t2.Decode File" << std::endl;
    std::cout << "\t3.Exit" << std::endl;
    std::cout << std::endl;
}

void printMainMenu(){
    std::cout << std::endl;
    std::cout << "Please type an option out of the ones below:" << std::endl;
    std::cout << "\t1.Encode File" << std::endl;
    std::cout << "\t2.Decode File" << std::endl;
    std::cout << "\t3.Exit" << std::endl;
    std::cout << std::endl;
}

void printMenuError(){
    std::cout << std::endl;
    std::cout << "Must be a number between 1 and 3" << std::endl;
    std::cout << std::endl;
}

void printExiting(){
    std::cout << std::endl;
    std::cout << "Exiting..." << std::endl;
    std::cout << std::endl;
}

void printEncodeFileMenu(){
    std::cout << std::endl;
    std::cout << "Please input the name of the file to encode" << std::endl;
    std::cout << std::endl;
}

void printDecodeFileMenu(){
    std::cout << std::endl;
    std::cout << "Please input the name of the huffman encoded file to decode" << std::endl;
    std::cout << std::endl;
}

void printFileNotFound(){
    std::cout << std::endl;
    std::cout << "File not found!" << std::endl;
    std::cout << std::endl;
}

void printFileFound(){
    std::cout << std::endl;
    std::cout << "File Found! Process starting..." << std::endl;
    std::cout << std::endl;
}