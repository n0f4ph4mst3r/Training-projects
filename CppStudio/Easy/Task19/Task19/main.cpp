#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>

using namespace std;

int main() 
{
	SetConsoleOutputCP(1251);

	int num;

	cout << "Введеите число: ";
	cin >> num;

	string tmp = to_string(num);

	if (tmp.length() == 5) 
	{
		int k, m;
		for (int i = 0; i < ceil(tmp.length()); i++)
		{
			if ((int)tmp[i] != (int)tmp[tmp.length() - i - 1])
			{
				cout << "Число не является палиндромом" << endl;
				system("pause");
				return 0;
			}
		}
		
		cout << "Число является палиндромом" << endl;
	}
	else
	{
		cout << "Число должно быть пятизначным!" << endl;
	}


	system("pause");
	return 0;
}