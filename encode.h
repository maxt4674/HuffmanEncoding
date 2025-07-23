#ifndef ENCODE
#define ENCODE

#include "fileinout.h"
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <iostream>

bool encodeFile(std::string filename);
std::map<char, float> retrieveCharDistribution(std::vector<std::vector<char>> content);

#endif