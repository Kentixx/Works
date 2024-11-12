#pragma once
#include <iostream>
#include <numeric>
#include <cmath>

class Fraction{
    int a; // числитель
    int b; // знаменатель
public:
    int c; // целая часть
    Fraction(int _a, int _b) : a(_a), b(_b) {
        int nod = std::gcd(a, b);
        if (nod != 1) {
            a /= nod;
            b /= nod;
        } // сокращение дроби
        if (a > 0 && b < 0 || a < 0 && b < 0) {
            b *= -1;
            a *= -1;
        } // перенос знака минус в числитель
    };

    int getA() const {
        return a;
    }
    int getB() const {
        return b;
    }

    Fraction operator+(const Fraction &other) {
        int d = std::lcm(b, other.b);
        int new_a1 = a*d/b;
        int new_a2 = other.a*d/other.b;
        return Fraction(new_a1 + new_a2, d);
    }

    Fraction operator-(const Fraction &other) {
        int d = std::lcm(b, other.b);
        int new_a1 = a*d/b;
        int new_a2 = other.a*d/other.b;
        return Fraction(new_a1 - new_a2, d);
    }

    Fraction operator*(const Fraction &other) {
        int new_a = a*other.a;
        int new_b = b*other.b;
        int nod = std::gcd(new_a, new_b);
        if (nod != 1) {
            new_a /= nod;
            new_b /= nod;
        }
        return Fraction(new_a, new_b);
    }

    Fraction operator/(const  Fraction &other) {
        int new_a = a*other.b;
        int new_b = b*other.a;
        int nod = std::gcd(new_a, new_b);
        if (nod != 1) {
            new_a /= nod;
            new_b /= nod;
        }
        return Fraction(new_a, new_b);
    }

};

std::ostream& operator<<(std::ostream &out, Fraction &frac) 
{
    if (frac.getB() == 1) {
        out << frac.getA();
    } else {
        if (abs(frac.getA()) > frac.getB()) {
            frac.c = abs(frac.getA())/frac.getB();
            if (frac.getA() < 0) {
                frac.c *= -1;
            }
            out << frac.c << " " << abs(frac.getA())-(abs(frac.c)*frac.getB()) << "/" << frac.getB();
        }
        else {
            out << frac.getA() << "/" << frac.getB();
        }
    }
    return out;
}