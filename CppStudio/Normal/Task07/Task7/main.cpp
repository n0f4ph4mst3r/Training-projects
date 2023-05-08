#include <iostream>
#include <cstdlib>
#include "Windows.h"
#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	InputValue<int>* inputINT = new InputValue<int>();
	inputINT->SetMessage("Введите х: ");

	int x = inputINT->GetValue();
	double y = x;

	while (true) {
		double yNext = 0.5 * (y + 3 * x / (2 * pow(y,2) + x/y));
		if (fabs(yNext - y) < pow(10, -5)) break;
		else y = yNext;
	}

	std::cout << "Результат: " << y << std::endl;

	system("pause");
	return 0;
}