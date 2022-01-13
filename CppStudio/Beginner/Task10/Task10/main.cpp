#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num[3];
	cout << "Первое число: ";
	cin >> num[0];
	cout << "Второе число: ";
	cin >> num[1];
	cout << "Третье число: ";
	cin >> num[2];
	bool equal = false;
	int next;
	//ищем равные числа
	for (int i = 0; i < 2; i++) {
		next = i++;
		while (next < 3) {
			if (num[i] == num[next]) {
				equal = true;
				break;
			}
			next++;
		}
		if (equal == true)
			break;
	}
	//выводим результат
	if (equal) {
		for (int i = 0; i < 3; i++) {
			num[i] += 5;
			switch (i) {
			case 0:
				cout << "1 число: " << num[i] << endl;
				break;
			case 1:
				cout << "2 число: " << num[i] << endl;
				break;
			case 2:
				cout << "3 число: " << num[i] << endl;
				break;
			default:
				break;
			}
		}
	}
	else cout << "Нет равных" << endl;
	system("pause");
	return 0;
}