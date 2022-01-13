#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include "Triangle.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int count;
	cout << "Кол-во треугольников: ";
	cin >> count;
	
	Triangle triangle = Triangle(count);
	vector<string> msg = triangle.Get();
	string tmp;

	for (int i = 0; i < msg.size(); i++)
	{
		tmp = msg[i];
		for (int j = 1; j < count; j++)
		{
			msg[i] += tmp;
		}
		cout << msg[i] << endl;
	}

	

	system("pause");
	return 0;
}