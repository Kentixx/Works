// Лаба 1, вычисление функций с точностью до k порядка
// 15.09.2024

#include <iostream>
#include <cmath>

int main() {
	int k, prec;
	double x;
	std::cout << "x (-1; 1) = ";
	std::cin >> x;
	std::cout << "k = ";
	std::cin >> k;
	std::cout << "precision: ";
	std::cin >> prec;
	double e{ pow(10, -k) }; // эпсилон
	double r2{ acos(-1) / 2 }; // ряды Тейлора
	double r1{ r2 - atan(x) }; // стандартная функция
	int sign{ 1 }, exp{ -1 };
	while (true) {
		sign *= -1;
		exp += 2;
		double t = (sign * pow(x, exp)) / exp * 1.;
		//std::cout << t << std::endl;
		if (abs(t) < e) {
			break;
		}
		r2 += t;
	}
	double delta = abs(r2 - r1);
	std::cout.precision(prec);
	std::cout << "Result using basic functions: " << r1 << std::endl;
	std::cout << "Result using Taylor rows: " << r2 << std::endl;
	std::cout << "d = " << delta << std::endl;
}