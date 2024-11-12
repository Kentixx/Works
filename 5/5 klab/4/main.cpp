#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "functions.h"

typedef std::pair<std::string, std::string> strpair;

std::string Second_Substring_of_First(const strpair& strs);
std::vector<strpair> ReadStringPairs(const std::string& filePath);
void VectorOutput(const std::vector<std::string>& strings, const std::string& filePath);

int main() {
    std::vector<strpair> string_pairs = ReadStringPairs("data/string pairs");
    std::vector<std::string> CheckedStrings;
    for (int i = 0; i < string_pairs.size(); i++) {
        CheckedStrings.emplace_back(Second_Substring_of_First(string_pairs[i]));
    }
    VectorOutput(CheckedStrings, "data/checked strings");
}