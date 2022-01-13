#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int count = 1;
	string text = "Я\nтвою мамашу\nв кино водил\nАХХАХХАХАХАХХАХХАХА";
	cout << text << endl;

	for (int i = 0; i < text.length(); i++) {
		if (text[i] == '\n')
			count++;
	}

	cout << "Количество строк: " << count << endl;
 	system("pause");
	return 0;
}