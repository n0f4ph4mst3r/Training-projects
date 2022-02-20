#include <iostream>
#include <Windows.h>
#include "InputValue.h"
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

int main() {
	SetConsoleOutputCP(1251);

	InputValue<unsigned>* innputUINT = new InputValue<unsigned>();
	innputUINT->SetMessage("Введите размер масива: ");
	unsigned size = innputUINT->GetValue();

	std::vector<int> arr, result;
	arr.resize(size);

	std::cout << "Массив:\r\n";
	for (auto value : arr) {
		auto rng = std::default_random_engine{};
		rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<int> uniform_dist(INT_MIN, INT_MAX);


		value = uniform_dist(rng);
		std::cout << std::setw(4) << value << " ";
		if (value & 1) result.push_back(std::move(value));
	}
	std::cout << std::endl;

	std::cout << "Результат:\r\n";
	for (auto value : result) {
		std::cout << std::setw(4) << value << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}