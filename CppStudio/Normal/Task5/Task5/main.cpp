#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "InputValue.h"

using namespace std;

struct Person {
	int number;
	std::string name;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Person* arr = new Person[1];
	unsigned size = 0;

	while (true) {
		++size;
		Person* temp = new Person[size];
		for (int i = 0; i < size - 1; ++i) {
			temp[i] = std::move(arr[i]);
		}

		delete[] arr;
		arr = new Person[size];

		for (int i = 0; i < size - 1; ++i) {
			arr[i] = std::move(temp[i]);
		}
		delete[] temp;

		cout << "Имя: ";
		cin >> arr[size - 1].name;

		InputValue<int>* inputINT = new InputValue<int>();
		inputINT->SetMessage("Возраст: ");

		arr[size - 1].number = inputINT->GetValue();

		cout << "Элементы структуры:\r\n";
		for (int i = 0; i < size; ++i) {
			cout << arr[i].name << " " << arr[i].number << endl;
		}

		std::string run;
		cout << "Продолжнить?(y/n): ";
		cin >> run;

		if (run == "n" || run == "N") {
			break;
		}
		else continue;
	}

	system("pause");
	return 0;
}

	