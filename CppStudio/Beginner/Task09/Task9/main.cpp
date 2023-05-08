#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "1 число: ";
	cin >> a;
	cout << "2 число ";
	cin >> b;
	if (a > b)
		cout << "Больше" << endl;
	if (a < b)
		cout << "Меньше" << endl;
	if (a == b)
		cout << "Равны" << endl;
	system("pause");
	return 0;
}