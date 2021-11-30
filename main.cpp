#include <iostream>
#include "Controller.h"
#include "Player.h"
#include <memory>
#include <windows.h>

int main()
{
    srand(time(0));
    char move = 'X';
    Controller control;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    //choosing players
    control.StartGame(player1, player2);
    while (true)
    {
        int x, y;
        Sleep(250);
        while (true)
        {
            player1->GetCoords(x, y);
            int status = control.MakeMove('X', x, y);
            if (status == 0)
            {
                break;
            }
            if (status == 1)
            {
                continue;
            }
            if (status == 2)
            {
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
                        std::cout << "Wrong variant!" << std::endl << "Do you want to restart the game or choose players(R/C): ";
                    }
                }
                continue;
            }
        }
        Sleep(250);
        while (true)
        {
            player2->GetCoords(x, y);
            int status = control.MakeMove('O', x, y);
            if (status == 0)
            {
                break;
            }
            if (status == 1)
            {
                continue;
            }
            if (status == 2)
            {
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
                        std::cout << "Wrong variant!" << std::endl << "Do you want to restart the game or choose players(R/C): ";
                    }
                }
                continue;
            }
        }
    }
}
