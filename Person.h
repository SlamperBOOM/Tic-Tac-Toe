#pragma once
#include "Player.h"
#include <conio.h>

class Person: public Player
{
public:
	virtual ~Person() {}

	bool GetCoords(int& x, int& y)
	{
		int key = _getch();
		if (key == 77)
		{
			if (y < 2) y++;
		}
		if (key == 75)
		{
			if (y > 0) y--;
		}
		if (key == 72)
		{
			if (x > 0) x--;
		}
		if (key == 80)
		{
			if (x < 2) x++;
		}
		if (key == 13)
		{
			return true;
		}
		return false;
	}
};

