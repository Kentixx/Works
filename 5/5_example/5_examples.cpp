#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //string
    std::string s1 = "Hello, world";
    s1 += " there";
    std::cout << s1 << std::endl;

    std::cout << s1.find("t") << std::endl; // тип возвращаемого значения - size_t
    std::cout << s1.find("AA", 4); // ()
    // Стоит пользоваться size_t при работе с массивами

    s1.replace(13, 5, "AK47"); //start, count, replacement
    std::cout << s1 << std::endl;

    s1.insert(6, " btw,"); //start, insertion
    std::cout << s1 << std::endl;

    const char *str = s1.c_str();
    //str[5] = 'C';

    std::cout << str << std::endl; // выводится вся строка
    std::cout << s1[7] << std::endl;

    std::string s2 = s1;
    s2.insert(4, "_LOL_");
    std::cout << s2 << " " << (s2 < s1) << std::endl;

    std::cout << s2.size() << std::endl;
    std::cout << s2.length() << std::endl;

    std::cout << s2.substr(5, 10) << std::endl;


    //file
    /*std::ofstream fout("out");
    fout << "print(Use C++ instead of pray)" << std::endl;
    */
    // std::cin.get();  ждет вписания чего либо в файл

    //fout.close();

    std::ofstream fout2("main.py"); // ios::app - сохраняет в закрытом ранее файле все, что было до этого
    fout2 << "print(Use C++ instead of pray)" << std::endl;
    fout2.close();
    
    //std::ifstream
    std::ifstream fin("out");
    // std::ofstream fin2("../2/2.cpp"); 
    int a, b;
    double c;
    fin >> a >> b >> c;
    cout << a << '\t' << b << '\t' << c << endl;
    fin.close();
}