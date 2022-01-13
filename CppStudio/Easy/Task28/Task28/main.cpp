#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

void Input(double* a, double* b, double* c, double* d, double* k);
int equation_type (double a, double b, double c);

int main()
{
	SetConsoleOutputCP(1251);

	double a, b, c, d, k;
	double* a_ptr = &a;
	double* b_ptr = &b;
	double* c_ptr = &c;
	double* d_ptr = &d;
	double* k_ptr = &k;

	Input(a_ptr, b_ptr, c_ptr, d_ptr, k_ptr);

	b = b - d;
	c = c - k;
	
	std::string msg;
	std::vector <double> x_points;
	std::vector <double> y_points;
	double disc;

	switch (int type = equation_type(a, b, c))
	{
    //для квадратного ур-ия
	case (1):
		//дискриминант
		disc = -pow(b, 2) - a * c;
		if (disc < 0) msg = "Уравнения не имеют общих точек.";
		else 
		{
			//находим x
			x_points.push_back((-b + sqrt(disc)) / a);
			if (disc != 0) x_points.push_back((-b - sqrt(disc)) / a);
			//находим y
			for (auto x : x_points)
			{
				y_points.push_back(d * x + k);
			}

			if (x_points.size() == 1) msg = "Координаты точки пересечения: [" + std::to_string(x_points[0]) + ", " + std::to_string(y_points[0]) + "].";
			else
			{
				msg = "Координаты точек пересечения: ";
				for (int i = 0; i < x_points.size(); i++)
				{
					msg += "[" + std::to_string(x_points[i]) + ", " + std::to_string(y_points[i]) + "]";
					if (i == x_points.size() - 1) msg += ".";
					else msg += ",";
				}
			}
		}
		break;
	//для линейного ур-ия
	case(2):
		x_points.push_back(-b/c);
		y_points.push_back(x_points[0] * b + c);

		msg = "Координаты точки пересечения: [" + std::to_string(x_points[0]) + ", " + std::to_string(y_points[0]) + "].";
		break;
	default:
		msg = "Уравнения не имеют общих точек.";
		break;
	}

	cout << msg << endl;

	system("pause");
	return 0;
}

void Input(double* a, double* b, double* c, double* d, double* k)
{
	std::string msg;
	try
	{
		cout << "y = ax^2+bx+c - первое ур-ие." << endl;

		cout << "Введите коэффициент a: " << endl;
		cout << "a = ";
		cin >> *a;

		cout << "Введите коэффициент b: " << endl;
		cout << "b = ";
		cin >> *b;

		cout << "Введите коэффициент c: " << endl;
		cout << "c = ";
		cin >> *c;

		cout << "y = dx+k - второе ур-ие." << endl;

		cout << "Введите коэффициент d: " << endl;
		cout << "d = ";
		cin >> *d;

		cout << "Введите коэффициент k: " << endl;
		cout << "k = ";
		cin >> *k;
		
		if (*a == 0 && *b == 0 && *d == 0) throw msg = "Коэффициенты не могуть быть равны 0!";
	}
	catch (std::string err)
	{
		cout << err << endl;
		cout << endl;
		Input(a, b, c, d, k);
	}
}

int equation_type(double a, double b, double c)
{
	if (a != 0) return 1;

	if (a == 0 && b != 0) return 2;

	return 0;
}