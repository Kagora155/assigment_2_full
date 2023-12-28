// Class definition for XO game classes
// Author:  ahmed mahmoud hasaneen ,id:20220039 ,S17
// Author: Nour El-dien Mohamed Rabie , id:20220364 , S17
// Author: doaa ayman mohamed , id:20220124 , S18
// Date:    17/12/2023

#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, char symbol) = 0;

    virtual bool is_winner() = 0;

    virtual bool is_draw() = 0;

    virtual void display_board() = 0;

    virtual bool game_is_over() = 0;
};

///////////////////////////////////////////

class X_O_Board : public Board
{
public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class Player
{
protected:
    string name;
    char symbol;

public:
    Player(char symbol);
    Player(int order, char symbol);

    virtual void get_move(int &x, int &y);

    string to_string();

    char get_symbol();
};

class RandomPlayer : public Player
{
protected:
    int dimension;

public:
    RandomPlayer(char symbol, int dimension);

    void get_move(int &x, int &y);
};

///////////////////////////////////////////
class GameManager
{
private:
    Board *boardPtr;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    void run();
    void board_5x5_run();
};
//////////////////////////////////////////
class connect_four_board : public Board
{
public:
    connect_four_board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class cnct4_player : public Player
{
public:
    cnct4_player(char symbol);
    cnct4_player(int order, char symbol);
    void get_move(int &x, int &y);
};

class board_5x5 : public Board
{
public:
    board_5x5();
    bool update_board(int x, int y, char mark);
    void display_board();

    struct winners
    {
        int x_count;
        int O_count;
    };
    winners count();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class random_cnct4_player : public Player
{
protected:
    int dimension;

public:
    random_cnct4_player(char symbol, int dimension);
    void get_move(int &x, int &y);
};
class Pyramic_Board : public Board
{
public:
    Pyramic_Board();
    bool update_board(int x, int y, char mark) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
};
#endif
