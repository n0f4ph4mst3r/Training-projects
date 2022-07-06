#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <memory>
#include <vector>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<double>> value = std::make_unique<InputValue<double>>();
	value->SetMin(0);
	value->SetMessage("Введите сумму(руб.): ");
	double sum = value->GetValue();
	std::cout << std::endl;

	std::unique_ptr<InputValue<unsigned>> option_input = std::make_unique<InputValue<unsigned>>();
	option_input->SetMessage("Вы являетесь резидентом страны?\r\n1 - да\r\n2 - нет\r\n");
	option_input->SetAllowedValues({ 1, 2 });
	unsigned option = option_input->GetValue();
	bool isResident = true;
	if (option == 2) isResident = false;
	std::cout << std::endl;

	option_input->SetAllowedValues({ 1, 2, 3, 4, 5});
	option_input->SetMessage("Каким образом получена сумма?\r\n1 - Трудовая деятельность\r\n2 - Продажа имущества\r\n3 - Дивиденты\r\n4 - Доход по вкладам\r\n5 - Приз или выигрыш\r\n");
	option = option_input->GetValue();
	std::cout << std::endl;

	double proz;
	switch (option) {
	case 1: case 2:
		if (isResident)
			proz = 0.13;
		else
			proz = 0.3;
		break;
	case 3:
		if (isResident)
			proz = 0.13;
		else
			proz = 0.15;
		break;
	case 4: case 5:
		proz = 0.35;
		break;
	}

	std::cout << "Процентная ставка: " << proz * 100 << " %" << std::endl;
	std::cout << "Налог НДФЛ: " << sum * proz << " руб." << std::endl;
	std::cout << "Сумма на руки: " << sum - sum * proz << " руб." << std::endl;

	system("pause");
	return 0;
}