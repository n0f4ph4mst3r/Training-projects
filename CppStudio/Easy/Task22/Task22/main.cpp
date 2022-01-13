#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <vector>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(0));

	unsigned int length, width, size;

	cout << "Длина: ";
	cin >> length;

	cout << "Ширина: ";
	cin >> width;

	if (length <= width) size = length;
	else size = width;

	unsigned int index = 0;
	double sum = 0;

	std::vector<std::vector<int>> matrix(length, std::vector<int>(width));
	cout << "Матрица: " << endl;
	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			matrix[i][j] = rand() % 100;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	while (index != size) 
	{
		sum += matrix[index][index];
		index++;
	}

	cout << "Сумма элементов главной диагонали: " << sum << endl;

	system("pause");
	return 0;
}
