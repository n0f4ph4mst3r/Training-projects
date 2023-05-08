#include <iostream>
#include <cstdlib>
#include <fstream>
#include <Windows.h>

using namespace std; 

void fileOpen(std::string fileName);

int main() {
	SetConsoleOutputCP(1251);

	ofstream cleaner;
	cleaner.open("..\\Task1\\output.txt", std::ofstream::out, std::ofstream::trunc);
	cleaner.close();

	fileOpen("..\\samplesC\\HelloWorld.c");
	fileOpen("..\\samplesC\\fibonachi.c");
	fileOpen("..\\samplesC\\sumC.c");

	system("pause");
	return 0;
}

void fileOpen(std::string fileName) {
	ofstream fout("..\\Task1\\output.txt", ios_base::app);
	cout << "Файл - " + fileName + "\n";
	fout << "Файл - " + fileName + "\n";
	fout.close();

	ifstream fin(fileName);
	try {
		const std::string errorMsg = "Не удается открыть файл!\n";
		if (!fin.is_open()) {
			fin.close();
			throw errorMsg;
		}
	}
	catch (std::string msg) {
		cout << msg;
		fout.open("..\\Task1\\output.txt", ios_base::app);
		fout << msg;
		fout.close();
		return;
	}

	unsigned counterLeftBracket = 0;
	unsigned counterRightBracket = 0;
	char symbol;
	fin >> symbol;

	try {
		const std::string errorMsg = "Баланс скобок нарушен!\n";
	while (fin) {
		if (symbol == '{') counterLeftBracket++;
		if (symbol == '}')
		{
	        counterRightBracket++;
			if (counterLeftBracket < counterRightBracket) throw errorMsg;
		}
		fin >> symbol;
		}
	if (counterLeftBracket != counterRightBracket) {
		fin.close();
		throw errorMsg;
	}
	}
	catch (std::string msg) {
		fout.open("..\\Task1\\output.txt", ios_base::app);
		cout << msg;
		fout << msg;
		fout.close();
		return;
	}
	fin.close();

	fout.open("..\\Task1\\output.txt", ios_base::app);
	cout << "Done!\n";
	fout << "Done!\n";
	fout.close();
}