#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <math.h>

#define M_PI           3.14159265358979323846 

using namespace std;


int main()
{
	SetConsoleOutputCP(1251);

	double sum = 0, sub = 0;
	unsigned int range, index = 0;

	cout << "Интервал: ";
	cin >> range;

	for (int i = 1; i <= range; i++)
	{
		sub += sin((double)i * M_PI / 180);
		sum += 1 / sub;
	}

	cout << "Сумма: " << sum << endl;

	system("pause");
	return 0;
}

