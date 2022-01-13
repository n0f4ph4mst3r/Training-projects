#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	cout << "Введите число: ";
	double num;
	std::string msg = "Число целое.";

	try 
	{
		cin >> num;
		if (num - int(num) != 0)
		{
			msg = "Число не целое!";
			throw msg;
		}
		else
		cout << msg << endl;
	}
	catch (std::string msg)
	{
		cout << msg << endl;
	}
	system("pause");
	return 0;
}