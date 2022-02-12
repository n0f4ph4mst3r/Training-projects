#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <sstream>
#include "InputValue.h"

using namespace std;


int main() {
	SetConsoleOutputCP(1251);

    cout << "Статический массив\r\n";

	int matrix[100][100];
	int vec[100];

	int result[100];
    for (int i = 0; i < 100; ++i) {
        result[i] = 0;
    }

    unsigned matrixRows;
    unsigned matrixColumns;

    InputValue<unsigned>* UnsignedInput = new InputValue<unsigned>();
    InputValue<int>* IntInput = new InputValue<int>();

    //параметры для матрицы и вектора
    UnsignedInput->SetMax(100);
    UnsignedInput->SetMessage("Количество строк матрицы: ");
    matrixRows = UnsignedInput->GetValue();

    UnsignedInput->SetMessage("Количество столбцов матрицы: ");
    matrixColumns = UnsignedInput->GetValue();
     
    //значения матрицы
    for (unsigned j = 0; j < matrixRows; ++j) {
        for (unsigned i = 0; i < matrixColumns; ++i) {
            IntInput->SetMessage("Элемент матрицы [" + to_string(i) + "][" + to_string(j) + "] = ");
            matrix[i][j] = IntInput->GetValue();
        }
    }

    //значения вектора
    for (unsigned i = 0; i < matrixColumns; ++i) {
        IntInput->SetMessage("Элемент вектора [" + to_string(i) + "] = ");
        vec[i] = IntInput->GetValue();
    }
    cout << endl;

    //умножаем матрицу на вектор
    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixColumns; ++j) {
            result[i] += matrix[j][i] * vec[j];
        }
    }

    //находим максимальное значение
    int max = result[0];
    for (int i = 1; i < matrixRows; ++i) {
        if (max < result[i]) max = result[i];
    }

    //вывод результата
    cout << "Матрица:\n";
    for (unsigned j = 0; j < matrixRows; ++j) {
        for (unsigned i = 0; i < matrixColumns; ++i) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Вектор:\n";
    for (int i = 0; i < matrixColumns; ++i) {
        cout << vec[i] << endl;
    }

    cout << "Результат:\n";
    for (int i = 0; i < matrixRows; ++i) {
        cout << result[i] << endl;
    }

    cout << "Максимальное значение:\n";
    cout << max << endl;

	system("pause");
	return 0;
}


