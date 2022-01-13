#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	unsigned int n;
	cout << "Введите размер массива: ";
	cin >> n;

	double *source = new double[n];
	cout << "Ваш массив: ";
	source[0] = rand();
	cout << source[0];

	double sum = 0;
	for (int i = 1; i < n; i++) {
		source[i] = rand();
		cout << ", " << source[i];
		if (fabs(source[i]))
			sum += pow(source[i], 2);
	}
	cout << endl;

	cout << "Сумма: " << sum << endl;

	system("pause");
	return 0;
}