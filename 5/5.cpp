// Лаба 5. Текстовые файлы
// Вариант 13

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

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

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream fin("5_input");
    vector<string> strings;
    vector<int> number_strings;
    string str;

    while (getline(fin, str)) {
        strings.emplace_back(str);
    }  
    for (int i = 0; i < strings.size(); i++) {
        if (isNumberString(strings[i])) {
            number_strings.push_back(i+1);
        }
    }

    vector<int>& first_numbers = number_strings;
    First_Strings_Only(strings, first_numbers);

    ofstream fout1("string numbers");
    ofstream fout2("string groups");
    for (const auto& line : first_numbers) {
        fout1 << line << endl;
    }
    for (int i = 0; i < first_numbers.size(); i++) {
        vector<nstring> repeated = Repeated_String(strings, first_numbers[i]);
        if (!repeated.empty()) {
            fout2 << i+1 << ")" << endl;
            fout2 << "Начальная строка: " << first_numbers[i] << endl;
            for (int j = 0; j < repeated.size(); j++) {
                fout2 << "Строка " << repeated[j].first << 
                " встретилась " << repeated[j].second << " раза" << endl; 
            }
        }
        else {
            fout2 << i+1 << ")" << endl;
            fout2 << "Начальная строка: " << first_numbers[i] << endl;
            fout2 << "В этой группе нет повторяющихся строк" << endl;
        }
        fout2 << endl;
    }
}