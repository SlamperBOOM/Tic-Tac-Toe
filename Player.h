#pragma once

class Player
{
public:
	virtual ~Player() {}

	virtual bool GetCoords(int& x, int& y) = 0; //13 - place chosen
};

