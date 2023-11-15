// File: A2_S17_20220364_1.cpp
// Purpose:Remove consecutive spaces Capitalize the first letter Convert the rest of the letters to lowercase:
// Author: Nour El-dien Mohamed Rabie
// Section: s17
// ID: 20220364
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string phrase;
    getline(cin, phrase); // to get the all line
    int size;
    size = phrase.size();

    //_____________

    int i = 0, j = 0;
    while (j < size)
    {
        j++;
        if (phrase[i] == 32 && phrase[i - 1] == 32)
        {                       // to check if there are two consecutive spaces
            phrase.erase(i, 1); // if there are two spaces erase the last one
            continue;
        }
        i++;
    }

    //_____________

    if (phrase[0] > 96 && phrase[0] < 123)
    {                    // to check if the first letter is capital or not
        phrase[0] -= 32; // if not make it capital
    }
    for (int i = 1; i < size; i++)
    {
        if (phrase[i] < 91 && phrase[i] > 64)
        {                    // to check if the rest letters are capital or not
            phrase[i] += 32; // if capital make it small
        }
    }
    cout << phrase;
}