#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <sstream>
#include "InputValue.h"

using namespace std;


int main() {
    SetConsoleOutputCP(1251);

    cout << "������������ ������ ����� �������\r\n";

    unsigned matrixRows;
    unsigned matrixColumns;

    InputValue<unsigned>* UnsignedInput = new InputValue<unsigned>();
    InputValue<int>* IntInput = new InputValue<int>();

    //��������� ��� ������� � �������
    UnsignedInput->SetMessage("���������� ����� �������: ");
    matrixRows = UnsignedInput->GetValue();

    UnsignedInput->SetMessage("���������� �������� �������: ");
    matrixColumns = UnsignedInput->GetValue();

    int** matrix = new int* [matrixRows];
    for (int i = 0; i < matrixRows; ++i)
        matrix[i] = new int[matrixColumns];

    //�������� �������
    for (unsigned j = 0; j < matrixRows; ++j) {
        for (unsigned i = 0; i < matrixColumns; ++i) {
            IntInput->SetMessage("������� ������� [" + to_string(i) + "][" + to_string(j) + "] = ");
            matrix[j][i] = IntInput->GetValue();
        }
    }

    //�������� �������
    int* vec = new int[matrixColumns];
    for (unsigned i = 0; i < matrixColumns; ++i) {
        IntInput->SetMessage("������� ������� [" + to_string(i) + "] = ");
        vec[i] = IntInput->GetValue();
    }
    cout << endl;

    //�������� ������� �� ������
    int* result = new int[matrixRows];
    for (int i = 0; i < matrixRows; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixColumns; ++j) {
            result[i] += *((*(matrix + i)) + j) * *(vec + j);
        }
    }

    //������� ������������ ��������
    int max = result[0];
    for (int i = 1; i < matrixRows; ++i) {
        if (max < result[i]) max = result[i];
    }

    //����� ����������
    cout << "�������:\n";
    for (unsigned j = 0; j < matrixRows; ++j) {
        for (unsigned i = 0; i < matrixColumns; ++i) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    cout << "������:\n";
    for (int i = 0; i < matrixColumns; ++i) {
        cout << vec[i] << endl;
    }

    cout << "���������:\n";
    for (int i = 0; i < matrixRows; ++i) {
        cout << result[i] << endl;
    }

    cout << "������������ ��������:\n";
    cout << max << endl;

    system("pause");
    return 0;
}