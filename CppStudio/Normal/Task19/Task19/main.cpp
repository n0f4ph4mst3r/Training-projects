#include <iostream>
#include <Windows.h>
#include <memory>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<int>> option = std::make_unique<InputValue<int>>();
	option->SetAllowedValues({ 0, 1 });

	while (true) {
		option->SetMessage("8-ая симфония Чайковского вышла в 1809 г.? (да - 1, нет - 0) ");
		int noption = option->GetValue();
		if (noption == 0) break;

		option->SetMessage("Написал ли Чайковский 8-ую симфонию? (да - 1, нет - 0) ");
		noption = option->GetValue();
		if (noption == 0) break;

		option->SetMessage("Вы дешёвка? (да - 1, нет - 0) ");
		noption = option->GetValue();
		if (noption == 0) break;
	}

	std::cout << "Ваше имя: ";
	std::string name;
	std::cin >> name;

	std::cout << name << ", вы думаете, что я вас не переиграю, что я вас не уничтожу? Я вас уничтожу, " << name << "." << std::endl;

	system("pause");
	return 0;
}