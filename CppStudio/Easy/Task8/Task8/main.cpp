#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

double Mathpow(double value, unsigned m) {
	double pow = 1;
	for (int i = 0; i < m; i++) {
		pow *= value;
	}
	return pow;
}

int main() {
	SetConsoleOutputCP(1251);

	double z, x = 1.1;
	unsigned int m = 1;
	for (x = -1.1; x < 0.3; x+=0.2) {
		cout << "Вычислено при x = " << x << endl;
		cout << endl;
		for (m = 1; m < 6; m++) {
			z = Mathpow(x, m) * Mathpow(sin(x * m), m);
			cout << "z = " << z << " при m = " << m << endl;
		}
		m = 1;
		cout << endl;
	}
	system("pause");
	return 0;
}
