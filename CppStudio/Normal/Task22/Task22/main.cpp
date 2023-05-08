#include <iostream>
#include <Windows.h>
#include <memory>
#include <map>
#include <format>
#include <iomanip>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<int>> mainoption = std::make_unique<InputValue<int>>();
	mainoption->SetMessage("Выберите действие\n\n1 - ввод матрицы\r\n2 - вывод матрицы\r\n3 - сложение матриц\r\n4 - умножение матриц\r\n5 - выход\r\n");
	int noption = 0;

	auto f_createMatrix = [](const unsigned height, const unsigned& width) { 
		std::map<unsigned, int> matrix;

		for (unsigned i = 0, k = 0; i < height; ++i) {
			for (unsigned j = 0; j < width; ++j, ++k) {
				std::unique_ptr<InputValue<int>> elemoption = std::make_unique<InputValue<int>>();
				elemoption->SetMessage(std::format("Элемент [{}][{}] = \r\n", i, j));
				int value = elemoption->GetValue();
				if (value != 0) matrix.insert(std::pair<unsigned, int>(k, value));
			}
		}

		return matrix;
	};

	std::map<unsigned, int> matrix;
	unsigned height = 0, width = 0;

	while (noption != 5) {
		noption = mainoption->GetValue();
		switch (noption) {
		case 1:
		{
			std::cout << "Введите размерность матрицы.\r\n";
			std::unique_ptr<InputValue<unsigned>> sizeoption = std::make_unique<InputValue<unsigned>>();
			sizeoption->SetMessage("Высота матрицы:\r\n");
			height = sizeoption->GetValue();
			sizeoption->SetMessage("Ширина матрицы матрицы:\r\n");
			width = sizeoption->GetValue();
			matrix = f_createMatrix(height, width);
			break;
		}
		case 2:
		{
			std::cout << "Матрица:\r\n";
			for (unsigned i = 0, k = 0; i < height; ++i) {
				for (unsigned j = 0; j < width; ++j, ++k) {
					int value = 0;
					if (auto search = matrix.find(k); search != matrix.end()) value = search->second;
					std::cout << std::setw(6) << value;
				}
				std::cout << std::endl;
			}
		}
		break;
		case 3:
		{
			std::cout << "2-ая матрица:\r\n";
			std::map<unsigned, int> matrix2 = f_createMatrix(height, width);
			for (unsigned i = 0, k = 0; i < height; ++i) {
				for (unsigned j = 0; j < width; ++j, ++k) {
					int value1 = 0;
					int value2 = 0;
					if (auto search = matrix.find(k); search != matrix.end()) value1 = search->second;
					if (auto search = matrix2.find(k); search != matrix2.end()) value2 = search->second;

					int result = value1 + value2;
					if (result != 0) {
						if (matrix.find(k) == matrix.end()) matrix.insert(std::pair<unsigned, int>(k, result));
						else matrix[k] = result;
					}
					else if (auto it = matrix.find(k); it != matrix.end()) matrix.erase(it);
				}
			}
		}
		break;
		case 4:
		{
			std::cout << "2-ая матрица:\r\n";
			std::map<unsigned, int> matrix2 = f_createMatrix(width, height);
			unsigned size = std::min<int>(width, height);

			std::map<unsigned, int> matrix3;
			for (unsigned i = 0, i_ = 0, k = 0; i < size; ++i, i_+=width) {
				for (unsigned j = 0; j < size; ++j, ++k) {
					int value3 = 0;
					for (unsigned l = i_, m = j; l < i_ + width; ++l, m+=height) {
						int value1 = 0;
						int value2 = 0;
						if (auto search = matrix.find(l); search != matrix.end()) value1 = search->second;
						if (auto search = matrix2.find(m); search != matrix2.end()) value2 = search->second;
						value3 += value1 * value2;
					}
					if (value3 != 0) matrix3.insert(std::pair<unsigned, int>(k, value3));
				}
			}

			matrix = std::move(matrix3);
			width = height = size;
			break;
		}
		default:
			break;
		}
	}

	system("pause");
	return 0;
}