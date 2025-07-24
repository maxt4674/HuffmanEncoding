#ifndef FILEINOUT
#define FILEINOUT

#include <string>
#include <fstream>
#include <vector>
#include <map>

bool isFileValid(std::string filename);
std::vector<std::vector<char>> readFileChar(std::string filename);
bool writeEncodedFile(std::map<char, std::vector<int>> binaryDist, std::string filename);

#endif