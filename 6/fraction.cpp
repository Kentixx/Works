#include "fraction.h"

Fraction::Fraction(int _a, int _b) : a(_a), b(_b) {
    int nod = std::gcd(a, b);
    if (nod != 1) {
        a /= nod;
        b /= nod;
    } // сокращение дроби
    if (a > 0 && b < 0 || a < 0 && b < 0) {
        b *= -1;
        a *= -1;
    } // перенос знака минус в числитель 
}

Fraction::Fraction(const Fraction &other) {
    a = other.a;
    b = other.b;
    c = other.c;
}
    
int Fraction::getA() const {
    return a;
}
int Fraction::getB() const {
    return b;
}

Fraction Fraction::operator+(const Fraction &other) {
    int d = std::lcm(b, other.b);
    return Fraction(a*d/b + other.a*d/other.b, d);
}

Fraction Fraction::operator-(const Fraction &other) {
    int d = std::lcm(b, other.b);
    return Fraction(a*d/b - other.a*d/other.b, d);
}

Fraction Fraction::operator*(const Fraction &other) {
    int new_a = a*other.a;
    int new_b = b*other.b;
    if (std::gcd(new_a, new_b) != 1) {
        new_a /= std::gcd(new_a, new_b);
        new_b /= std::gcd(new_a, new_b);
    }
    return Fraction(new_a, new_b);
}

Fraction Fraction::operator/(const Fraction &other) {
    int new_a = a*other.b;
    int new_b = b*other.a;
    if (std::gcd(new_a, new_b) != 1) {
        new_a /= std::gcd(new_a, new_b);
        new_b /= std::gcd(new_a, new_b);
    }
    return Fraction(new_a, new_b);
}

std::ostream& operator<<(std::ostream &out, Fraction &frac) {
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
