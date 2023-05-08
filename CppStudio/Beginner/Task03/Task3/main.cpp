#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
using namespace std;

char ToUpper(char c) {
	return (char)(c - 32);
}

int main() {
	setlocale(LC_ALL, "Russian");
	char ch;
	printf("Введите символ: ");
	cin >> ch;

	if (ch <= 'z' && ch >= 'a') {
		cout << "Результат: " << ToUpper(ch) << endl;
	}
	else printf("Wrong input /n");

	system("pause");
	return 0;
}