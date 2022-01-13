#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int num;

	do
	{
		cout << "Введите число: ";
		cin >> num;
	} while (num != 1);

	system("pause");
	return 0;
}