#include "Controller.h"
#include <conio.h>

int Controller::StartGame()
{
	int choice = 1;
	view.CleanScreen();
	view.ShowStartMessage(choice);
	//"1. Player vs. Player"
	//"2. Player vs. Bot"
	//"3. Bot vs. Bot"
	while (true)
	{
		int key = _getch();
		if (key == 80) //down
		{
			if (choice < 3) choice++;
			else continue;
		}
		else if (key == 72) //up
		{
			if (choice > 1) choice--;
			else continue;
		}
		else if (key == 13) //enter
		{
			break;
		}
		else
		{
			continue;
		}
		view.CleanScreen();
		view.ShowStartMessage(choice);
	}
	model.ClearField();
	return choice;
}

void Controller::RestartGame()
{
	model.ClearField();
}

int Controller::MakeMove(int& x, int& y)
{
	return model.MakeMove(x, y);
}