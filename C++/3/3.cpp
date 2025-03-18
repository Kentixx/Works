// Лаба 3, двумерные массивы
// Вариант 13

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void VectorPrint(const std::vector<std::vector<int>>& x)
{
	for (const auto& ints : x) {
		for (int j = 0; j != x[0].size(); j++) {
			std::cout << ints[j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Transpose(const std::vector<std::vector<int>>& Vector, std::vector<std::vector<int>>& TVector)
{
	for (int i = 0; i != TVector.size(); i++) {
		for (int j = 0; j < TVector[0].size(); j++) {
			TVector[i][j] = Vector[j][i];
		}
	}
}

bool comp(const std::vector<int>& a, const std::vector<int>& b)
{
	int a_sum(0), b_sum(0);
	for (const auto& elem_a : a) {
		a_sum += abs(elem_a);
	}
	for (const auto& elem_b : b) {
		b_sum += abs(elem_b);
	}
	return (a_sum < b_sum);
}

void Matrix_sort(std::vector<std::vector<int>>& m)
{
	const int rows = m.size();
	const int columns = m[0].size();
	std::vector<std::vector<int>> Tmatrix(columns, std::vector<int>(rows));
	Transpose(m, Tmatrix);
	std::sort(Tmatrix.rbegin(), Tmatrix.rend(), comp);
	Transpose(Tmatrix, m);
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	
	const int MAX_SIZE = 10;
	int rows, cols, isRand;
	do {
		std::cout << "Размер матрицы (строки, столбцы (первые n) | <=10): " << std::endl;
		std::cin >> rows >> cols;
	} while (rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0);
	do {
		std::cout << "Использовать случайные числа? (0/1)" << std::endl;
		std::cin >> isRand;
	} while (isRand < 0 || isRand > 1);

	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
	if (isRand) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				// std::cin >> matrix[i][j];
				matrix[i][j] = rand() % 1000 - 500;
			}
		}
	}
	else {
		std::cout << "Введите элементы матрицы (первые n столбцов)" << std::endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cin >> matrix[i][j];
			}
		}
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i].push_back(-matrix[i][j]);
		}
	}
	std::cout << "Исходная матрица" << std::endl;
	VectorPrint(matrix);
	Matrix_sort(matrix);
	std::cout << std::endl;
	std::cout << "Отсортированная матрица: " << std::endl;
	VectorPrint(matrix);
}