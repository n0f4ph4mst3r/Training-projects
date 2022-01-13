#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int num;
	cout << "Введите номер символа: ";
	cin >> num;
	cout << endl;

	char sym;
	switch (num)
	{
	case 1:
		sym = '*';
		break;
	case 2:
		sym = '+';
		break;
	case 3:
		sym = '#';
		break;
	default:
		cout << "Неверный номер" << endl;
		system("pause");
		return 0;
	}

	unsigned int height, width;
	cout << "Высота ромба: ";
	cin >> height;
	cout << "Ширина ромба: ";
	cin >> width;
	cout << endl;

	unsigned int point = ceil((double)width / 2) - 1;

	vector<vector<char> > romb(height, vector<char>(width, ' '));

		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
			   if (i == point)
			   {
				   romb[j][i] = romb[height - j - 1][i] = romb[j][width - i - 1] = romb[height - j - 1][width - i - 1] = sym;
				   point--;
			   }
			   cout << romb[j][i];
		    }
			cout << endl;
	    }

	system("pause");
	return 0;
}