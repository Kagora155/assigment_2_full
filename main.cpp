#include <iostream>
#include "biGreal.cpp"
using namespace std;
int main(){
    string str1,str2;
    cout<<"please enter the first number \n";
    cin>>str1;
    cout<<"please enter the second number \n";
    cin>>str2;
    BigReal r1(str1);
    BigReal r2(str2);
    if (r1.isValidReal(str1)==true&&r2.isValidReal(str2)==true){
        BigReal r3;
       cout<< (r1==r2);
    }
    else if (r1.isValidReal(str1)==false)
        cout<<"the first number is not valid\n";
    else if (r2.isValidReal(str2)==false)
        cout<<"the second number is not valid\n";
    else
        cout<<"the numbers are not valid \n";







    return 0;
}