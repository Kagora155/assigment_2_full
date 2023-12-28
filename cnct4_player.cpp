//
// Created by user on 12/13/2023.
//
#include<iostream>
#include<random>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;
  cnct4_player:: cnct4_player(char sym): Player(sym){}
  cnct4_player:: cnct4_player(int ord, char sym): Player(ord,sym){}
void cnct4_player::get_move(int &x,int &y) {
    cout << "\nPlease enter your move (1 to 7) : ";
    cin >> x ;
}
random_cnct4_player::random_cnct4_player(char symbol, int dimension):Player(symbol) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
void random_cnct4_player:: get_move (int& x,int&y){
x=(int) (rand()/(RAND_MAX + 1.0) * dimension);

}
