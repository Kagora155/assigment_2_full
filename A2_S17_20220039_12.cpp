// File: A2_S17_20220039_12.cpp
// Purpose:its a code just doing a check for scammers acconuts if the acconut has mentioned this words and get alot of points that make
// it get a ban or something like that depends on the ponits
// Author:ahmed mahmoud hasaneen
// Section: s17
// ID: 20220039
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
void problem12()
{
    // Create a map to store the frequency of specific keywords and their associated scores
    map<string, int> freq, words{
                               // List of predefined keywords and their associated scores
                               {"urgent", 3},
                               {"important", 3},
                               {"immediate action required", 3},
                               {"account suspended", 3},
                               {"account security risk", 3},
                               {"verify your account", 3},
                               {"update your account information", 3},
                               {"confirm your identity", 3},
                               {"click here", 3},
                               {"link", 3},
                               {"password", 3},
                               {"credit card number", 3},
                               {"social security number", 3},
                               {"banking information", 3},
                               {"personal information", 3},
                               {"confidential information", 3},
                               {"free", 2},
                               {"prize", 2},
                               {"winner", 2},
                               {"gift", 2},
                               {"offer", 2},
                               {"limited time", 2},
                               {"don't miss out", 2},
                               {"act now", 2},
                               {"PayPal", 2},
                               {"eBay", 2},
                               {"Amazon", 2},
                               {"Bank of America", 2},
                               {"Chase", 2},
                               {"Wells Fargo", 2},
                               {"Citibank", 2},
                               {"American Express", 2},
                               {"Mastercard", 2},
                               // ... (other keywords with associated scores)
                               {"Visa", 2}};
    // Open and read content from a file named "file.txt"
    ifstream file("file.txt");
    string s;
    // Process each line of the file
    while (getline(file, s))
    { // Loop through the predefined keywords and count their occurrences in the text
        for (auto i : words)
        {
            int pos = s.find(i.first);
            while (pos != -1)
            {
                freq[i.first]++;
                pos = s.find(i.first, pos + i.first.length());
            }
        }
    }
    // Close the file
    file.close();
    // Display the frequency of each keyword and their total scores
    for (auto i : freq)
    {
        cout << i.first << endl;
        cout << "Occurrences: " << i.second << " Total: " << i.second * words[i.first] << endl;
    }
    // Calculate and display the total point score for the analyzed content
    long long total = 0;
    for (auto i : freq)
    {
        total += i.second * words[i.first];
    }
    cout << "Total point score: " << total << endl;
}
int main()
{
    // Call the problem12 function to analyze the email content
    problem12();
}