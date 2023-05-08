#define NOMINMAX

#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <array>
#include <random>
#include <chrono>
#include <iomanip>
#include "InputValue.h"

struct MinElement {
	double elem;
	unsigned row;
};

int main() {
	SetConsoleOutputCP(1251);

	InputValue<double>* inputDBL = new InputValue<double>();

	inputDBL->SetMessage("Введите первое число: ");
	double a = inputDBL->GetValue();
	inputDBL->SetMessage("Введите второе число: ");
	double b = inputDBL->GetValue();
	std::cout << std::endl;

	//заполняем матрицу
	std::array<std::array<double, 10>, 10> matrix;

	auto rng = std::default_random_engine{};
	rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_real_distribution<> dis(std::min(a, b), std::max(a, b));

	for (unsigned i = 0; i < 10; ++i) {
		for (unsigned j = 0; j < 10; ++j) {
			matrix[i][j] = dis(rng);
		}
	}

	std::cout << "Матрица:\r\n";
	std::cout << std::endl;
	for (unsigned i = 0; i < 10; ++i) {
		for (unsigned j = 0; j < 10; ++j) {
			std::cout << std::setw(7) << std::setprecision(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//находим минимальный элемент
	MinElement min;
	min.elem = DBL_MAX;
	min.row = 0;

	for (unsigned i = 0; i < 10; ++i) {
		for (unsigned j = 0; j < 10; ++j) {
			if (matrix[i][j] < min.elem) {
				min.elem = matrix[i][j];
				min.row = i;
			}
		}
	}

	std::cout << "Минимальный элемент: " << min.elem << std::endl;
	std::cout << "Номер строки: " << min.row+1 << std::endl;
	std::cout << std::endl;

	//меняем строки
	std::swap(matrix[0], matrix[min.row]);

	std::cout << "Результат:\r\n";
	std::cout << std::endl;
	for (unsigned i = 0; i < 10; ++i) {
		for (unsigned j = 0; j < 10; ++j) {
			std::cout << std::setw(7) << std::setprecision(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}

