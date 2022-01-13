#include "DegTable.h"
#include "Cell.h"
#include <vector>

MultiTable:: MultiTable(std::vector <int> num, int multiplier) //здесь рисуется таблица путём слияния строк
{
	    this->num = num;
		for (int i = 0; i < this->num.size(); i++)
		{
			result.push_back(this->num[i] * multiplier); //находим результат умножения
			cells.push_back({Cell (this->num[i]), Cell (result[i])}); //создаем вектор "ячеек" с полученными значениями
		}

		for (auto row : cells)
		{
			rows.push_back(Row(row)); //из полученного векторов ячеек создаем вектор "строк"
		}

		std::vector <std::string> string_tmp;
		//рисуем шапку таблицы
		string_tmp = rows[0].Get();
		table.push_back(string_tmp[0]);
		table.push_back("|x    |x*"+ std::to_string(multiplier));
		while (table[1].size() < 12)
		{
			table[1] += " ";
		}
		table[1] += '|';
		table.push_back(string_tmp[2]);

		//непосредственно таблица
		for (int i = 0; i < this->rows.size(); i++)
		{
				string_tmp = rows[i].Get();
				table.push_back(string_tmp[1]);
				table.push_back(string_tmp[2]);
		}
};

std::vector <std::string> MultiTable::Get()
{
	return table;
}