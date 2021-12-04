#pragma once
#include "Player.h"
#include "Controller.h"
#include <memory>

class Game
{
public:
	void Play();

private:
	Controller control;
	std::shared_ptr<Player> player1, player2;

	std::shared_ptr<Player> CreatePlayer(char playertype); //p - person, b - bot

	void ChoosePlayers(std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2);

	bool Move(const int& numberofplayer, int& x, int& y);

};

