#pragma once
#include <vector>
#include "Cell.h"
#include "Row.h"

class MultiTable {
public:
	MultiTable(std::vector <int> num, int multiplier);
	std::vector <std::string> Get();
private:
	std::vector <int> num;
	std::vector <int> result;
	std::vector<std::vector <Cell>> cells;
	std::vector <Row> rows;
	std::vector <std::string> table;
};