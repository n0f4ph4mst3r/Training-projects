#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	unsigned int range;

	cout << "Интервал: ";
	cin >> range;

	unsigned int index = 0;
	double sum = 0;

	while (index <= range)
	{
		if (index % 5 == 0) sum += index;
		index++;
	}

	cout << "Сумма: " << sum << endl;

	system("pause");
	return 0;
}