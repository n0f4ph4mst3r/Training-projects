#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {

	SetConsoleOutputCP(1251);

	cout << "Введите двузначное число: ";
	unsigned int num;
	cin >> num;
	int div[2]; 
	div[0] = num / 10;
	div[1] = num % 10;
	if (div[0] > div[1]) {
		cout << div[0] << " - большая цифра" << endl;
		cout << div[1] << " - меньшая цифра" << endl;
	}
	else {
		cout << div[1] << " - большая цифра" << endl;
		cout << div[0] << " - меньшая цифра" << endl;
	}
	system("pause");
	return 0;
}