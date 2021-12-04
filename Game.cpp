#include "Game.h"
#include "Person.h"
#include "Bot.h"
#include <Windows.h>

std::shared_ptr<Player> Game::CreatePlayer(char playertype)
{
    if (playertype == 'p')
    {
        return std::shared_ptr<Player>(new Person());
    }
    else
    {
        return std::shared_ptr<Player>(new Bot());
    }
}

void Game::ChoosePlayers(std::shared_ptr<Player> &player1, std::shared_ptr<Player> &player2)
{
    int choice = control.StartGame();
	if (choice == 1)
	{
		player1 = CreatePlayer('p');
		player2 = CreatePlayer('p');
	}
	else if (choice == 2)
	{
		player1 = CreatePlayer('p');
		player2 = CreatePlayer('b');
	}
	else
	{
		player1 = CreatePlayer('b');
		player2 = CreatePlayer('b');
	}
}

bool Game::Move(const int& numberofplayer, int& x, int& y)
{
    std::shared_ptr<Player> player;
    if (numberofplayer == 1) {
        player = player1;
    }
    else {
        player = player2;
    }
    while (true)
    {
        if (!player->GetCoords(x, y))
        {
            control.ShowChoice(x, y);
            continue;
        }
        int status = control.MakeMove(x, y);
        if (status == 0)
        {
            //correct coords
            return false;
        }
        if (status == 1)
        {
            //wrong coords
            continue;
        }
        if (status == 2)
        {
            //returning cursor to the end
            COORD coord;
            coord.Y = 7;
            coord.X = 0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            //win processing
            while (true)
            {
                std::cout << std::endl << "Do you want to restart the game or choose players(R/C): ";
                char choise;
                std::cin >> choise;
                if (choise == 'R' || choise == 'r')
                {
                    control.RestartGame();
                    break;
                }
                else if (choise == 'C' || choise == 'c')
                {
                    ChoosePlayers(player1, player2);
                    break;
                }
                else
                {
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    std::cout << " " << std::endl << "                                                                                  ";//need to clear previous choice
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    std::cout << "Wrong variant!";
                }
            }
            return true;
        }
    }
}

void Game::Play()
{
    ChoosePlayers(player1, player2);
    int x = 1, y = 1;
    while (true)
    {
        Sleep(250);
        if (Move(1, x, y))
        {
            x = 1;
            y = 1;
            continue;
        }
        Sleep(250);
        if (Move(2, x, y))
        {
            x = 1;
            y = 1;
            continue;
        }
    }
}
