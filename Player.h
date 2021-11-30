#pragma once

class Player
{
public:
	virtual ~Player() {}

	virtual void GetCoords(int& x, int& y) = 0;
};

