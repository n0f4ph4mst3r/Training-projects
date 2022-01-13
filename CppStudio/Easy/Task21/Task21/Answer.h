#pragma once
#include <string>
#include "../include/pugixml.hpp"
//ответ
class Answer
{
	std::string text; //текст ответа
	int criteria;//кол-во баллов

public:
	Answer(pugi::xml_node tool);
	std::string GetText();
	int GetCriteria();
};