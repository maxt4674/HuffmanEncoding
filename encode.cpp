#include "encode.h"

bool encodeFile(std::string filename){
    std::vector<std::vector<char>> precodedArr = readFileChar(filename);
    std::map<char, float> probabilityDistribution = retrieveCharDistribution(precodedArr);

    if(probabilityDistribution.empty()){
        return false;
    }

    std::cout << std::endl;
    std::cout << "Probability Distribution of Characters in Document" << std::endl;
    std::cout << std::endl;

    for(const auto& pair : probabilityDistribution){
        char charIn = pair.first;
        float probIn = pair.second;

        std::cout << charIn << ": " << probIn << std::endl;
    }

    std::map<char, std::vector<int>> binaryDist = convertProbToBinaryDist(probabilityDistribution);

    if(binaryDist.empty()){
        return false;
    }

    std::cout << std::endl;
    std::cout << "Binary Representation of Characters" << std::endl;
    std::cout << std::endl;

    for(const auto& pair : binaryDist){
        char charIn = pair.first;
        std::vector<int> binary = pair.second;

        std::cout << charIn << ": ";

        for(int i = 0; i < binary.size(); i++){
            std::cout << binary.at(i);
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;

    if(!writeEncodedFile(binaryDist, filename)){
        return false;
    }

    std::cout << "Encoded File written!" << std::endl;

    return true;
};

std::map<char, float> retrieveCharDistribution(std::vector<std::vector<char>> content){
    int totalSize = 0;

    for(int i = 0; i < content.size(); i++){
        totalSize += content.at(i).size();
    }

    std::map<char, int> charCount;

    for(int i = 0; i < content.size(); i++){
        for(int j = 0; j < content.at(i).size(); j++){
            if(charCount.count(content.at(i).at(j)) > 0){
                charCount.at(content.at(i).at(j)) += 1;
            } else {
                charCount.insert({content.at(i).at(j), 1});
            }
        }
    }

    std::map<char, float> charProbability;

    for (const auto& pair : charCount){
        char charCounted = pair.first;
        int charCount = pair.second;

        float probability = charCount / float(totalSize);

        charProbability.insert({charCounted, probability});
    }

    return charProbability;
};

std::map<char, std::vector<int>> convertProbToBinaryDist(std::map<char, float> probabilityDistribution) {
    std::map<char, std::vector<int>> binaryDist;
    std::vector<std::pair<char, float>> probDistribution = sortMapByValues(probabilityDistribution);

    std::vector<std::shared_ptr<node>> consideredNodes;

    for (const auto& pair : probDistribution){
        char charIn = pair.first;
        float probIn = pair.second;

        consideredNodes.push_back(std::make_shared<node>(probIn, charIn));
    }

    auto compare = [](const std::shared_ptr<node>& a, const std::shared_ptr<node>& b) {
        return a->probability > b->probability;
    };

    std::make_heap(consideredNodes.begin(), consideredNodes.end(), compare);

    while (consideredNodes.size() > 1) {
        std::pop_heap(consideredNodes.begin(), consideredNodes.end(), compare);
        auto left = consideredNodes.back(); consideredNodes.pop_back();

        std::pop_heap(consideredNodes.begin(), consideredNodes.end(), compare);
        auto right = consideredNodes.back(); consideredNodes.pop_back();

        auto parent = std::make_shared<node>(left->probability + right->probability);
        parent->assignChildren(left, right);

        consideredNodes.push_back(parent);
        std::push_heap(consideredNodes.begin(), consideredNodes.end(), compare);
    }

    assignCodes(consideredNodes.front(), {}, binaryDist);
    return binaryDist;
}

std::vector<std::pair<char, float>> sortMapByValues(std::map<char, float> incomingMap) {
    std::vector<std::pair<char, float>> vec(incomingMap.begin(), incomingMap.end());

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    return vec;
}

void assignCodes(std::shared_ptr<node> current, std::vector<int> path, std::map<char, std::vector<int>>& binaryDist) {
    if (!current->left && !current->right) {
        binaryDist[current->charIn] = path;
        return;
    }
    if (current->left) {
        path.push_back(0);
        assignCodes(current->left, path, binaryDist);
        path.pop_back();
    }
    if (current->right) {
        path.push_back(1);
        assignCodes(current->right, path, binaryDist);
        path.pop_back();
    }
}