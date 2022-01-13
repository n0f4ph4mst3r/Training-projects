#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	int value, div, multiplier = 10;

	cout << "Введите число: ";
	cin >> value;

	//заносим в вектор значения разрядов
	vector<int> numbers;
	while (value != 0) {
		div = value % multiplier;
		numbers.push_back(div);
		value /= multiplier;
	}

	unsigned int num_check[10]; //в массив заносим количество совпадений с текущей цифрой
	for (int i = 0; i < 10; i++) {
		num_check[i] = 0; //по умолчанию все значения равны 0
	}

	unsigned int count = 0; //счетчик совпадений
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < numbers.size(); j++) {
			if (i == numbers[j]) { //если значение вектора равно текущей цифре
				num_check[i]++; //инкрементируем значение в массиве для этой цифры
			}
		}
		if (num_check[i] >= 2) {
			count += num_check[i]-1; //инкрементируем счетчик если количество совпадений больше или равно 2
		}
	}
	if (count != 0) {
		cout << "Общее количество совпадений - " << count << endl;
		for (int i = 0; i < 9; i++) {
			if (num_check[i] >= 2) {
				cout << --num_check[i] << " для цифры " << i << endl;
			}
		}
	}
	else cout << "Совпадений не обнаружено" << endl;

	system("pause");
	return 0;
}