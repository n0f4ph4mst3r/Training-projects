#include <iostream>
#include <Windows.h>
#include <memory>
#include <map>
#include <format>
#include <iomanip>
#include <vector>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::cout << "Введите результаты соревнований:\r\n\r\n\r\n";
	std::vector<std::vector<double>> matrix(5);
	for (unsigned i = 0; i < 5; ++i) {
		matrix[i].reserve(3);
		std::cout << std::format("Для {} спортсмена:\r\n\r\n", i+1);
		for (unsigned j = 0; j < 3; ++j) {
			std::unique_ptr<InputValue<double>> valueInput = std::make_unique<InputValue<double>>();
			valueInput->SetMessage(std::format("Попытка {}: ", j + 1));
			double value = valueInput->GetValue();
			matrix[i].push_back(value);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Лучший результат у спортсменов:\r\n\r\n\r\n";
	for (unsigned i = 0; i < 5; ++i)
		std::cout << std::format("Для {} спортсмена - {}\r\n\r\n", i + 1, std::max<double>(matrix[i][0], std::max<double>(matrix[i][1], matrix[i][2])));

	system("pause");
	return 0;
}