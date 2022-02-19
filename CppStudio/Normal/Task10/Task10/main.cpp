#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <map>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите строку:\r\n";
	std::cout << std::endl;
	std::string str;
	std::cin >> str;
	std::cout << std::endl;

	std::map <char, unsigned> mp;

	for (int i = 0; i < str.length(); ++i) {
		if (mp.find(str[i]) == mp.end()) {
			mp.insert(std::make_pair(str[i], 1));
		}
		else {
			++mp[str[i]];
		}
	}

	std::cout << "Результат:\r\n";
	std::cout << std::endl;

	for (std::map <char, unsigned>::iterator i = mp.begin(); i != mp.end(); ++i) {
		std::cout << i->first << std::setw(4) << i->second << std::endl;
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}