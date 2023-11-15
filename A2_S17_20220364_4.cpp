// File: A2_S17_20220364_4.cpp
// Purpose:calculate the prime numbers from 1 to n number
// Author: Nour El-dien Mohamed Rabie
// Section: s17
// ID: 20220364
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "enter the maximum number you want to check :\n";
    int N;
    cin >> N;
    vector<int> nums;
    for (unsigned int i = 2; i < N; i++)
    {
        nums.push_back(i); // to store all numbers from 2 to user input
    }
    for (unsigned int k = 0; k < N; k++)
    { // to pick the smalest number that hasn't checked yet
        for (unsigned int j = k + 1; j < N; j++)
        { // to divid all larger numbers over the picked one The remainder
            if (nums[j] % nums[k] == 0)
            {
                nums.erase(nums.begin() + j); // if it Divisible on the picked number it erase it
                N--;                          // to fit the new number of numbers
            }
        }
    }
    for (unsigned int l = 0; l < N; l++)
    {
        cout << nums[l] << " "; // to appear all the remain numbers
    }
}