#include <iostream>
#include <Windows.h>
#include <memory>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<unsigned>> inputOption = std::make_unique<InputValue<unsigned>>();
	inputOption->SetMessage("0 - добавить число\r\n1 - выйти\r\n");
	inputOption->SetAllowedValues({ 0,1 });

	unsigned noption = 0;
	std::string value = "";
	while (noption != 1) {
		auto аddRightDigit = [&value]() {
			std::unique_ptr<InputValue<unsigned>> inputNumber = std::make_unique<InputValue<unsigned>>();
			inputNumber->SetMessage("Введите число: ");
			inputNumber->SetMax(9);
			unsigned n = inputNumber->GetValue();

			value += std::to_string(n);
			std::cout << "Текущее число - " << value << "\r\n\r\n";
		};

		noption = inputOption->GetValue();
		if (noption == 0)
			аddRightDigit();
	}

	system("pause");
	return 0;
}