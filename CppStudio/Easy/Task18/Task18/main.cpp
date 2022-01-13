#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	cout << "Введите число: ";
	int num;
	cin >> num;

	cout.unsetf(ios::dec);
	cout << "Результат: ";
	cout.setf(ios::hex);
	cout << num << endl;

	system("pause");
	return 0;
}