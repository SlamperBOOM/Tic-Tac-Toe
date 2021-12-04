#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameModel.h"

class GameModel;

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

	void RefreshField(const int& status, const int& x, const int& y, const GameModel& model);

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

	void DrawField(const int& status, const int& x, const int& y, const GameModel& model);//x and y for mark 

	std::string MakeMessage(const int& status, const GameModel& model);
	
};

