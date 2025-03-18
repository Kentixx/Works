#pragma once
#include <iostream>
#include <numeric>
#include <cmath>

class Fraction{
    int a; // числитель
    int b; // знаменатель
public:
    int c; // целая часть

    Fraction(int _a, int _b);
    Fraction() = delete;
    Fraction(const Fraction &other);
    
    int getA() const;
    int getB() const;

    Fraction operator+(const Fraction &other);
    Fraction operator-(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction operator/(const Fraction &other);
};

std::ostream& operator<<(std::ostream &out, Fraction &frac);