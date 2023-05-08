#include <iostream>
#include <cstdlib>
#include <vector>
#include <Windows.h>
#include "InputValue.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	unsigned size = 0;
	int* arr = new int[1];

	while (true) {
		InputValue<int> *input = new InputValue<int>();
		int value;

		cout << "Введите элемент массив: ";
		value = input->GetValue();
		if (value < 0) break;

		else if (value > 0) {
			int* buffer;
			++size;
			buffer = new int[size];
			for (int i = 0; i < size - 1; ++i) {
				buffer[i] = std::move(arr[i]);
			}
			buffer[size - 1] = value;
			delete [] arr;

			arr = new int[size];
			for (int i = 0; i < size; ++i) {
				arr[i] = std::move(buffer[i]);
			}
			delete [] buffer;
		}

		cout << "Массив:\r\n";
	    
		for (int i = 0; i < size; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}