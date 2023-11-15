// File: A2_S17_20220039_3.cpp
// Purpose: it make a list of numbers like string and put them into individal string for each of them also the same with list of iteger
// Author:ahmed mahmoud hasaneen
// Section: s17
// ID: 20220039
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to split a string into substrings using a delimiter
vector<string> split(string &target, string &delimiter)
{
    vector<string> result;
    string::size_type start = 0;
    string::size_type end = target.find(delimiter);

    while (end != string::npos)
    {
        result.push_back(target.substr(start, end - start));
        start = end + delimiter.length();
        end = target.find(delimiter, start);
    }

    result.push_back(target.substr(start));

    return result;
}

int main()
{
    string target1, target2;
    string delimiter1 = " ";
    string delimiter2 = " ";

    // Input for target1 and target2
    cout << "Enter target1: ";
    getline(cin, target1);

    cout << "Enter target2: ";
    getline(cin, target2);

    // Split target1 and target2 into substrings
    vector<string> result1 = split(target1, delimiter1);
    vector<string> result2 = split(target2, delimiter2);

    // Construct a formatted string (ss1) for target1
    stringstream ss1;
    for (size_t i = 0; i < result1.size(); ++i)
    {
        if (i == result1.size() - 1 && i > 0)
        {
            ss1 << "and ";
        }
        ss1 << '"' << result1[i] << '"';
        if (i != result1.size() - 1)
        {
            ss1 << " ";
        }
    }

    // Print the formatted string for target1
    cout << ss1.str() << endl;

    // Separator line
    cout << "-----------" << endl;

    // Construct a formatted string (ss2) for target2
    stringstream ss2;
    for (size_t i = 0; i < result2.size(); ++i)
    {
        if (i == result2.size() - 1 && i > 0)
        {
            ss2 << "and ";
        }
        ss2 << '"' << result2[i] << '"';
        if (i != result2.size() - 1)
        {
            ss2 << " ";
        }
    }

    // Print the formatted string for target2
    cout << ss2.str() << endl;

    return 0;
}