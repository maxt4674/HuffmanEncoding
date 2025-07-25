#ifndef FILEINOUT
#define FILEINOUT

#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

bool isFileValid(std::string filename);
std::vector<std::vector<char>> readFileChar(std::string filename);
bool writeEncodedFile(std::map<char, std::vector<int>> binaryDist, std::string filename);
std::map<std::string, char> retrieveBinaryDist(std::string filename);
bool writeDecodedFile(std::map<std::string, char> binaryDist, std::string filename);

std::vector<std::string> splitString(const std::string& s, char delimiter);

#endif