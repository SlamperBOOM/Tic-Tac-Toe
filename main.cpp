#include <iostream>
#include "Controller.h"
#include "Player.h"
#include <memory>



int main()
{
    char move = 'X';
    Controller control;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    //choosing players
    control.StartGame(player1, player2);
    while (true)
    {
        int x, y;
        if (player1->MakeMove(control, 'X'))
        {
            while (true)
            {
                std::cout << "Do you want to restart the game or choose players(R/C): ";
                char choise;
                std::cin >> choise;
                if (choise == 'R')
                {
                    control.RestartGame();
                    break;
                }
                else if (choise == 'C')
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
        if (player2->MakeMove(control, 'O'))
        {
            while (true)
            {
                std::cout << "Do you want to restart the game or choose players(R/C): ";
                char choise;
                std::cin >> choise;
                if (choise == 'R')
                {
                    control.RestartGame();
                    break;
                }
                else if (choise == 'C')
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
