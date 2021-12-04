#include "ViewMaker.h"
#include <windows.h>

void ViewMaker::DrawField(const int& status, const int& x,  const int& y, const GameModel& model)
{
	const std::vector<std::vector<char>> field = model.GetField();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			pattern[i * 2][j * 2] = field[i][j];
		}
	}
	std::string message = MakeMessage(status, model);
	CleanScreen();
	for (int i = 0; i < pattern.size(); ++i)
	{
		std::cout << pattern[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << message << std::endl;
	ShowChoice(x, y);
}

std::string ViewMaker::MakeMessage(const int& status, const GameModel& model)
{
	if (status == 0)
	{
		std::string message = "Now '";
		message += model.GetTurnType();
		message += "' turn";
		return message;
	}
	if (status == 1)
	{
		return "Wrong coords, choose another";
	}
	if (status == 2)
	{
		std::string message = "'";
		message += model.GetTurnType();
		message += "' won!";
		return message;
	}
	if (status == 3)
	{
		return "It's a draw!";
	}
	return "";
}

void ViewMaker::RefreshField(const int& status, const int& x, const int& y, const GameModel& model)
{
	if (status == 1)
	{
		COORD coord;
		coord.Y = 6;
		coord.X = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::string message = MakeMessage(status, model);
		std::cout << message;
		ShowChoice(x, y);
	}
	else
	{
		DrawField(status, x, y, model);
	}
}

void ViewMaker::ShowStartMessage(int choise)
{
	for (int i = 0; i < startmessage.size(); ++i)
	{
		if (i == choise)
		{
			std::cout << ">";
		}
		else if (i > 0)
		{
			std::cout << " ";
		}
		std::cout << startmessage[i] << std::endl;
	}
}

void ViewMaker::ShowChoice(const int& x, const int& y)
{
	COORD coord;
	coord.Y = x * 2;
	coord.X = y * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
