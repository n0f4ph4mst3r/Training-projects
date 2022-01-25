#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

unsigned Input();

int main() {
	SetConsoleOutputCP(1251);

    unsigned count = Input();

    double fraction = 1;
    for (unsigned i = 0; i < count; i++) {
        fraction = 1 + 1 / fraction;
    }

    cout << fraction << endl;

	system("pause");
	return 0;
}

unsigned Input() {
    unsigned value;
    while (true) {
        std::cout << "How much?: ";
        std::cin >> value;

        if (std::cin.fail()) {
            cin.clear();
            cin.ignore(UINT_MAX, '\n');
            cout << "That input is invalid.\n";
        }
        else {
            cin.ignore(UINT_MAX, '\n');
            return value;
        }
    }
}
