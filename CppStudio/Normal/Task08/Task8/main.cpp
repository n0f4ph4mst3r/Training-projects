#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "InputValue.h"
#include <map>
#include <ctype.h>

using namespace std;

enum {
	TOUPPER,
	TOLOWER,
	TOCAPITAL,
	TOCAPITALLOWER,
	TOAVERAGE,
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	InputValue<char>* inputCHAR = new InputValue<char>();
	InputValue<std::string>* inputSTR = new InputValue<std::string>();
	
	inputSTR->SetMessage("Введите строку:\r\n\n");
	std::string str = inputSTR->GetValue();
	cout << endl;

	std::vector<char> availableOptions = { '1', '2', '3', '4', '5', 'f' };
	inputCHAR->SetAllowedValues(availableOptions);

	inputCHAR->SetMessage("Для преобразования строки в заглавные буквы нажмите : 1\nДля преобразования строки в нижний регистр нажмите : 2\nДля преобразования строки с Заглавной Буквы нажмите : 3\nДля преобразования строки в первый символ в нижнем регистре нажмите : 4\nДля преобразования строки как в обычном предложении нажмите : 5\nДля выхода нажмите : f\n\nВведите необходимое действие : ");

	while (true) {
		char currentOption = inputCHAR->GetValue();
		cout << endl;

		if (currentOption == 'f') break;

		std::map<char, int> options = { {'1', TOUPPER},
										{'2', TOLOWER},
										{'3', TOCAPITAL},
										{'4', TOCAPITALLOWER},
										{'5', TOAVERAGE}
		};

		std::string result = str;
		switch (options[currentOption]) {
		case TOUPPER:
			for (size_t i = 0; i < result.length(); ++i) {
				if (islower(result[i])) result[i] = toupper(result[i]);
			}
			break;

		case TOLOWER:
			for (size_t i = 0; i < result.length(); ++i) {
				if (isupper(result[i])) result[i] = tolower(result[i]);
			}
			break;

		case TOCAPITAL:
		{
			bool isCapital = true;

			for (size_t i = 0; i < result.length(); ++i) {
				if (isspace(result[i])) {
					isCapital = true;
				}
				else if (isCapital) {
					if (islower(result[i])) result[i] = toupper(result[i]);
					isCapital = false;
				}
				else {
					if (isupper(result[i])) result[i] = tolower(result[i]);
				}
			}
		}
			break;

		case TOCAPITALLOWER:
		{
			bool isCapital = true;

			for (size_t i = 0; i < result.length(); ++i) {
				if (isspace(result[i])) {
					isCapital = true;
				}
				else if (isCapital) {
					if (isupper(result[i])) result[i] = tolower(result[i]);
					isCapital = false;
				}
				else {
					if (islower(result[i])) result[i] = toupper(result[i]);
				}
			}
		}
			break;

		case TOAVERAGE:
			if (islower(result[0])) result[0] = toupper(result[0]);

			for (size_t i = 1; i < result.length(); ++i) {
				if (isupper(result[i])) result[i] = tolower(result[i]);
			}
			break;

		default:
			cout << "FATAL ERROR!\n";
			return 1;
		}
		cout << result << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}