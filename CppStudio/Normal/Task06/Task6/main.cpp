#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "InputValue.h"
#include <vector>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	InputValue<unsigned>* uintInput = new InputValue<unsigned>();
	uintInput->SetMessage("Размер массива: ");
	unsigned size = uintInput->GetValue();

	std::vector<std::vector<unsigned>> arr;
	arr.resize(size);
	for (unsigned i = 0; i < size; ++i) arr[i].resize(size);
	
	unsigned count = 1;
	unsigned n = 0;
	unsigned k = 0;
	unsigned* nptr = &n;
	unsigned* kptr = &k;

	//заполняем матрицу с начала главной с диагонали
	for (unsigned i = 0; i < size; ++i) {
		n = i;
		for (k = 0; k < i+1; ++k) {
			arr[*nptr][*kptr] = count;
			--n;
			++count;
		}
		std::swap(nptr, kptr);
	}

	//заполняем матрицу с конца главной с диагонали
	count = size * size;
	for (unsigned i = size - 1; i > 0; --i) {
		n = i;
		for (k = size - 1; k > i - 1; --k) {
			arr[*nptr][*kptr] = count;
			++n;
			--count;
		}
		std::swap(nptr, kptr);
	}

	

	cout << "Результат:\r\n";
	for (unsigned i = 0; i < size; ++i) {
		for (unsigned j = 0; j < size; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}