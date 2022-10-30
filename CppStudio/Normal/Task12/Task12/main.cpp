#include <iostream>
#include <Windows.h>
#include <vector>
#include <memory>
#include <wctype.h>
#include <functional>
#include <map>
#include <iomanip>
#include <format>
#include <string>
#include <fstream>

#include "../include/pugixml.hpp"

#include "InputValue.h"

struct Worker {
	std::string firstname;
	std::string middlename;
	std::string lastname;
	std::string post;

	unsigned hpay;
	unsigned hours;
	unsigned salary;
};

using InputChar = InputValue<char>;
using InputUnsigned = InputValue<unsigned>;
using WorkerPtr = std::unordered_map<unsigned, Worker> ::iterator;

namespace filterData
{
	enum SortType {
		QUICK,
		SHELL,
		BUBBLE
	};

	SortType sortType = QUICK;

	std::string firstname = "";
	std::string middlename = "";
	std::string lastname = "";
	std::string post = "";

	unsigned hpay_min = 0;
	unsigned hpay_max = UINT_MAX;

	unsigned hours_min = 0;
	unsigned hours_max = UINT_MAX;

	unsigned salary_min = 0;
	unsigned salary_max = UINT_MAX;
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::unordered_map<unsigned, Worker> workerList;
	std::vector<WorkerPtr> selectedItems;

	std::function<bool()> f_showmenu;
	std::function<std::string(const std::string&, const std::string&)> f_addData;
	std::function<void()> f_sortData;
	std::function<void()> f_createWorker;
	std::function<void(WorkerPtr& it)> f_enterid;
	std::function<void()> f_editData;
	std::function<void()> f_enterFilterData;
	std::function<void()> f_deleteData;
	std::function<void()> f_saveToFile;
	std::function<void()> f_loadFromFile;
	std::function<void()> f_selectSortType;
	std::function<void()> f_showList;

	f_showmenu = [&]() {
		std::unique_ptr<InputChar> pmainMenu = std::make_unique<InputChar>();
		pmainMenu->SetMessage("Выберите действие:\r\nN Добавить работника\r\nE Редактировать запись\r\nF Фильтр\r\nD Удалить запись\r\nS Сохранить в файл\r\nL Загрузить из файла\r\nV Показать записи\r\nC Сортировать\r\nQ Выйти\r\n");
		pmainMenu->SetAllowedValues({'N', 'E', 'F', 'D', 'S', 'L', 'V', 'C', 'Q', 'n', 'e', 'f', 'd', 's', 'l', 'v', 'c', 'q' });
		char selectedOption = pmainMenu->GetValue();

		switch (selectedOption) {
		    case 78: case 110:
				f_createWorker();
			    break;
			case 69: case 101:
				if (workerList.size() > 0) f_editData();
				else std::cout << "Нет записей.\r\n";
				break;
			case 70: case 102:
				f_enterFilterData();
				break;
			case 68: case 100:
				if (workerList.size() > 0) f_deleteData();
				else std::cout << "Нет записей.\r\n";
				break;
			case 83: case 115:
				f_saveToFile();
				break;
			case 76: case 108:
				f_loadFromFile();
				break;
			case 86: case 118:
				f_showList();
				break;
			case 67: case 99:
				f_selectSortType();
				break;
			default: return true;
		}

		return false;
	};

	f_addData = [&](const std::string& msg, const std::string& errormsg) {
		std::cout << msg;
		std::string str;
		while (1) {
			std::cin >> str;
			if (!str[0]) std::cout << "Значение не может быть пустым.\r\n";
			else break;
		}

		for (auto& ch : str) {
			if (!iswalpha(ch) && ch != '\n' && ch != '\0')
			{
				std::cout << errormsg;
				return f_addData(msg, errormsg);
			}
		}

		return str;
	};

	f_sortData = [&]() {
		std::function<bool(const Worker& item)> f_checkItem = [&](const Worker& item) {
			if (filterData::firstname != item.firstname && filterData::firstname != "") return false;
			if (filterData::middlename != item.middlename && filterData::middlename != "") return false;
			if (filterData::lastname != item.lastname && filterData::lastname != "") return false;
			if (filterData::post != item.post && filterData::post != "") return false;

			if (filterData::hpay_min > item.hpay || filterData::hpay_max < item.hpay) return false;
			if (filterData::hours_min > item.hours || filterData::hours_max < item.hours) return false;
			if (filterData::salary_min > item.salary || filterData::salary_max < item.hours) return false;

			return true;
		};

		selectedItems.clear();
		if (workerList.size() > 0) {
			for (auto it = workerList.begin(); it != workerList.end(); ++it) {
				if (f_checkItem(it->second)) selectedItems.push_back(it);
			}

			if (selectedItems.size() == 2) {
				if (selectedItems[0]->first > selectedItems[1]->first) {
					std::swap(selectedItems[0], selectedItems[1]);
				}
			}
			else if (workerList.size() > 2) {
				switch (filterData::sortType) {
				case filterData::QUICK:
				{
					std::function<void(const unsigned, const unsigned)> f_qsort = [&](const unsigned b, const unsigned e) {
						unsigned l = b, r = e;
						unsigned piv = selectedItems[(l + r) / 2]->first;
						while (l < r) {
							while (selectedItems[l]->first < piv) l++;
							while (selectedItems[r]->first > piv) r--;
							std::swap(selectedItems[l], selectedItems[r]);
						}

						if (b < r && r - b > 1) f_qsort(b, r);
						if (e > l && e - l > 1) f_qsort(l, e);
					};

					f_qsort(0, selectedItems.size() - 1);
					break;
				}
				case filterData::SHELL:
				{

					unsigned d = selectedItems.size();
					do {
						d /= 2;
						for (unsigned i = 0; i < d; ++i) {
							std::vector<WorkerPtr> tmp;
							for (unsigned j = i; j < selectedItems.size(); j+= d) {
								tmp.push_back(selectedItems[j]);
							}

							if (tmp.size() >= 2) {
								for (unsigned j = 1; j < tmp.size(); ++j) {
									WorkerPtr value = tmp[j];
									unsigned k;
									for (k = j - 1; tmp[k]->first >= value->first;) {
										std::swap(tmp[k], tmp[k + 1]);
										if (k != 0) --k;
										else break;
									}
								}
							}

							for (unsigned j = 0; j < tmp.size(); ++j) {
								selectedItems[i + j * d] = std::move(tmp[j]);
							}
						}
					} while (d != 1);
					break;
				}
				case filterData::BUBBLE:
				{
					for (unsigned i = 0; i < selectedItems.size(); ++i) {
						for (unsigned prev = 0, next = 1; next < selectedItems.size(); ++prev, ++next) {
							if (selectedItems[prev]->first > selectedItems[next]->first) std::swap(selectedItems[prev], selectedItems[next]);
						}
					}
					break;
				}
				default: break;
				}
			}
		}
	};

	f_createWorker = [&]() {
		std::unique_ptr<Worker> newWorker = std::make_unique<Worker>();

		newWorker->firstname = f_addData("Имя: ", "Некорректное имя.\r\n");
		newWorker->middlename = f_addData("Фамилия: ", "Некорректная фамилия.\r\n");
		newWorker->lastname = f_addData("Отчество: ", "Некорректное отчество.\r\n");

		std::string spost;
		std::cout << "Должность: ";
		std::cin >> spost;
		newWorker->post = std::move(spost);

		std::unique_ptr<InputUnsigned> pvalue = std::make_unique<InputUnsigned>();
		pvalue->SetMessage("Оплата за час: ");
		newWorker->hpay = pvalue->GetValue();

		pvalue->SetMessage("Часы: ");
		newWorker->hours = pvalue->GetValue();

		newWorker->salary = newWorker->hpay * newWorker->hours;

		unsigned newId;
		pvalue->SetMessage("Введите ID: ");
		while (1) {
			newId = pvalue->GetValue();
			if (workerList.find(newId) != workerList.end()) std::cout << "ID уже существует.\r\n";
			else break;
		}

		workerList.insert(std::make_pair(newId, *newWorker));
		f_sortData();
	};

	f_enterid = [&](WorkerPtr& it) {
		unsigned id;
		std::unique_ptr<InputUnsigned> pvalue = std::make_unique<InputUnsigned>();
		pvalue->SetMessage("Введите ID: ");
		while (1) {
			id = pvalue->GetValue();
			it = workerList.find(id);
			if (it != workerList.end()) break;
			else std::cout << "Неизвестный ID.\r\n";
		}
	};

	f_editData = [&]() {
		WorkerPtr it;

		std::function<bool()> f_showsubmenu = [&]() {
			std::unique_ptr<InputChar> psubMenu = std::make_unique<InputChar>();
			psubMenu->SetMessage(std::format("Текущий ID - {}\r\nF - изменить имя\r\nM - изменить фамилию\r\nL - изменить отчество\r\nP - изменить должность\r\nS - изменить оплату в час\r\nH - изменить кол-во часов\r\nС - в главное меню\r\n", it->first));
			psubMenu->SetAllowedValues({ 'F', 'M', 'L', 'P', 'S', 'H', 'C', 'f', 'm', 'l', 'p', 's', 'h', 'c' });
			char selectedOption = psubMenu->GetValue();

			switch (selectedOption) {
			case 70: case 102:
				it->second.firstname = f_addData("Имя: ", "Некорректное имя.\r\n");
				break;
			case 77: case 109:
				it->second.middlename = f_addData("Фамилия: ", "Некорректная фамилия.\r\n");
				break;
			case 76: case 108:
				it->second.lastname = f_addData("Отчество: ", "Некорректное отчество.\r\n");
				break;
			case 80: case 112:
			{
				std::string spost;
				std::cout << "Должность: ";
				std::cin >> spost;
				it->second.post = std::move(spost);
				break;
			}
			case 83: case 115:
			{
				std::unique_ptr<InputUnsigned> pvalue = std::make_unique<InputUnsigned>();
				pvalue->SetMessage("Оплата за час: ");
				it->second.hpay = pvalue->GetValue();
				it->second.salary = it->second.hpay * it->second.hours;
				break;
			}
			case 72: case 104:
			{
				std::unique_ptr<InputUnsigned> pvalue = std::make_unique<InputUnsigned>();
				pvalue->SetMessage("Часы: ");
				it->second.hours = pvalue->GetValue();
				it->second.salary = it->second.hpay * it->second.hours;
				break;
			}
			default: return true;
			}

			return false;
		};

		f_enterid(it);
		bool existFlag = false;
		while (!existFlag) {
			existFlag = f_showsubmenu();
		}

		f_sortData();
	};

	f_enterFilterData = [&]() {
		std::function<bool()> f_showsubmenu = [&]() {
			std::unique_ptr<InputUnsigned> psubMenu = std::make_unique<InputUnsigned>();
			psubMenu->SetMessage("1 - Имя\r\n2 - Фамилия\r\n3 - Отчество\r\n4 - Должность\r\n5 - Минимальная оплата в час\r\n6 - Максимальная оплата в час\r\n7 - Минимальное кол-во часов\r\n8 - Максимальное кол-во часов\r\n9 - Минимальная зарплата\r\n10 - Максимальная зарплата\r\n11 - Сбросить фильтр\r\n12 - В главное меню\r\n");
			psubMenu->SetAllowedValues({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });
			unsigned selectedOption = psubMenu->GetValue();

			std::function<void(unsigned&)> f_setValue = [](unsigned& value) {
				std::unique_ptr<InputUnsigned> pvalue = std::make_unique<InputUnsigned>();
				pvalue->SetMessage("Введите значение: ");
				value = pvalue->GetValue();
			};

			switch (selectedOption) {
			case 1:
				filterData::firstname = f_addData("Имя: ", "Некорректное имя.\r\n");
				break;
			case 2:
				filterData::middlename = f_addData("Фамилия: ", "Некорректная фамилия.\r\n");
				break;
			case 3:
				filterData::lastname = f_addData("Отчество: ", "Некорректное отчество.\r\n");
				break;
			case 4:
			{
				std::string spost;
				std::cout << "Должность: ";
				std::cin >> spost;
				filterData::post = std::move(spost);
				break;
			}
			case 5:
			{
				f_setValue(filterData::hpay_min);
				break;
			}
			case 6:
			{
				f_setValue(filterData::hpay_max);
				break;
			}
			case 7:
			{
				f_setValue(filterData::hours_min);
				break;
			}
			case 8:
			{
				f_setValue(filterData::hours_max);
				break;
			}
			case 9:
			{
				f_setValue(filterData::salary_min);
				break;
			}
			case 10:
			{
				f_setValue(filterData::salary_max);
				break;
			}
			case 11:
				filterData::firstname = "";
				filterData::middlename = "";
				filterData::lastname = "";
				filterData::post = "";

				filterData::hpay_min = 0;
				filterData::hpay_max = UINT_MAX;

				filterData::hours_min = 0;
				filterData::hours_max = UINT_MAX;

				filterData::salary_min = 0;
				filterData::salary_max = UINT_MAX;
				break;
			default: return true;
			}

			return false;
		};

		bool existFlag = false;
		while (!existFlag) {
			existFlag = f_showsubmenu();
		}

		f_sortData();
	};

	f_deleteData = [&]() {
		WorkerPtr it;
		f_enterid(it);
		workerList.erase(it);
		f_sortData();
		std::cout << "Запись удалена.\r\n";
	};

	f_saveToFile = [&]() {
		std::ofstream fout;
		std::string path;

		while (1) {
			std::cout << "Введите путь к файул: ";
			std::cin >> path;
			fout.open(path);
			
			if (fout.is_open()) break;
			else std::cout << "Не удалось открыть файл.\r\n";
		}

		fout << "<\?xml version=\"1.0\" encoding=\"windows-1251\"\?>\r\n";
		fout << "<table>\r\n";

		for (auto item : selectedItems) {
			fout << std::format("<Worker id = \"{}\" firstname = \"{}\" middlename = \"{}\" lastname = \"{}\" post = \"{}\" hpay = \"{}\" hours = \"{}\" salary = \"{}\">\n", item->first, item->second.firstname, item->second.middlename, item->second.lastname, item->second.post, item->second.hpay, item->second.hours, item->second.salary);
			fout << "</Worker>\r\n";
		}

		fout << "</table>\r\n";
	};

	f_loadFromFile = [&]() {
		std::string path;
		pugi::xml_document doc;
		pugi::xml_parse_result result;

		while (1) {
			std::cout << "Введите путь к файлу: ";
			std::cin >> path;

			std::ifstream stream(path);
			result = doc.load(stream);
			if (result) break;
			else std::cout << "Не удалось открыть файл.\r\n";
		}

		selectedItems.clear();
		workerList.clear();

		filterData::firstname = "";
		filterData::middlename = "";
		filterData::lastname = "";
		filterData::post = "";

		filterData::hpay_min = 0;
		filterData::hpay_max = UINT_MAX;

		filterData::hours_min = 0;
		filterData::hours_max = UINT_MAX;

		filterData::salary_min = 0;
		filterData::salary_max = UINT_MAX;

		for (pugi::xml_node tool : doc.child("table").children("Worker")) {
			Worker newWorker;
			newWorker.firstname = tool.attribute("firstname").value();
			newWorker.middlename = tool.attribute("middlename").value();
			newWorker.lastname = tool.attribute("lastname").value();
			newWorker.post = tool.attribute("post").value();
			newWorker.hpay = std::stoul(tool.attribute("hpay").value());
			newWorker.hours = std::stoul(tool.attribute("hours").value());
			newWorker.salary = std::stoul(tool.attribute("salary").value());

			workerList.insert(std::make_pair(std::stoul(tool.attribute("id").value()), newWorker));
		}
		
		f_sortData();
	};

	f_showList = [&]() {
		std::cout << std::endl;
		std::cout << std::left
			<< std::setw(5) << " ID"
			<< std::setw(15) << "Имя"
			<< std::setw(15) << "Фамилия"
			<< std::setw(15) << "Отчество"
			<< std::setw(15) << "Должность"
			<< std::setw(16) << "Оплата за час"
			<< std::setw(10) << "Часы"
			<< std::setw(10) << "Оклад" << std::endl;
		for (int i = 0; i < 101; ++i) {
			std::cout << '-';
		}
		std::cout << std::endl;

		std::cout << std::endl;
		if (selectedItems.size() > 0) {
			for (auto it : selectedItems) {
				std::cout << std::left
					<< ' ' << std::setw(4) << it->first
					<< std::setw(15) << it->second.firstname
					<< std::setw(15) << it->second.middlename
					<< std::setw(15) << it->second.lastname
					<< std::setw(15) << it->second.post
					<< std::setw(16) << it->second.hpay
					<< std::setw(10) << it->second.hours
					<< std::setw(10) << it->second.salary << std::endl;
			}
		}
		else {
			std::cout << std::right << std::setw(61) << "Нет записей" << std::endl;
		}
		std::cout << std::endl;
	};

	f_selectSortType = [&]() {
		std::unique_ptr<InputChar> submenu = std::make_unique<InputChar>();
		submenu->SetMessage("Q - быстрая сортировка\r\nS - сортировка Шелла\r\nB - пузырьковая сортировка\r\n");
		submenu->SetAllowedValues({ 'Q', 'S', 'B', 'q', 's', 'b' });
		char selectedOption = submenu->GetValue();

		switch (selectedOption) {
		case 81: case 113:
			filterData::sortType = filterData::QUICK;
			break;
		case 83: case 115:
			filterData::sortType = filterData::SHELL;
			break;
		case 66: case 98:
			filterData::sortType = filterData::BUBBLE;
			break;
		}

		f_sortData();
	};

	bool existFlag = false;
	while (!existFlag) {
		existFlag = f_showmenu();
	}

	system("pause");
	return 0;
}

