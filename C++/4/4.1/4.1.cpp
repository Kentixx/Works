// Лаба 4(1). Строки, указатели, массивы символов
// Вариант 11

#include <iostream>
#include <cstring>

int _strcspn (const char *string, const char *strCharSet) {
    int diff_char = strlen(string);
    for (int i = 0; i != strlen(string); i++) {
        for (int j = 0; j != strlen(strCharSet); j++) {
            if (string[i] == strCharSet[j]) {
                diff_char = i;
                break;
            }
        }
        if (diff_char != strlen(string)) {
            break;
        }
    }
    return diff_char;
}
int main() {
    int n, m;
    std::cout << "Количество элементов string" << std::endl;
    std::cin >> n;
    std::cout << "Количество элементов CharSet" << std::endl;
    std::cin >> m;
    char *str = new char[n+1];
    char *Chrset = new char[m+1];
    std::cout << "Введите исходную строку string" << std::endl;
    std::cin >> str;
    std::cout << "Введите множество CharSet" << std::endl;
    std::cin >> Chrset;
    std::cout << "Длина начальной подстроки string, не содержащей символов из CharSet: " << strcspn(str, Chrset) << std::endl;
    delete[] str;
    delete[] Chrset;
}