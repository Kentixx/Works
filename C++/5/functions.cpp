#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;
typedef std::pair<string, int> nstring;

bool isNumberString(const string& str) 
{
    if (str.empty()) {
        return false;
    }
    const int code_0 = 48, code_9 = 57;
    for (int i = 0; i < str.length(); i++) {
        if (!(str[i] >= code_0 && str[i] <= code_9)) {
            return false;
            break;
        }
    }
    return true;
}

vector<nstring> Repeated_String(const vector<string>& strs, int begin) // считает количество повторяющихся строк в группе
{
    vector<nstring> rep_strings;
    nstring result;
    int end;
    result.second = 1;
    begin--;
    for (int i = begin; i < strs.size(); i++) {
        if (!isNumberString(strs[i])) {
            end = i;
            break;
        }
    }
    for (int i = begin; i < end; i++) {
        bool Met_Before = 0;
        for (int i_1 = begin; i_1 < i; i_1++) {
            if (strs[i_1] == strs[i]) {
                Met_Before = 1;
            }
        }
        if (!Met_Before) {
            for (int j = i+1; j < end; j++) {
                if (strs[j] == strs[i]) {
                    result.second++;
                }
            }
            if (result.second > 1) {
                result.first = strs[i];
                rep_strings.emplace_back(result);
            }
            result.second = 1;
        }
    }
    return rep_strings;
}

void First_Strings_Only(const vector<string>& strs, vector<int>& v_str) // оставляет только номера первых строк групп
{
    int pointer = 0;
    for (size_t i = 0; i < v_str.size() - 1; i++) {
        if (v_str[i+1] - v_str[i] == 1) {
            pointer = i + 1;
            while (v_str[pointer+1] - v_str[pointer] == 1) {
                pointer++;
            }
            auto iter = v_str.cbegin();
            v_str.erase(iter+i+1, iter+pointer+1);
        }
    }
}