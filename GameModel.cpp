#include "GameModel.h"
#include "Bot.h"
#include "Person.h"
#include <iostream>
#include <exception>

void GameModel::MakeMove(char movetype, int x, int y)
{
    if (field[x][y] != ' ')
    {
        throw std::invalid_argument("Wrong coordinates, choose another");
    }
    else
    {
        field[x][y] = movetype;
    }
}

std::shared_ptr<Player> GameModel::CreatePlayer(char playertype)
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

int GameModel::CheckForWin(char movetype)
{
    int countdiagonal1 = 0;
    int countdiagonal2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        int countlanes = 0;
        int countrows = 0;
        for (int j = 0; j < 3; ++j)
        {
            if (field[i][j] == movetype)
            {
                ++countlanes;
            }
            if (field[j][i] == movetype)
            {
                ++countrows;
            }
        }
        if (countlanes == 3 || countrows == 3)
        {
            return 1;
        }

        if (field[i][i] == movetype)
        {
            ++countdiagonal1;
        }
        if (field[i][2 - i] == movetype)
        {
            ++countdiagonal2;
        }
        if (countdiagonal1 == 3 || countdiagonal2 == 3)
        {
            return 1;
        }
    }

    bool fullfield = false;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (field[i][j] == ' ')
            {
                fullfield = true;
                break;
            }
        }
    }
    if (!fullfield)
    {
        return 2;
    }
    return 0;
}
