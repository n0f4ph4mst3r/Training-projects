#include <iostream>
#include <Windows.h>
#include <memory>
#include "InputValue.h"

struct Moment {
	int hours;
	int min;
	int sec;
};

int main() {
	SetConsoleOutputCP(1251);

	std::unique_ptr<InputValue<int>> InputInt = std::make_unique<InputValue<int>>();

	std::cout << "Время\r\n";
	Moment moment;

	InputInt->SetMessage("Часы: ");
	moment.hours = InputInt->GetValue();

	InputInt->SetMessage("Минуты: ");
	moment.min = InputInt->GetValue();

	InputInt->SetMessage("Секунды: ");
	moment.sec = InputInt->GetValue();

	InputInt->SetMessage("Кол-во секунд: ");
	int seconds = InputInt->GetValue();

	seconds -= (moment.hours * 3600 + moment.min * 60 + moment.sec);
	seconds = abs(seconds);

	moment.hours = seconds / 3600;
	moment.min = (seconds - moment.hours * 3600) / 60;
	moment.sec = (seconds - moment.hours * 3600 - moment.min * 60);
	
	std::cout << "Оставшееся время: " << moment.hours << ":" << moment.min << ":" << moment.sec << std::endl;

	Moment first;
	Moment second;

	std::cout << "Первый момент времени\r\n";

	InputInt->SetMessage("Часы: ");
	first.hours = InputInt->GetValue();

	InputInt->SetMessage("Минуты: ");
	first.min = InputInt->GetValue();

	InputInt->SetMessage("Секунды: ");
	first.sec = InputInt->GetValue();

	std::cout << "Второй момент времени\r\n";

	InputInt->SetMessage("Часы: ");
	second.hours = InputInt->GetValue();

	InputInt->SetMessage("Минуты: ");
	second.min = InputInt->GetValue();

	InputInt->SetMessage("Секунды: ");
	second.sec = InputInt->GetValue();

	seconds = abs((first.hours * 3600 + first.min * 60 + first.sec)-(second.hours * 3600 + second.min * 60 + second.sec));

	std::cout << "Разница: " << seconds << std::endl;

	system("pause");
	return 0;
}