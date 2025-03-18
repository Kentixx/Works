  // Лаба 4(2). Строки, указатели, массивы символов
// Вариант 11

#include <iostream>
#include <cstring>

void High_Register (char& c) 
{
    c -= 32;
}

void No_first_elem (char *array2, char *array) {
    for (int i = 0; array2[i]; i++) {
        array2[i] = array[i+1];
    }
}

void Change_to_High_Register (char *string)
{
    const int a_code = 97, z_code = 122; 
    const int space_code = 32, newline_code = 10;
    /* std::cout << string[0] << std::endl;
    if (string[0] != space_code && string[0] >= a_code && string[0] <= z_code) {
        High_Register(string[0]);
    }*/
    for (int i = 0; i < strlen(string); i++) {
        if ((string[i-1] == space_code || string[i-1] == newline_code) && string[i] >= a_code && string[i] <= z_code) {
            High_Register(string[i]);
        }
    }
}

int main() {
    const int MAX_SYMBOLS = 300;
    int str_length;
    do {
        std::cout << "Введите длину строки (<=300):" << std::endl;
        std::cin >> str_length;
    } while (str_length > MAX_SYMBOLS || str_length <= 0);

    char *str = new char[str_length+2];
    std::cout << "Введите строку:" << std::endl;;
    std::cout << "P. S. В более длинной строке лишние элементы отбрасываются\n";
    std::cin.getline(str, str_length+2, ';');
    char *str2 = new char[str_length+1];
    //No_first_elem(str2, str); // удаление некого первого элемента с ASCII-кодом 10
    /* std::cout << str2 << " \n" << strlen(str); */
    Change_to_High_Register(str);
    std::cout << str;
    delete[] str;
    //delete[] str;
}