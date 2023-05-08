#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <sstream>
#include "InputValue.h"

using namespace std;


int main() {
    SetConsoleOutputCP(1251);

    cout << "Динамический массив через индексы\r\n";

    unsigned matrixRows;
    unsigned matrixColumns;

    InputValue<unsigned>* UnsignedInput = new InputValue<unsigned>();
    InputValue<int>* IntInput = new InputValue<int>();

    //параметры для матрицы и вектора
    UnsignedInput->SetMessage("Количество строк матрицы: ");
    matrixRows = UnsignedInput->GetValue();

    UnsignedInput->SetMessage("Количество столбцов матрицы: ");
    matrixColumns = UnsignedInput->GetValue();

    int** matrix = new int* [matrixRows];
    for (int i = 0; i < matrixRows; ++i)
        matrix[i] = new int[matrixColumns];

    //значения матрицы
    for (unsigned j = 0; j < matrixRows; ++j) {
        for (unsigned i = 0; i < matrixColumns; ++i) {
            IntInput->SetMessage("Элемент матрицы [" + to_string(i) + "][" + to_string(j) + "] = ");
            matrix[j][i] = IntInput->GetValue();
        }
    }

    //значения вектора
    int* vec = new int[matrixColumns];
    for (unsigned i = 0; i < matrixColumns; ++i) {
        IntInput->SetMessage("Элемент вектора [" + to_string(i) + "] = ");
        vec[i] = IntInput->GetValue();
    }
    cout << endl;

    //умножаем матрицу на вектор
    int* result = new int[matrixRows];
    for (int i = 0; i < matrixRows; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixColumns; ++j) {
            result[i] += *((*(matrix + i)) + j) * *(vec + j);
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
            cout << matrix[j][i] << " ";
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