#ifndef FILEINOUT
#define FILEINOUT

#include <string>
#include <fstream>
#include <vector>

bool isFileValid(std::string filename);
std::vector<std::vector<char>> readFileChar(std::string filename);

#endif