#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	double x = rand() % 361;
	double y = rand() % 361;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	double result;
	result = pow(1 - tan(x), 1 / tan(x)) + cos(x - y);
	cout << "Результат: " << result << endl;
	system("pause");
	return 0;
}