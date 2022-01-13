#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include "DegTable.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int multiplier;

	cout << "Введите число: ";
	cin >> multiplier;

	cout << "Таблица умножения" << endl;
	cout << "-----------------" << endl;

	std::vector <std::string> table;
	MultiTable table_multi = MultiTable({ 1,2,3,4,5,6,7,8,9,10}, multiplier);
	table = table_multi.Get();

	for (auto str : table)
	{
		cout << str << endl;
	}

	system("pause");
	return 0;
}