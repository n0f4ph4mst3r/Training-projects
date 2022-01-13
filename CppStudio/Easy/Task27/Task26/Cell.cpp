#include "Cell.h"

Cell::Cell(int value)
{
	this->value = value;
	str = '|' + std::to_string(value);

	while (str.length() < 6)
	{
		str += ' ';
	}
	str += '|';

	line = std::string(str.length(), '-');

	cell = { line, str, line };
}

std::vector<std::string> Cell::Get()
{
	return cell;
};


