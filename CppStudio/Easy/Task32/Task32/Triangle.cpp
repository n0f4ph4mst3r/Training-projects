#include "Triangle.h"
#include <vector>
#include <string>

Triangle::Triangle(int height)
{
	std::string star = "*", str = star, tmp;
	//строим основание треугольника
	for (int i = 0; i < height; i++)
	{
		str = "*" + str + "*";
	}
	//строим треугольник
	while (star != str)
	{
		tmp = star;
		while (tmp.length() < str.length())
		{
			tmp = " " + tmp + " ";
		}
		triangle.push_back(tmp);
		star = "*" + star + "*";
	}

}

std::vector<std::string> Triangle::Get()
{
	return triangle;
}