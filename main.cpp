#include <iostream>
#include "Controller.h"
#include "Player.h"
#include <memory>
#include <windows.h>

bool Move(std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2, int numberofplayer, Controller& control, int& x, int& y)
{
    std::shared_ptr<Player> player;
    char movetype;
    if (numberofplayer == 1) {
        player = player1; movetype = 'X';
    }
    else {
        player = player2; movetype = 'O';
    }
    while (true)
    {
        if (!player->GetCoords(x, y))
        {
            control.ShowChoice(x, y);
            continue;
        }
        int status = control.MakeMove(movetype, x, y);
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
                    control.StartGame(player1, player2);
                    break;
                }
                else
                {
                    std::cout << "Wrong variant!";
                }
            }
            x = 1;
            y = 1;
            return true;
        }
    }
}

int main()
{
    srand(time(0));
    Controller control;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    //choosing players
    control.StartGame(player1, player2);
    int x = 1, y = 1;
    while (true)
    {
        Sleep(250);
        if (Move(player1, player2, 1, control, x, y))
        {
            continue;
        }
        Sleep(250);
        if (Move(player1, player2, 2, control, x, y))
        {
            continue;
        }
    }
}
