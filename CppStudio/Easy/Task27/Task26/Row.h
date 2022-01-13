#pragma once
#include <vector>
#include <string>
#include "Cell.h"

class Row //здесь рисуем здесь рисуем "строки" путем слияния ячеек
{
private:
	std::vector<std::string> row; //непосредственно строка 
	std::string str, line = ""; //значения строки и линия таблицы
public:
	Row(std::vector<Cell> cells);
	std::vector<std::string> Get();
};

