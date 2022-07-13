#include <iostream>
#include <Windows.h>
#include <memory>
#include <map>

#include "InputValue.h"

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<int>> optionInput = std::make_unique<InputValue<int>>();
	optionInput->SetMessage("1 - ввод строки\r\n2 - подсчет символов\r\n3 - результат\r\n4 - выход\r\n\r\n");
	optionInput->SetAllowedValues({ 1,2,3,4 });

	unsigned noption = 0;
	std::string str = "";
	unsigned max = 0;
	while (noption != 4) {
		auto SetString = [&str, &max]() {
			std::cout << "Введите строку: ";
			std::cin >> str; 
			std::cout <<  std::endl;
			max = 0;
		};

		auto ProcessData = [&str, &max]() {
			std::cout << "Обрабатываю строку...\r\n";
			std::map <char, unsigned> mp;
			std::map <char, unsigned>::iterator it;

			for (int i = 0; i < str.length(); ++i) {
				it = mp.find(str[i]);
				if (it != mp.end()) {
					++mp[str[i]];
				}
				else
					mp.insert(std::pair<char, unsigned>(str[i], 1));

				if (mp[str[i]] > max)
					max = mp[str[i]];
			}

			std::cout << "Готово.\r\n\r\n";
		};

		auto PrintResult = [&max]() {
			std::cout << "Результат: " << max << "\r\n\r\n";
		};

		noption = optionInput->GetValue();
		switch (noption) {
		case 1:
			SetString();
			break;
		case 2:
			ProcessData();
			break;
		case 3:
			PrintResult();
			break;
		case 4:
			break;
		}
	}

	system("pause");
	return 0;
}