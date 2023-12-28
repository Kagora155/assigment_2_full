//
// Created by user on 12/12/2023.

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;
connect_four_board::connect_four_board() {
    n_rows=6;
    n_cols=7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }}
bool connect_four_board::update_board(int x,int y, char mark) {
    if (x<1||x>n_cols||board[0][x-1]!=0){
        return false ;
    }

        for (int i = n_rows - 1; i >= 0; --i) {
            if (board[i][x - 1] == 0) {
                board[i][x - 1] = toupper(mark);
                n_moves++;
                return true;
            }
        } return false;

}
void connect_four_board::display_board(){
    for (int i = 0; i < 6; ++i) {
        cout << "\n| ";
        for (int j = 0; j < 7; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------------------------------------";
    } cout << endl;
}
bool connect_four_board:: is_winner(){
    //horizontal
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols-3; ++j) {
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j] != 0) {
                return true;
            }
        }
    }
    //vertical
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 0; j <n_cols ; ++j) {
            if (board[i][j] == board[i+1][j ] && board[i+1][j] == board[i+2][j ] && board[i+2][j ] == board[i+3][j ] && board[i][j] != 0) {
                return true;
            }
        }
    }
    //diagonal 1
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 0; j < n_cols-3; ++j) {
            if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3] && board[i][j] != 0)
            {
                return true;
            }

        }
    }
    //diagonal 2
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 3; j <n_cols ; ++j) {
            if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i+2][j-2] == board[i+3][j-3] && board[i][j] != 0)
            {
                return true;
            }

        }
    }
    return false ;
}
bool connect_four_board::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool connect_four_board::game_is_over() {
    return n_moves >= 42;
}