#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int count, sum = 0, range;
	cout << "Введите интервал: ";
	cin >> count;
	range = count;

	while (count != 0)
	{
		if (count % 5 == 0) sum += count;
		count--;
	}

	cout << "Сумма чисел, нацело делящихся на 5, в интервале [0," << range << "] равна: " << sum << endl;

	system("pause");
	return 0;
}