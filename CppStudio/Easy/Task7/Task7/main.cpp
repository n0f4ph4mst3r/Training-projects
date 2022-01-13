#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	double x, z, y, length;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Z: ";
	cin >> z;
	length = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	cout << "Результат: " << length << endl;
	system("pause");
	return 0;
}