#pragma once
#include <string>
class Worker {
public:
	Worker(const std::string& n, const unsigned int e, const unsigned int hW, const unsigned int h);
	std::string GetName();
	unsigned int GetExp();
	unsigned int GethWage();
	unsigned int Gethours();
	unsigned int GetSalary();
	unsigned int GetPremy();
private:
	std::string name;
	unsigned int exp;
	unsigned int hWage;
	unsigned int hours;
	unsigned int salary;
	unsigned int premy;
};