#pragma once
#include <climits>
#include <iostream>
#include <cstdlib>
#include <optional>
#include <vector>

//шаблонный класс для ввода данных в консоль
template <class T> class InputValue {
public:

	InputValue() {};

	void SetMax(T value) {
		max = value;
	};

	void SetMessage(std::string str) {
		msg = str;
	}

	T GetValue () {
		Input();
		return value;
	};

private:

	std::string msg; //сообщение перед вводом значения

	const T range; //максимально возможное для данного типа данных значение
	std::optional<T> max = std::nullopt; //пользовательское ограничение для вводимого значения
	T value;

	void ClearInput() {
		std::cin.clear();
		std::cin.ignore(range, '\n');
		std::cout << "That input is invalid.\n";
	};

	void Input() {
		while (true) {
			std::cout << msg;
			std::cin >> value;

			//если ввод не удался или значение не соотвествует ограничению -> очистить поток
			if (std::cin.fail()) {
				ClearInput();
			}
			else if (value > max && max != std::nullopt) {
				ClearInput();
			}
			else {
				std::cin.ignore(range, '\n');
				break; //иначе прервать цикл
			}
		}
	};


};

InputValue<int>::InputValue() : range(INT_MAX) {}
InputValue<unsigned>::InputValue() : range(UINT_MAX) {}
InputValue<char>::InputValue() : range(CHAR_MAX) {}

