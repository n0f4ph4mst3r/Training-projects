#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <sstream>
#include "InputValue.h"

using namespace std;


int main() {
	SetConsoleOutputCP(1251);

    cout << "����������� ������\r\n";

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

    //��������� ��� ������� � �������
    UnsignedInput->SetMax(100);
    UnsignedInput->SetMessage("���������� ����� �������: ");
    matrixRows = UnsignedInput->GetValue();

    UnsignedInput->SetMessage("���������� �������� �������: ");
    matrixColumns = UnsignedInput->GetValue();
     
    //�������� �������
    for (unsigned j = 0; j < matrixRows; ++j) {
        for (unsigned i = 0; i < matrixColumns; ++i) {
            IntInput->SetMessage("������� ������� [" + to_string(i) + "][" + to_string(j) + "] = ");
            matrix[i][j] = IntInput->GetValue();
        }
    }

    //�������� �������
    for (unsigned i = 0; i < matrixColumns; ++i) {
        IntInput->SetMessage("������� ������� [" + to_string(i) + "] = ");
        vec[i] = IntInput->GetValue();
    }
    cout << endl;

    //�������� ������� �� ������
    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixColumns; ++j) {
            result[i] += matrix[j][i] * vec[j];
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
            cout << matrix[i][j] << " ";
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


