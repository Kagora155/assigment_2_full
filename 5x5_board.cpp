//
// Created by user on 12/17/2023.
//
#include <iostream>
#include "BoardGame_Classes.hpp"
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
board_5x5::board_5x5() {
    n_rows = n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}



bool board_5x5::update_board(int x, int y, char mark) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void board_5x5::display_board() {
    for (int i : {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board[i][j] << " |";
        }
        cout << "\n----------------------------------------------------";
    }
    cout << endl;
}





board_5x5::winners board_5x5::count() {
    winners w;
    w.x_count = 0;
    w.O_count = 0;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            char t = board[i][j];
            if (t == board[i - 1][j - 1] && t == board[i + 1][j + 1] && t == 'O')w.O_count++;
            if (t == board[i - 1][j - 1] && t == board[i + 1][j + 1] && t == 'X')w.x_count++;
            if (t == board[i][j - 1] && t == board[i][j + 1] && t == 'O')w.O_count++;
            if (t == board[i][j - 1] && t == board[i][j + 1] && t == 'X')w.x_count++;
            if (t == board[i - 1][j] && t == board[i + 1][j] && t == 'O')w.O_count++;
            if (t == board[i - 1][j] && t == board[i + 1][j] && t == 'X')w.x_count++;
            if (t == board[i - 1][j + 1] && t == board[i + 1][j - 1] && t == 'O')w.O_count++;
            if (t == board[i - 1][j + 1] && t == board[i + 1][j - 1] && t == 'X')w.x_count++;
        }
    }

    for (int j : {0, 4}) {
        for (int i = 0; i < 3; i++) {
            if (board[j][i] == board[j][1 + i] && board[j][i] == board[j][2 + i] && board[j][i] == 'O') w.O_count++;
            if (board[j][i] == board[j][1 + i] && board[j][i] == board[j][2 + i] && board[j][i] == 'X') w.x_count++;
        }
    }

    for (int j : {0, 4}) {
        for (int i = 0; i < 3; i++) {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[2 + i][j] && board[i][j] == 'O') w.O_count++;
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[2 + i][j] && board[i][j] == 'X') w.x_count++;
        }
    }
    return w;
}


bool board_5x5::is_winner() {
    winners w;
    w = count();

    if (w.x_count > w.O_count){

        cout << " X is the winner!\n";
        return true;
    }

    else if (w.O_count > w.x_count) {
        cout << w.O_count << endl;
        cout << " O is the winner!\n";
        return true;
    }

    else return false;
}



bool board_5x5::is_draw() {
    return(n_moves == 24 && !is_winner());
}


bool board_5x5::game_is_over() {
    return(n_moves >= 24);
}