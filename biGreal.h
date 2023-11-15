#pragma once


#include <iostream>
#include <string>
#include <regex>

using namespace std;

class BigReal {
private:
    char sign = '+';
    string integer = "", fraction;

public:
    bool isValidReal(string realNum);
    BigReal ();
    BigReal(string);
    bool operator==(BigReal anotherReal);
    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    BigReal operator+ (BigReal anotherReal);
    BigReal operator- (BigReal anotherReal);
    friend ostream& operator << (ostream& out,const BigReal& num);
    void print ();



};
ostream &operator<<(ostream &out, const BigReal& num) {
    out <<num.sign<<num.integer<<"."<<num.fraction;
    return out;
}