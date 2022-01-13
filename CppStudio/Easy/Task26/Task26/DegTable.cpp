#include "DegTable.h"
#include "Cell.h"
#include <vector>

DegTable:: DegTable(std::vector <int> num) //здесь рисуется таблица путём слияния строк
{
	    this->num = num;
		for (int i = 0; i < this->num.size(); i++)
		{
			deg.push_back(pow(this->num[i], 2)); //находим квадраты
			cells.push_back({Cell (this->num[i]), Cell (deg[i])}); //создаем вектор "ячеек" с полученными значениями
		}

		for (auto row : cells)
		{
			rows.push_back(Row(row)); //из полученного векторов ячеек создаем вектор "строк"
		}

		std::vector <std::string> string_tmp;
		//рисуем шапку таблицы
		string_tmp = rows[0].Get();
		table.push_back(string_tmp[0]);
		table.push_back("|x    |x^2  |");
		table.push_back(string_tmp[2]);

		//непосредственно таблица
		for (int i = 0; i < this->rows.size(); i++)
		{
				string_tmp = rows[i].Get();
				table.push_back(string_tmp[1]);
				table.push_back(string_tmp[2]);
		}
};

std::vector <std::string> DegTable::Get()
{
	return table;
}