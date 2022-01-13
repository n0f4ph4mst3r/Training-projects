#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	string FIO, group, tmp;
	cout << "Введите имя студента: ";
	cin >> FIO;
	cout << "Введите фамилию студента: ";
	cin >> tmp;
	FIO += " " + tmp;
	cout << "Введите отчество студента: ";
	cin >> tmp;
	FIO += " " + tmp;
	cout << "Введите номер группы студента: ";
	cin >> group;
	//создание формы
	string field[5];
	field[1] = "*Лабораторная работа №1";
	field[2] = "*Выполнил(а): ст. гр. " + group;
	field[3] = "*" + FIO;
	//ищем наибольшую строку
	int maxindex = 1;
	for (int i = 2; i < 4; i++) {
		if (field[maxindex].length() < field[i].length())
		maxindex = i;
	}
	//'выравниваем' строки
	for (int i = 1; i < 4; i++) {
		if (i != maxindex) {
			while (field[maxindex].length() > field[i].length())
			{
				field[i] += " ";
			}
		}
		field[i] += "*";
	}
	while (field[maxindex].length() > field[0].length())
	{
		field[0] += "*";
	}
	field[4] = field[0];
	//выводим результат
	for (int i = 0; i < 5; i++) {
		cout << "                   " << field[i] << endl;
	}
	system("pause");
	return 0;
}