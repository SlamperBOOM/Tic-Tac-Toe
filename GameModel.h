#pragma once
#include "Player.h"
#include <vector>
#include <memory>

class GameModel
{
public:
	GameModel()
	{
		field.resize(3);
		field[0].resize(3);
		field[1].resize(3);
		field[2].resize(3);
		ClearField();
	}

	void MakeMove(char movetype, int x, int y);

	std::shared_ptr<Player> CreatePlayer(char playertype); //p - person, b - bot

	int CheckForWin(char movetype);

	std::vector<std::vector<char>>& GetField()
	{
		return field;
	}

	void ClearField()
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				field[i][j] = ' ';
	}

private:
	std::vector<std::vector<char>> field; // ' ' - пусто, 'X' - крестик, 'O' - нолик

};

