#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	string week[7] = { "Понедельник", "Вторник", "Среда","Четверг","Пятница","Суббота", "Воскресенье"};
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << week[i] << endl;
	}
	cout << "Введите номер недели: " << endl;
	unsigned int number;
	cin >> number;

	switch (number) {
	case 1:
		cout << week[0] << endl;
		break;
	case 2:
		cout << week[1] << endl;
		break;
	case 3:
		cout << week[2] << endl;
		break;
	case 4:
		cout << week[3] << endl;
		break;
	case 5:
		cout << week[4] << endl;
		break;
	case 6:
		cout << week[5] << endl;
		break;
	case 7:
		cout << week[6] << endl;
		break;
	default:
		cout << "Такого дня нет" << endl;
		break;
	}
	system("pause");
	return 0;
}