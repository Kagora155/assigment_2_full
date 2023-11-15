// File: A2_S18_20220124_2.cpp
// Purpose:  converting male speech to inclusive speech that includes both male and female
// Author:doaa ayman mohamed
// Section: s18
// ID: 20220124
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <bits/stdc++.h>
#include <string>
using namespace std;
 int main(){
  std::ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
  string str,copy;
  getline(cin,str,'\n'); //to get all the line not the first word
  if (str.substr(0,3)=="He ") //if the first word he i will convert it 
   str=str.substr(0,3)+"or she "+str.substr(3,str.size()-1);
 for (int i = 0; i < str.size(); i++)
  {
  if (str.substr(i,4)==" He ")
   str=str.substr(0,i)+" He or she "+str.substr(i+4,str.size()-i-1);  //to convert any he in the speech
   if (str.substr(i,4)==" he ")
   str=str.substr(0,i)+" he or she "+str.substr(i+4,str.size()-i-1);
  }
  for (int i = 0; i < str.size(); i++)
  {
     if (str.substr(i,5)==" him."||str.substr(i,5)==" him?"||str.substr(i,5)==" him!"||str.substr(i,5)==" him ")   //to convert him or his 
     str=str.substr(0,i)+" him or her"+str.substr(i+4,str.size()-i-1);
     if (str.substr(i,5)==" his."||str.substr(i,5)==" his?"||str.substr(i,5)==" his!"||str.substr(i,5)==" his ")
     str=str.substr(0,i)+" his or her"+str.substr(i+4,str.size()-i-1);
  }
  
  cout<<str;
   }
   //---------------------------------------------------------------------------------------
  
   
 
 

