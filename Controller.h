#pragma once
#include "GameModel.h"
#include "ViewMaker.h"
#include "Player.h"
#include <string>
#include <exception>

class Controller
{
public:

	int StartGame();

	void RestartGame();

	int MakeMove(int& x, int& y); //0 - turn success, 1 - already chosen, 2 - win

	void ShowChoice(int& x, int& y)
	{
		view.ShowChoice(x, y);
	}

	char GetTurnType()
	{
		return model.GetTurnType();
	}

private:
	ViewMaker view;
	GameModel model{view};
};

