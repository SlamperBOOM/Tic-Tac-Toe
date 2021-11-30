#pragma once
#include <iostream>
#include <string>
#include <vector>

class ViewMaker
{
public:

	ViewMaker()
	{
		pattern.resize(5);
		ClearField();
	}

	void DrawField(const std::vector<std::vector<char>>& field, std::string message);

	void ShowStartMessage()
	{
		std::cout << "Who will play:" << std::endl <<
			"1. Player vs. Player" << std::endl <<
			"2. Player vs. Bot" << std::endl <<
			"3. Bot vs. Bot" << std::endl << std::endl <<
			"Choise: ";
	}

	void CleanScreen()
	{
		system("cls");
	}

	void ClearField()
	{
		pattern[0] = " | | ";
		pattern[1] = "-+-+-";
		pattern[2] = " | | ";
		pattern[3] = "-+-+-";
		pattern[4] = " | | ";
	}

private:
	std::vector<std::string> pattern;
};

