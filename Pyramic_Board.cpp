#include <iostream>
#include <string>
#include "BoardGame_Classes.hpp"
using namespace std;
Pyramic_Board::Pyramic_Board()
{
    n_moves = 0;
    n_cols = 5;
    n_rows = 3;
    board = new char *[n_rows];

    size_t i = 0;
    while (i < n_rows)
    {
        board[i] = new char[i * 2 + 1];

        size_t j = 0;
        while (j < i * 2 + 1)
        {
            board[i][j] = ' ';
            j++;
        }

        i++;
    }
}
bool Pyramic_Board::update_board(int x, int y, char mark)
{

    if (n_moves == 9)
        return false;

    if (x >= 0 && x < n_rows && y >= 0 && y < n_cols && board[x][y] == ' ')
    {

        board[x][y] = mark;
        n_moves++;
        return true;
    }

    return false;
}
void Pyramic_Board::display_board()
{
    cout << "----------------------\n";

    size_t i = 0;
    while (i < n_rows)
    {
        if (i == 0)
        {
            cout << "   |";
        }
        if (i == 1)
        {
            cout << " |";
        }

        size_t j = 0;
        while (j < i * 2 + 1)
        {
            cout << board[i][j] << "|";
            j++;
        }

        cout << "\n"
             << "----------\n";

        i++;
    }

    cout << "------------------------\n";
}

bool Pyramic_Board::is_winner()
{

    if (board[2][2] == board[1][1] && board[0][0] == board[2][2] && board[2][2] != ' ' ||
        board[1][2] == board[1][0] && board[1][1] == board[1][0] && board[1][1] != ' ' ||
        board[0][0] == board[1][2] && board[1][2] == board[2][4] && board[0][0] != ' ' ||
        board[0][0] == board[2][0] && board[1][0] == board[0][0] && board[0][0] != ' ')
    {
        return true;
    }

    else
    {
        size_t i = 0;
        while (i < 3)
        {
            if (board[2][0 + i] == board[2][1 + i] && board[2][2 + i] == board[2][1 + i] && board[2][0 + i] != ' ')
            {
                return true;
            }
            i++;
        }
    }

    return false;
}

bool Pyramic_Board::is_draw()
{
    return n_moves == 9;
}

bool Pyramic_Board::game_is_over()
{
    return n_moves == 9;
}

