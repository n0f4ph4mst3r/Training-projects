#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	srand(time(0));

	unsigned int n = 1 + rand(); //количество псевдослучайных чисел
	int *y = new int[n];
	double *x = new double[n]; 
	const int m = rand(), // диапазон 
		a = rand() % m, // множитель 
		inc = rand() % m, // инкрементирующее значение 
		x0 = rand() % m; // начальное значение
	y[0] = (a * x0 + inc) % m;
	x[0] = y[0]/double(m);

	cout << "Множитель: " << a << endl;
	cout << "Диапозон: " << m << endl;
	cout << "Инкремент: " << inc << endl;
	cout << "Начальное значение: " << x0 << endl;
	cout << "Количество чисел: " << n << endl;

	cout << "Результат: " << x[0];
	for (unsigned int i = 1; i < n; i++) {
		y[i] = fmod((a * y[i-1] + inc), m);
		x[i] = y[i]/double(m);
		cout << ", " << x[i];
	}
	cout << "\n";
	system("pause");
	return 0;
}


