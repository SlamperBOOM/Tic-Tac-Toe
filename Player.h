#pragma once
#include "Controller.h"

class Controller;

class Player
{
public:
	virtual ~Player() {}

	virtual bool MakeMove(Controller& control, char type) = 0;
};

