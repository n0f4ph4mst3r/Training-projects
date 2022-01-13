#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <iomanip>

using namespace std;

float GetAvg(std::vector <float> arr, unsigned int size) 
{
	float avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += arr[i];
	}

	avg /= size;
	return avg;
}

int main()

{
	SetConsoleOutputCP(1251);
	srand(time(0));

	unsigned int size;

	cout << "Размер массива: ";
	cin >> size;

	std::vector <float> arr(size);

	cout << "Массив: " << endl;
	float range = 100.00;
	for (int i = 0; i < size; i++)
	{
		arr[i] = (float(rand())/float(RAND_MAX))*range;
		cout << arr[i] << "  ";
	}
	cout << endl;

	cout << "Среднее ариметическое: " << GetAvg(arr, size) << endl;

	system("pause");
	return 0;
}