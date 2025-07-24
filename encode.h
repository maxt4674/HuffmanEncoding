#ifndef ENCODE
#define ENCODE

#include "fileinout.h"
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "node.h"

bool encodeFile(std::string filename);
std::map<char, float> retrieveCharDistribution(std::vector<std::vector<char>> content);
std::map<char, std::vector<int>> convertProbToBinaryDist(std::map<char, float> probabilityDistribution);
std::vector<std::pair<char, float>> sortMapByValues(std::map<char, float> incomingMap);
void assignCodes(std::shared_ptr<node> current, std::vector<int> path, std::map<char, std::vector<int>>& binaryDist);

#endif