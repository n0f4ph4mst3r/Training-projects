#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	string str="+";
	cout << str << endl;
	for (int i = 0; i < 7; i++) {
		str += "+";
		cout << str << endl;
	}
	system("pause");
	return 0;
}