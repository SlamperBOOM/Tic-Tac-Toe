#pragma once
#include "Player.h"

class Bot: public Player
{
public:
	virtual ~Bot() {}

	bool GetCoords(int& x, int& y)
	{
		x = rand() % 3;
		y = rand() % 3;
		return true;
	}
};

