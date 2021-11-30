#pragma once
#include "Player.h"

class Person: public Player
{
public:
	virtual ~Person() {}

	bool MakeMove(Controller& control, char type)
	{
		while (true)
		{
			int x;
			int y;

			int status = control.MakeMove(type, x, y);
			if (status == 0)
			{
				return false;
			}
			if (status == 1)
			{
				continue;
			}
			if (status == 2)
			{
				return true;
			}
		}
	}
};

