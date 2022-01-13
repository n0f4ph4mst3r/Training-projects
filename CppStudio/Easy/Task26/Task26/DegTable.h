#pragma once
#include <vector>
#include "Cell.h"
#include "Row.h"

class DegTable {
public:
	DegTable(std::vector <int> num);
	std::vector <std::string> Get();
private:
	std::vector <int> num;
	std::vector <int> deg;
	std::vector<std::vector <Cell>> cells;
	std::vector <Row> rows;
	std::vector <std::string> table;
};