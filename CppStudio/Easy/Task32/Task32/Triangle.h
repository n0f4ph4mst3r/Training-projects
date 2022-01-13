#pragma once
#include <vector>
#include <string>
class Triangle
{
public:
	std::vector<std::string> Get();
	Triangle(int height);
private:
	std::vector<std::string> triangle;
};