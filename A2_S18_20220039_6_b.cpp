// File: A2_S17_20220039_6_b.cpp
// adding a const prefix to a number of power itself
// like prefix is 011 and k is 3 out put will be :011000,011001,011010,011011,011100,011101,011110,011111
// Author:ahmed mahmoud hasaneen
// Section: s17
// ID: 20220039
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <string>
#include <bitset> // Include the <bitset> library for binary conversions
using namespace std;

void numbers(string prefix, int k)
{
    if (k < 0)
    {
        cout << "Please enter a non-negative number for 'k'." << endl;
        return;
    }

    if (k == 0)
    {
        cout << prefix << endl;
        return;
    }

    for (int i = 0; i < (1 << k); i++)
    {                                                             // Iterate through all possible k-digit binary numbers
        string suffix = bitset<32>(i).to_string().substr(32 - k); // Convert i to binary of length k
        cout << prefix << suffix << endl;
    }
}

int main()
{
    string prefix = "01000";
    int k = 4;
    numbers(prefix, k);
    return 0;
}