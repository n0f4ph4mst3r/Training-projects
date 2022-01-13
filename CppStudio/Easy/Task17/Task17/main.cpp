#include <iostream>
#include <cstdlib>
#include <cctype>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	string num;

	cout << "Введите число: ";
	cin >> num;
	if ( isdigit(num[0]) )
	{
		unsigned int k;
		cout << "Порядковый номер числа: ";
		cin >> k;
		cout << endl;

		cout << "k-ый символ последовательности: " << num[k-1] << endl;
	}
	else
	{
		cout << "Неверный формат!" << endl;
	}

	system("pause");
	return 0;
}