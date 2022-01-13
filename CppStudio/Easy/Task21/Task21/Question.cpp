#include "Question.h"

Question::Question(pugi::xml_node tool)
{
	text = tool.attribute("text").value();
	for (auto answer_xml : tool.child("answerblock").children("answer"))
	{
		answerblock.push_back(Answer(answer_xml));
	}
}

std::string Question::GetText()
{
	return text;
}

std::vector<Answer> Question::GetAnswerBlock()
{
	return answerblock;
}

void Question::SetCurrentOption(int value)
{
	currentoption = value;
	value--;
	currencriteria = answerblock[value].GetCriteria();
}

int Question::GetCurrnetCriteria()
{
	return currencriteria;
}