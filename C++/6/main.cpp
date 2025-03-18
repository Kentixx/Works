// Лаба 6. Простейший класс

#include <iostream>
#include <numeric>
#include <cmath>
#include "fraction.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int a1, b1, a2, b2;
    do {
    std::cout << "Введите числитель и знаменатель 1-ой дроби:" << std::endl;
    std::cin >> a1 >> b1;
    if (b1 == 0)
        std::cout << "Знаменатель не может равняться 0" << std::endl;
    } while (b1 == 0);
    do {
    std::cout << "Введите числитель и знаменатель 2-ой дроби:" << std::endl;
    std::cin >> a2 >> b2;
    if (b2 == 0)
        std::cout << "Знаменатель не может равняться 0" << std::endl;
    } while (b2 == 0);
    Fraction f1(a1, b1), f2(a2, b2);

    //std::cout << std::gcd(a1, b1) << " " << std::gcd(a2, b2) << std::endl;
    Fraction f3 = f1 + f2, f4 = f1 - f2;
    std::cout << "Сумма: " << f3 << std::endl;
    std::cout << "Разность: " << f4 << std::endl;

    Fraction f5 = f1 * f2;
    //std::cout << "Произведение: " << f5 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f5 << std::endl;

    if (f2.getA() == 0) {
        std::cout << "Частное: не определено" << std::endl;
    } else {
        Fraction f6 = f1 / f2;
        std::cout << "Частное: " << f6 << std::endl;
    }
}