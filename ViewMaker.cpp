#include "ViewMaker.h"
#include <windows.h>

void ViewMaker::DrawField(const std::vector<std::vector<char>>& field, std::string message, const int& x,  const int& y)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			pattern[i * 2][j * 2] = field[i][j];
		}
	}
	CleanScreen();
	for (int i = 0; i < pattern.size(); ++i)
	{
		std::cout << pattern[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << message << std::endl;
	ShowChoice(x, y);
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
	coord.X = y * 2;
	coord.Y = x * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
