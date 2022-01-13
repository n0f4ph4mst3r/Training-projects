#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	unsigned int N, k;
	SetConsoleOutputCP(1251);

	cout << "Введите число элементов N: ";
	cin >> N;
	cout << "Введите степень k: ";
	cin >> k;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += pow(i + 1, k);
	}
	cout << "Алгебраическая сумма: " << sum << endl;
	system("pause");
	return 0;
}
