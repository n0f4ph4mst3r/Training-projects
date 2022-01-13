#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int meters;
	cout << "Метры: ";
	cin >> meters;

	int miles;
	miles = meters / 1000;

	cout << "Километры: " << miles << endl;

	system("pause");
	return 0;
}