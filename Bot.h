#pragma once
#include "Player.h"
#include <windows.h>

class Bot: public Player
{
public:
	virtual ~Bot() {}

	bool MakeMove(Controller& control, char type)
	{
		Sleep(1000);
		while (true)
		{
			int status = control.MakeMove(type, rand() % 3, rand() % 3);
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

