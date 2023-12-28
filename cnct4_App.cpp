//
// Created by user on 12/14/2023.
//
#include <iostream>
#include "connect_four_board.cpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "X_O_Board.cpp"
#include "5x5_board.cpp"
#include "Pyramic_Board.cpp"
using namespace std;

int main()
{
    cout << "please enter the game that you want to play : \n1)XO game \n2)connect four game \n3)5x5\n4) pyramic game\n";
    int num;
    cin >> num;
    if (num == 2)
    {
        int choice;
        Player *players[2];
        players[0] = new cnct4_player(1, 'x');
        cout << "Welcome to FCAI connect four Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new cnct4_player(2, 'o');
        else
            // Player pointer points to child
            players[1] = (new random_cnct4_player('o', 7));

        GameManager cnct4_game(new connect_four_board(), players);
        cnct4_game.run();
        system("pause");
    }
    else if (num == 1)
    {
        int choice;
        Player *players[2];
        players[0] = new Player(1, 'x');
        cout << "strating xo game \n";
        cout << "Press 1 if you want to play with specail player and any other bottom to play with  other player: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
        system("pause");
    }
    else if (num == 3)
    {
        int choice;
        Player *players[2];
        players[0] = new Player(1, 'x');
        cout << "Welcome to FCAI 5x5 Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 5);

        GameManager third_game(new board_5x5, players);
        third_game.board_5x5_run();
        system("pause");
    }
    else
    {
        int choice;
        Player *players[2];
        players[0] = new Player(1, 'x');

        cout << "hello sir \n";
        cout << "choose 1 if you want to play with special player if no choose any other key and you will play with antoher player  : ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager fourth_game(new Pyramic_Board, players);
        fourth_game.run();
    }
}
