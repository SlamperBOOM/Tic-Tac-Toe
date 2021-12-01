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
		startmessage.resize(4);
		startmessage[0] = "Who will play:";
		startmessage[1] = "Player vs. Player";
		startmessage[2] = "Player vs. Bot";
		startmessage[3] = "Bot vs. Bot";
	}

	void DrawField(const std::vector<std::vector<char>>& field, std::string message, const int& x, const int& y);//x and y for mark 

	void ShowStartMessage(int choise);

	void ShowChoice(const int& x, const int& y);

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
	std::vector<std::string> startmessage;
};

