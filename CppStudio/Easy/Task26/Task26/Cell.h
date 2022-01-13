#pragma once
#include <vector>
#include <string>

class Cell //здесь рисуем "ячейки"
{
private:
	int value; //значение
	std::vector <std::string> cell; //непосредственно ячейка
	std::string str, line = ""; //строка с значением и линия таблицы
public:
	Cell(int value);
	std::vector<std::string> Get();
};