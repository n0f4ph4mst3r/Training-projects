#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	int x, y;
	SetConsoleOutputCP(1251);

	cout << "X =";
	cin >> x;
	cout << "Y = ";
	cin >> y;
	if (x * y != 0) {
		if (x > 0 && y > 0)
			cout << "I четверть" << endl;
		if (x < 0 && y > 0)
			cout << "II четверть" << endl;
		if (x < 0 && y < 0)
		    cout << "III четверть" << endl;
		if (x > 0 && y < 0)
			cout << "IV четверть" << endl;
	}
	else cout << "Точка на координатной прямой" << endl;
	system("pause");
	return 0;
}