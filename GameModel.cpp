#include "GameModel.h"
#include "Bot.h"
#include "Person.h"
#include <iostream>
#include <exception>


int GameModel::MakeMove(int& x, int& y)
{
    if (field[x][y] != ' ')
    {
        Notify(1, x, y);
        return 1;
    }
    else
    {
        field[x][y] = turn;
        int win = CheckForWin();
        if (win == 2)
        {
            Notify(3, x, y);
            return 1;
        }
        if (win == 1)
        {
            Notify(2, x, y);
            return 2;
        }
        if (turn == 'X')
        {
            turn = 'O';
        }
        else
        {
            turn = 'X';
        }
        Notify(0, x, y);
        return 0;
    }
}

int GameModel::CheckForWin()
{
    int countdiagonal1 = 0;
    int countdiagonal2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        int countlanes = 0;
        int countrows = 0;
        for (int j = 0; j < 3; ++j)
        {
            if (field[i][j] == turn)
            {
                ++countlanes;
            }
            if (field[j][i] == turn)
            {
                ++countrows;
            }
        }
        if (countlanes == 3 || countrows == 3)
        {
            return 1;
        }

        if (field[i][i] == turn)
        {
            ++countdiagonal1;
        }
        if (field[i][2 - i] == turn)
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

void GameModel::Notify(const int& status, const int& x, const int& y)
{
    view.RefreshField(status, x, y, *this);
}
