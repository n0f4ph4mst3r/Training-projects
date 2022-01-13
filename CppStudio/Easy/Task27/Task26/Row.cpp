#include <vector>
#include <string>
#include "Row.h"
#include "Cell.h"

Row::Row(std::vector<Cell> cells)
{
	std::vector <std::string> tmp;
	for (int i = 0; i < cells.size(); i++)
	{
		tmp = cells[i].Get();

		if (line != "") line += tmp[0].substr(1);
		else line = tmp[0];

		if (str != "") str += tmp[1].substr(1);
		else str = tmp[1];
	}
	row = { line, str, line };
}

std::vector<std::string> Row::Get()
{
	return row;
}