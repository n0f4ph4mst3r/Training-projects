#pragma once
#include <string>
#include "../include/pugixml.hpp"
#include <vector>
#include "Answer.h"
//вопрос
class Question
{
	std::string text; //текст вопроса
	std::vector<Answer> answerblock; //блок ответов
	int currentoption, currencriteria; //выбранный ответ и кол-во баллов за него
public:
	Question(pugi::xml_node tool);
	std::string GetText();
	std::vector<Answer> GetAnswerBlock();

	void SetCurrentOption(int value);
	int GetCurrnetCriteria();
};