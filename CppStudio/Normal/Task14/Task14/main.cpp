#include <iostream>
#include <Windows.h>
#include <memory>
#include <fstream>

#include "InputValue.h"
#include "Worker.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<unsigned int>> InputUint = std::make_unique<InputValue<unsigned int>>();

	std::cout << "Имя работника: ";
	std::string name;
	std::cin >> name;

	InputUint->SetMessage("Стаж работника: ");
	unsigned int exp = InputUint->GetValue();

	InputUint->SetMessage("Почасовая оплата: ");
	unsigned int hWage = InputUint->GetValue();

	InputUint->SetMessage("Кол-во часов: ");
	unsigned int hours = InputUint->GetValue();

	std::unique_ptr<Worker> worker = std::make_unique<Worker>(name, exp, hWage, hours);

	std::cout << "Имя работника: " << worker->GetName() << std::endl;
	std::cout << "Стаж работника: " << worker->GetExp() << std::endl;
	std::cout << "Почасовая оплата: " << worker->GethWage() << std::endl;
	std::cout << "Кол-во часов: " << worker->Gethours() << std::endl;
	std::cout << "Зарплата: " << worker->GetSalary() << std::endl;
	std::cout << "Премия: " << worker->GetPremy() << std::endl;

	std::ofstream fout("worker.txt");
	fout << "Имя работника: " << worker->GetName() << std::endl;
	fout << "Стаж работника: " << worker->GetExp() << std::endl;
	fout << "Почасовая оплата: " << worker->GethWage() << std::endl;
	fout << "Кол-во часов: " << worker->Gethours() << std::endl;
	fout << "Зарплата: " << worker->GetSalary() << std::endl;
	fout << "Премия: " << worker->GetPremy() << std::endl;
	fout.close();
    std::cout << "Инвормация записана в файл worker.txt" << std::endl;

	system("pause");
	return 0;
}

