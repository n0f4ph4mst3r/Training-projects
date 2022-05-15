#include <iostream>
#include <Windows.h>
#include <memory>
#include <vector>
#include <format>
#include <iomanip>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<unsigned>> InputUnsigned = std::make_unique<InputValue<unsigned>>();
	//ввод матрицы
	//ввод размера
	InputUnsigned->SetMessage("Введите высоту матрицы: ");
	unsigned height = InputUnsigned->GetValue();
	InputUnsigned->SetMessage("Введите ширину матрицы: ");
	unsigned width = InputUnsigned->GetValue();
	std::cout << std::endl;
	
	std::vector<std::vector<unsigned>> matrix;
	matrix.resize(height);
	for (unsigned i = 0; i < height; ++i) {
		matrix[i].resize(width);
	}
	//ввод значений и поиск модуля
	std::unique_ptr<InputValue<int>> InputInt = std::make_unique<InputValue<int>>();
	int max = 0;
	std::pair<int, int> point(0,0);
	std::cout << "Введите элементы матрицы:\r\n\r\n";
	for (unsigned i = 0; i < height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			InputInt->SetMessage(std::format("matrix[{}][{}] = ", i, j));
			matrix[i][j] = InputInt->GetValue();
			if (abs((int)matrix[i][j]) > max) {
				max = matrix[i][j];
				point.first = i;
				point.second = j;
			} 
		}
	}
	std::cout << std::endl;

	std::cout << "Матрица:\r\n\r\n";
	for (unsigned i = 0; i < height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			std::cout << std::setw(9) << matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//преобразование матрицы
	std::swap(matrix[point.first], matrix[height-1]);
	for (unsigned i = 0; i < height; ++i) {
		std::swap(matrix[i][point.second], matrix[i][width-1]);
	}
	//вывод результата
	std::cout << std::format("Максимальный модуль - {}\r\nСтрока - {}\r\nСтолбец - {}\r\n ", max, ++point.first, ++point.second);
	std::cout << std::endl;
	for (unsigned i = 0; i < height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			std::cout << std::setw(9) << matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}