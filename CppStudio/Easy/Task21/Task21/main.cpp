#include "..\\include\\pugixml.hpp"

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Question.h"
#include <vector>

using namespace std;

void Input(int* pointcount, int* answer, int answerblock_size, Question* question);

int main()
{
	SetConsoleOutputCP(1251);
	//извлекаем "тест" из xml-файла
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("..\\res\\test.xml");
	if (!result)
		return -1;

	std::vector<Question> questions;
	for (pugi::xml_node tool : doc.child("test").children("question"))
		questions.push_back(Question(tool));

	int pointcount = 0; //общее кол-во баллов
	int answer; //выбранный ответ
	int* pointcount_ptr = &pointcount;
	int* answer_ptr = &answer;
	Question* question_ptr;

	//непосредственный вывод теста
	for (auto question : questions)
	{
		//выводим текст вопроса на экран
		question_ptr = &question;
		cout << question.GetText() <<"\n" << endl;

		//выводим блок ответов
		for (auto option : question.GetAnswerBlock())
			cout << option.GetText() << endl;

		cout << '\n';
		//вводим номер ответа
		Input(pointcount_ptr, answer_ptr, question.GetAnswerBlock().size(), question_ptr);

		cout << "\n";
	}

	cout << "Сумма баллов: " << pointcount << endl;

	system("pause");
	return 0;
}

void Input(int* pointcount, int* answer, int answerblock_size, Question* question)
{
	try
	{
		cout << "Ответ: ";
		std::string err = "Некорректный ответ!";

		cin >> *answer;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			throw err;
		}
		if((*answer >= 1) && (*answer <= answerblock_size))
		{
			question->SetCurrentOption(*answer);
			*pointcount += question->GetCurrnetCriteria();
		}
		else throw err;
	}
	catch (std::string err)
	{
		cout << "\n" << err << "\n" << endl;
		Input(pointcount, answer, answerblock_size, question);
	}
}