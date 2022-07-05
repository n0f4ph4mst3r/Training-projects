#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <map>
#include <random>
#include <string>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//создаем "словарь" для измененных букв
	std::map<char, int> vowelsKeys; //для гласных
	std::map<char, char> consonantsKeys; //для согласных

	//заполняем словарь для гласных
	auto insertVowel = [&vowelsKeys](char c) mutable {
		vowelsKeys.insert(std::make_pair(c, (int)c));
	};

	std::string vowels = "AEIOUYaeiouy";
	for (auto c : vowels)
		insertVowel(c);

	//заполняем словарь для согласных
	auto insertConsonants = [=, &consonantsKeys](char itChar, const char end) mutable {
		while (itChar <= end) {
			std::map <char, int> ::iterator itMap;
			itMap = vowelsKeys.find(itChar);
			//если символ не гласная
			if (itMap == vowelsKeys.end()) {
				std::random_device r;
				std::default_random_engine e1(r());
				std::uniform_int_distribution<int> uniform_dist(0, 11);

				consonantsKeys.insert(std::make_pair(itChar, vowels[std::round(uniform_dist(e1))]));
			}
			++itChar;
		}
	};

	insertConsonants('B', 'Z');
	insertConsonants('b', 'z');

	//вводим строку
	std::cout << "Строка: ";
	std::string source;
	std::cin >> source;
	std::string result;

	for (auto c : source) {
		std::map <char, int> ::iterator itMap1;
		itMap1 = vowelsKeys.find(c);
		if (itMap1 != vowelsKeys.end()) {
			result += std::to_string(itMap1->second);
			result += " ";
		}
		else {
			std::map <char, char> ::iterator itMap2;
			itMap2 = consonantsKeys.find(c);
			if (itMap2 != consonantsKeys.end()) {
				result += itMap2->second;
				result += " ";
			}
		}
	}

	std::cout << "Результат: " << result << std::endl;

	system("pause");
	return 0;
}