// Лаба 1, вычисление функций с точностью до k порядка
// 15.09.2024

#include <iostream>
#include <cmath>

int main() {
	int k, prec;
	double x;
	do {
		std::cout << "x (-1; 1) = ";
		std::cin >> x;
	} while (x >= 1. || x <= -1.);
	std::cout << "k = ";
	std::cin >> k;
	std::cout << "precision: ";
	std::cin >> prec;
	long double e = pow(10, -k); // эпсилон
	long double r2{acos(-1) / 2}; // ряды Тейлора
	long double r1{r2 - atan(x)}; // стандартная функция
	const int sign{-1};
	int exp{1};
	long double term = (-1)*x;
	while (fabs(term) >= e) {
		r2 += term;
		exp += 2;
		term *= (sign*x*x*(exp-2)) / exp*1.;
	}
	long double delta = fabs(r2 - r1);
	std::cout.precision(prec);
	std::cout << "Result using basic functions: " << r1 << std::endl;
	std::cout << "Result using Taylor rows: " << r2 << std::endl;
	std::cout << "delta = " << delta << std::endl;
}