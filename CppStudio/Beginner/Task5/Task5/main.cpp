#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n[2][9] = {
                     {201,203,203,203,203,203,203,203,187}, 
                 {200,202,202,202,202,202,202,202,188}
    };
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 9; j++) cout << static_cast<char>(n[i][j]); 
        cout << endl;
    };
    cin.get();
	system("pause");
	return 0;
}