#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "functions.h"

typedef std::pair<std::string, std::string> strpair;

std::string Second_Substring_of_First(const std::pair<std::string, std::string>& strs) {
    if (strs.first.find(strs.second) != std::string::npos) {
        return "YES";
    }
    else {
        return "NO";
    }
}

std::vector<strpair> ReadStringPairs(const std::string& filePath) {
    std::ifstream data(filePath);
	std::vector<strpair> VectorStrings;
	strpair s;
	while (data >> s.first >> s.second) { // >> 
		VectorStrings.emplace_back(s);
	}
	return VectorStrings;
}

void VectorOutput(const std::vector<std::string>& strings, const std::string& filePath) {
    std::ofstream fout(filePath);
    for (int i = 0; i < strings.size(); i++) {
        fout << i+1 << " - " << strings[i] << std::endl;
    }
}