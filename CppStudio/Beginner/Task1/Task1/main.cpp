#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите число: ";
	int number;
	cin >> number;
	int div = 10000, tmp, result;

	for (int i = 0; i < 4; i++)
	{
		tmp = number % div;
		result = (number - tmp) / div;
		number = tmp;
		div /= 10;
		switch (i) {
		case 0:
			cout << "Первое число: " << result << endl;
			break;
		case 1:
			cout << "Второе число: " << result << endl;
			break;
		case 2:
			cout << "Третье число: " << result << endl;
			break;
		case 3:
			cout << "Четвертое число: " << result << endl;
			break;
		default:
			break;
		};
	}
	cout << "Пятое число: " << number << endl;

	system("pause");
	return 0;
}