#include "Answer.h"

Answer::Answer(pugi::xml_node tool)
{
	std::string sub = tool.attribute("text").value();
	text = "->" + sub;
	criteria = tool.attribute("criteria").as_int();
}

std::string Answer::GetText()
{
	return text;
}

int Answer::GetCriteria()
{
	return criteria;
}