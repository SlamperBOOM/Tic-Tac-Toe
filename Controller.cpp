#include "Controller.h"

void Controller::StartGame(std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2)
{
	int choise;
	view.CleanScreen();
	view.ShowStartMessage();
	std::cin >> choise;
	//"1. Player vs. Player"
	//"2. Player vs. Bot"
	//"3. Bot vs. Bot"
	if (choise == 1)
	{
		player1 = model.CreatePlayer('p');
		player2 = model.CreatePlayer('p');
	}
	else if (choise == 2)
	{
		player1 = model.CreatePlayer('p');
		player2 = model.CreatePlayer('b');
	}
	else
	{
		player1 = model.CreatePlayer('b');
		player2 = model.CreatePlayer('b');
	}
	view.CleanScreen();
	model.ClearField();
	view.DrawField(model.GetField(), "Now 'X' turn");
}

void Controller::RestartGame()
{
	model.ClearField();
	view.CleanScreen();
	view.DrawField(model.GetField(), "Now 'X' turn");
}

int Controller::MakeMove(char movetype, int x, int y)
{
	try {
		model.MakeMove(movetype, x, y);
	}
	catch (std::invalid_argument& ex)
	{
		view.DrawField(model.GetField(), ex.what());
		return 1;
	}
	int win = model.CheckForWin(movetype);
	if (win == 1)
	{
		std::string message = "'";
		message += movetype;
		message += "' won!";
		view.DrawField(model.GetField(), message);
		return 2;
	}
	if (win == 2)
	{
		view.DrawField(model.GetField(), "It's a draw!");
		return 2;
	}

	if (movetype == 'X')
	{
		view.DrawField(model.GetField(), "Now 'O' turn");
	}
	else
	{
		view.DrawField(model.GetField(), "Now 'X' turn");
	}
	return 0;
}