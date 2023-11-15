// File: A2_S17_20220364_10.cpp
// Purpose:its change some words that has a Censorship and make it with a * or - or any char that can avoid the Censorship.
// Author: Nour El-dien Mohamed Rabie
// Section: s17
// ID: 20220364
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;
string replace_censored_words(string text, unordered_map<string, string> table)
{
    // take each key and check if it is existed in the text and replace each same word with its alternative
    for (auto word : table)
    {
        string censored = word.first;
        string alternative = word.second;
        int index = text.find(censored); // get the index of the first censored word
        while (index != string::npos)
        {
            text.replace(index, censored.length(), alternative);       // replace from the first char index of the censored word to its lentgh with its alternative
            index = text.find(censored, index + alternative.length()); // get the index of the same censored word starting from the last checked word to derease the time
        }
    }
    return text;
}
int main()
{
    // declare the 3 files
    ifstream inputfile("palestine.txt");
    ifstream tablefile("table_alternative.txt");
    ofstream outputfile("alternative_post.txt");

    unordered_map<string, string> table; // map that has key which is the censored word and value which is its alternative word
    if (tablefile.is_open())
    { // check to know if there is an error
        string censored, alternative;
        while (tablefile >> censored >> alternative)
        { // insert each 2 words in the table file in an element in the map
            table[censored] = alternative;
        }
        tablefile.close();
    }
    else
    {
        cout << "Failed to open table file." << endl;
        return 0;
    }
    string text = "";
    if (inputfile.is_open())
    { // check to know if there is an error
        string line;
        while (getline(inputfile, line))
        { // put the input file line by line in text to change it later
            text += line + '\n';
        }
        inputfile.close();
    }
    else
    {
        cout << "Failed to open input file." << endl; // error
        return 0;
    }

    if (outputfile.is_open())
    {                                                           // check to know if there is an error
        string finalText = replace_censored_words(text, table); // call the function to replace the censored words
        for (auto c : finalText)
        { // put each single character in the outputfile
            outputfile << c;
        }
        outputfile.close();
    }
    else
    {
        cout << "Failed to open output file." << endl; // error
        return 0;
    }
}