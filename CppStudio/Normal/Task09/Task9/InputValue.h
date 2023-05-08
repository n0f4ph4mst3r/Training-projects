#pragma once
#include <iostream>
#include <optional>
#include <vector>
#include <sstream>

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

	void SetAllowedValues(std::vector<T> &values) {
		allowedValues = std::move(values);
	}
	
	T GetValue () {
		Input();
		return value;
	};

private:

	std::string msg; //сообщение перед вводом значения

	const size_t range; //максимально возможное для данного типа данных значение
	std::optional<T> max = std::nullopt; //пользовательское ограничение для вводимого значения
	std::vector<T> allowedValues; //допустимые значения
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
			else {
				if (max != std::nullopt && value > max) {
					ClearInput();
					continue;
				}

				if (allowedValues.size() > 0) {
					for (size_t i = 0; i < allowedValues.size(); ++i) {
						if (allowedValues[i] == value) {
							std::cin.ignore(range, '\n');
							return;
						}
					}

					ClearInput();
					continue;
				}
				
				std::cin.ignore(range, '\n');
				return;
			}
		}
	};


};

InputValue<int>::InputValue() : range(INT_MAX) {}
InputValue<unsigned>::InputValue() : range(UINT_MAX) {}
InputValue<double>::InputValue() : range(DBL_MAX) {}
InputValue<char>::InputValue() : range(CHAR_MAX) {}


InputValue<std::string>::InputValue() : range(4294967295) {}
void InputValue<std::string>::Input() {
	while (true) {
		std::cout << msg;
		std::getline(std::cin >> std::ws, value);

		//если ввод не удался или значение не соотвествует ограничению -> очистить поток
		if (std::cin.fail()) {
			ClearInput();
		}
		else {
		    if (allowedValues.size() > 0) {
				for (size_t i = 0; i < allowedValues.size(); ++i) {
					if (allowedValues[i] == value) {
						std::cin.ignore(range, '\n');
						return;
					}
				}

				ClearInput();
				continue;
			}

			return;
		}
	}
}
