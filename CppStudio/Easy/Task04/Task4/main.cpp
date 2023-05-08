#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	double V, t, alpha;
		cout << "Скорость: ";
		cin >> V;
		cout << "Время: ";
		cin >> t;

	alpha = asin((9.8 * t) / (2 * V));
	cout << "Угол равен: " << alpha << endl;

	system("pause");
	return 0;
}