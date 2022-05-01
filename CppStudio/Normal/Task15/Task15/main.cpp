#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <memory>
#include <random>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<unsigned>> InputUnsigned = std::make_unique<InputValue<unsigned>>();
    
	InputUnsigned->SetMessage("Высота матрицы: ");
	unsigned height = InputUnsigned->GetValue();
	InputUnsigned->SetMessage("Ширина матрицы: ");
	unsigned width = InputUnsigned->GetValue();

	std::vector<std::vector<int>> matrix;
	matrix.resize(height);
	for (auto &vec : matrix) vec.resize(width);

	std::vector<int> vec;
	std::cout << "Матрица:\r\n";
	std::cout << std::endl;
	for (unsigned i = 0; i < height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			std::random_device rd;     
			std::mt19937 rng(rd());    
			std::uniform_int_distribution<int> uni(-100, 100); 

			matrix[i][j] = uni(rng);
			std::cout << std::setw(6) << matrix[i][j];
			vec.push_back(std::move(matrix[i][j]));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Вектор:\r\n";
	for (auto elem : vec) std::cout << std::setw(6) << elem;
	std::cout << std::endl;

	system("pause");
	return 0;
}