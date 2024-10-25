// Лаба 5. Текстовые файлы
// Вариант 13

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;
typedef std::pair<string, int> nstring;

bool isNumberString(const string& str);
vector<nstring> Repeated_String(const vector<string>& strs, int begin); // считает количество повторяющихся строк в группе
void First_Strings_Only(const vector<string>& strs, vector<int>& v_str); // оставляет только номера первых строк групп

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream fin("files/5_input");
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

    ofstream fout1("files/string numbers");
    ofstream fout2("files/string groups");
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