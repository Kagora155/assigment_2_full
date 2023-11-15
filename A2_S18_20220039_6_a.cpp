// File: A2_S17_20220039_6_a.cpp
// converting from decimal to binary number
// Author:ahmed mahmoud hasaneen
// Section: s17
// ID: 20220039
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void binary(int n)
{
    if (n == 0)
    {
        cout << 0;
        return;
    }

    if (n > 0)
    {
        binary(n / 2);
        cout << n % 2;
    }
}
int main()
{

    int n;
    cout << "your number is:";
    cin >> n;
    binary(n);
    cout << endl;

    return 0;
}
