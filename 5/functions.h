#pragma once
#include <iostream>
#include <vector>

bool isNumberString(const std::string& str);

std::vector<std::pair<std::string, int>> Repeated_String(const std::vector<std::string>& strs, int begin);

void First_Strings_Only(const std::vector<std::string>& strs, std::vector<int>& v_str);
