#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	cout << "Количество иксов: ";
	int length;
	cin >> length;
	//создаем массивы
	double* z = new double[length];
	double* a = new double[length];
	double* b = new double[length];
	double* betta = new double[length];
	double* x = new double [length];
	double y = 0;

	for (int i = 0; i < length; i++) {
		cout << "Введите значения Z, A, B, Betta для x" << i+1 << ":" << endl;

		cout << "Z = ";
		cin >> z[i];

		cout << "A = ";
		cin >> a[i];

		cout << "B = ";
		cin >> b[i];

		cout << "Betta = ";
		cin >> betta[i];

		x[i] = pow(z[i], 3) - b[i] + pow(a[i], 2)/pow(betta[i], 2);
		y += x[i];
	}
	cout << "y = " << y << endl;
	system("pause");
	return 0;
}