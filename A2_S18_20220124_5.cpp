// File: A2_S18_20220124_5.cpp
// Purpose:  e a program that manages a list of up to 10 players and their high scores
// Author:doaa ayman mohamed
// Section: s18
// ID: 20220124
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <bits/stdc++.h>
#include <string>
using namespace std;
 int main(){
// std::ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
   vector <pair<int,string>>vec;
   int num;
   string name;
   int score;
    cout<<"please enter the name and score of the players : \n";
   for (int i = 0; i < 10; i++)
   { 
    cin>>name>>score;
     vec.push_back(make_pair(score,name));//to make a list of players
   }
   sort(vec.begin(),vec.end());
   cout<<"1-add a new player and score \n2-print the top 10 names and scores \n3-enter a player name to show his score : \n";
   while (cin>>num&&num!=0) //
   {
    if (num==1){
    cin>>name>>score;
    if (score>vec[0].first)
    {vec[0].second=name; //if the score of the new player bigger than the smalest score in the list I'll exchange them.
    vec[0].first=score;
    sort(vec.begin(),vec.end());} //sorting the vetor
   }
   else if (num==2)
   {
    for (int i =10; i >=0; i--)
    {
     cout<<vec[i].second<<" "<<vec[i].first<<"\n"; //printing the list from the biggest 
    }
    }
    else if (num==3)
    {
      string player_name;
      cout<<"enter the name of the player that you want to know his score : ";
      cin>>player_name;
      for (int i = 10; i >=0; i--)
      {
        if (player_name==vec[i].second) //finding the score of the player that the user entered
        {
          cout<<vec[i].first<<"\n";
          break;
        }
        if (i==0)
          {
            cout<< "this name is not exist!";
          }
      }
      
    }
   }
   }