#ifndef ENCODE
#define ENCODE

#include "fileinout.h"
#include <vector>
#include <fstream>
#include <string>
#include <map>

bool encodeFile(std::string filename){};
std::map<char, int> retrieveCharDistribution(std::vector<std::vector<char>> content){};

#endif