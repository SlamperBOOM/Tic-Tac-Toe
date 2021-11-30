#pragma once
#include "GameModel.h"
#include "ViewMaker.h"
#include "Player.h"
#include <string>
#include <exception>

class Controller
{
public:
	void StartGame(std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2);

	void RestartGame();

	int MakeMove(char movetype, int x, int y); //0 - ��� �������, 1 - ������ ������, 2 - ������

private:
	GameModel model;
	ViewMaker view;
};

