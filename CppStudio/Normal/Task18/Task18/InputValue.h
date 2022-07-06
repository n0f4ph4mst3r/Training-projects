#pragma once
#include <iostream>
#include <optional>
#include <vector>
#include <sstream>

//шаблонный класс для ввода данных в консоль
template <class T> class InputValue {
public:
	InputValue()  {};

	void SetMax(const T value) {
		m_max = value;
	};

	void SetMin(const T value) {
		m_min = value;
	};

	void SetMessage(const std::string str) {
		m_message = str;
	}

	void SetAllowedValues(const std::vector<T> &values) {
		m_allowedValues = std::move(values);
	}
	
	T GetValue () {
		Input();
		return m_value;
	};

private:
	std::string m_message; //сообщение перед вводом значения
	const size_t m_range; //максимально возможное для данного типа данных значение
	std::optional<T> m_max = std::nullopt; //максимальное значенеи
	std::optional<T> m_min = std::nullopt; //минимальное значение
	std::vector<T> m_allowedValues; //допустимые значения
	T m_value; //вводимое значение

	void ClearInput() {
		std::cin.clear();
		std::cin.ignore(m_range, '\n');
		std::cout << "That input is invalid.\n";
	};

	void Input() {
		while (true) {
			std::cout << m_message;
			std::cin >> m_value;

			//если ввод не удался или значение не соотвествует ограничению -> очистить поток
			if (std::cin.fail()) {
				ClearInput();
			}
			else {
				if ((m_max != std::nullopt && m_value > m_max) || (m_min != std::nullopt && m_value < m_min)) {
					ClearInput();
					continue;
				}

				if (m_allowedValues.size() > 0) {
					for (size_t i = 0; i < m_allowedValues.size(); ++i) {
						if (m_allowedValues[i] == m_value) {
							std::cin.ignore(m_range, '\n');
							return;
						}
					}

					ClearInput();
					continue;
				}
				
				std::cin.ignore(m_range, '\n');
				return;
			}
		}
	};


};

InputValue<int>::InputValue() : m_range(INT_MAX) {}
InputValue<unsigned>::InputValue() : m_range(UINT_MAX) {}
InputValue<double>::InputValue() : m_range((size_t)std::numeric_limits<double>::max) {}
InputValue<char>::InputValue() : m_range(CHAR_MAX) {}


InputValue<std::string>::InputValue() : m_range(4294967295) {}
void InputValue<std::string>::Input() {
	while (true) {
		std::cout << m_message;
		std::getline(std::cin >> std::ws, m_value);

		//если ввод не удался или значение не соотвествует ограничению -> очистить поток
		if (std::cin.fail()) {
			ClearInput();
		}
		else {
		    if (m_allowedValues.size() > 0) {
				for (size_t i = 0; i < m_allowedValues.size(); ++i) {
					if (m_allowedValues[i] == m_value) {
						std::cin.ignore(m_range, '\n');
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
