#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	double number, Pow = 1;
	unsigned int n;

	cout << "Введите число: ";
	cin >> number;
	cout << "Введите значение степени: ";
	cin >> n;

	for (unsigned int i = 0; i < n; i++) {
		Pow *= number;
	}

	cout << "Результат: " << Pow << endl;

	system("pause");
	return 0;
}