// File: A2_S17_20220039_9.cpp
// Purpose: its a game all the traget at it to get back 42bears from the number of bears that the user givimh you
// Author:ahmed mahmoud hasaneen
// Section: s17
// ID: 20220039
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>

using namespace std;

bool bears(int n)
{
    if (n == 42)
    {
        return true; // Base case: We have 42 bears, and we have won the game.
    }

    if (n < 42)
    {
        return false; // Base case: We cannot reach 42 bears with the given number of bears.
    }

    // Rule 2: If n is divisible by 3 or 4, try returning the product of the last two digits.
    if ((n % 3 == 0 || n % 4 == 0))
    {
        int first = (n % 10);
        int second = (n % 100) / 10;

        if (first * second != 0)
        {
            bears(n - (first * second));
        }
        else
            bears(n / 2);
    }
    // Rule 1: If n is even, try returning n/2 bears.
    if (n % 2 == 0)
    {
        bears(n / 2);
        return true;
    }

    // Rule 3: If n is divisible by 5, return 42 bears.
    if (n % 5 == 0 && bears(n - 42))
    {
        return true;
    }

    return false; // If none of the rules leads to a win, return false.
}

int main()
{
    int n;
    cout << "Enter the number of bears: ";
    cin >> n;

    if (bears(n))
    {
        cout << "You can win the game starting with " << n << " bears!" << endl;
    }
    else
    {
        cout << "You can't win the game starting with " << n << " bears." << endl;
    }

    return 0;
}