#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include "DegTable.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	cout << "Таблица квадратов" << endl;
	cout << "-----------------" << endl;

	std::vector <std::string> table;
	DegTable table_deg = DegTable({ 1,2,3,4,5 });
	table = table_deg.Get();

	for (auto str : table)
	{
		cout << str << endl;
	}

	system("pause");
	return 0;
}