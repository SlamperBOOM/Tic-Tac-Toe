#pragma once
#include "Player.h"
#include <vector>
#include <memory>
#include "ViewMaker.h"

class ViewMaker;

class GameModel
{
public:
	GameModel() = default;

	GameModel(ViewMaker& v):view(v)
	{
		field.resize(3);
		field[0].resize(3);
		field[1].resize(3);
		field[2].resize(3);
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				field[i][j] = ' ';
	}

	int MakeMove(int& x, int& y);

	const std::vector<std::vector<char>>& GetField() const
	{
		return field;
	}

	void ClearField()
	{
		win = ' ';
		turn = 'X';
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				field[i][j] = ' ';
		Notify(0, 1, 1);
	}

	char GetTurnType() const
	{
		return turn;
	}
	
	void Notify(const int& status, const int& x, const int& y);
	

private:
	ViewMaker& view;
	std::vector<std::vector<char>> field; // ' ' - plain, 'X' - x, 'O' - o
	char turn = 'X';
	char win = ' ';

	int CheckForWin();

};

