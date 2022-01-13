#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <algorithm>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	double block[3];
	double window[2];

	cout << "-----------Введите габариты кирпича--------------" << endl;
	cout << "Длина: ";
	cin >> block[0];
	cout << "Ширина: ";
	cin >> block[1];
	cout << "Высота: ";
	cin >> block[2];
	reverse(begin(block), end(block));

	cout << "-----------Введите габариты окна----------------" << endl;
	cout << "Длина: ";
	cin >> window[0];
	cout << "Ширина: ";
	cin >> window[1];
	reverse(begin(window), end(window));

	if ((block[0] <= window[0] && block[1] <= window[1]) || (block[0] <= window[0] && block[2] <= window[1]) || (block[1] <= window[0] && block[2] <= window[1]))
		cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}