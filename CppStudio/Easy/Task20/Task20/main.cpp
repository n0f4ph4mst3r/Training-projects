#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

double a, b, h;

void InputValue()
{
	cout << "Левая граница: ";
	cin >> a;

	cout << "Правая граница: ";
	cin >> b;
	if (a > b)
	{
		cout << "Правая граница не должна быть больше левой!" << endl;
		InputValue();
	}
	else 
	{
		cout << "Шаг функции: ";
		cin >> h;
		h = fabs(h);
	}
}

int main()
{
	SetConsoleOutputCP(1251);

	InputValue();
	
	double x = a, y;
	unsigned int count = 0;
	for (a; x < b; h)
	{
		y = pow(tan(log(x)), -2);
		cout << "y["<< count <<"] = " << y << ";" << endl;
		x += h;
		count++;
	}
	system("pause");
	return 0;
}

