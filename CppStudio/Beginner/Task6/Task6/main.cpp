#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	string firststr = "                    /";
	string secondstr = "\\";

	//крыша
	while (firststr.length() > 9) {
		cout << firststr;
		secondstr = "  " + secondstr;
		cout << secondstr << endl;
		firststr.erase(1, 1);
	}

	//основание
	cout << "         --------------------------" << endl;
	for (int i = 0; i < 11; i++) {
		cout << "         |                        |" << endl;
	}
	cout << "         --------------------------" << endl;
	system("pause");
	return 0;
}