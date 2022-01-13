#include <iostream>
#include <cstdlib>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, f;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "f = ";
	cin >> f;

	double result;
	result = (a + b - f / a) + f * pow(a,2) - (a + f);

	cout << "Результат: " << result << endl;
	system("pause");
	return 0;
}