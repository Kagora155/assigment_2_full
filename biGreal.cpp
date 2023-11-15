#include "biGreal.h"
using namespace std;
//___________________________________________________________
BigReal::BigReal(string real) {
    if (regex_match(real, regex("[+-]?\\d*.?\\d+"))) {
        if (real[0] == '-') {
            sign = '-';
            real.erase(0, 1);
        }
        else if (real[0] == '+') {
            real.erase(0, 1);
        }


        if (real[0] == '.') {
            integer = "0";
            fraction = real.substr(1, real.size() - 1);
        }
        else if (real.find(".") != string::npos) {
            integer = real.substr(0, real.find("."));
            fraction = real.substr(real.find(".") + 1, real.size() - 1);
        }
        else {
            integer = real;
            fraction = "0";
        }
    }
    while (integer[0] == '0') { integer.erase(0, 1); }
    while (fraction[fraction.size() - 1] == '0' && fraction.size() > 1) { fraction.erase(fraction.size() - 1, 1); }
    if (integer.size() == 0)integer = "0";
    if (fraction.size() == 0)fraction = "0";

}
//___________________________________________________________
bool BigReal:: operator< (BigReal anotherReal) {
    if (sign == '-' && anotherReal.sign == '+') {
        return true;
    }
    else if (sign == '+' && anotherReal.sign == '+') {
        if (integer < anotherReal.integer) {
            return true;
        }
        else if (integer == anotherReal.integer) {
            if (fraction < anotherReal.fraction) {
                return true;
            }
        }
       else {
           return false;
            }
    }
    else if (sign == '-' && anotherReal.sign == '-') {
        if (integer > anotherReal.integer) {
            return true;
        }
        if (integer == anotherReal.integer) {
            if (fraction > anotherReal.fraction) {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool BigReal:: operator > (BigReal anotherReal) {
    if (sign == '+' && anotherReal.sign == '-') {
        return true;
    }
    else if (sign == '+' && anotherReal.sign == '+') {
        if (integer > anotherReal.integer) {
            return true;
        }
        else if (integer == anotherReal.integer) {
            if (fraction > anotherReal.fraction) {
                return true;
            }

        }
        else { return false; }

    }
    else if (sign == '-' && anotherReal.sign == '-') {
        if (integer < anotherReal.integer) {
            return true;
        }
        if (integer == anotherReal.integer) {
            if (fraction < anotherReal.fraction) {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool BigReal:: operator == (BigReal anotherReal) {
    if (sign == anotherReal.sign && integer == anotherReal.integer && fraction == anotherReal.fraction) {
        return true;
    }
    else {
        return false;
    }
}


BigReal BigReal::operator+(BigReal anotherReal) {
    BigReal res, cup;
    bool bigger = false;
    if (sign == anotherReal.sign) {
        int carry = 0, int_size; char temp;
        int SIze;
        res.sign = sign;
        if (integer.size() > anotherReal.integer.size())
        {
            SIze = integer.size() - anotherReal.integer.size();
            for (int i = 0; i < SIze; ++i) {
                anotherReal.integer = "0" + anotherReal.integer;
            }
        }
        else if (anotherReal.integer.size() > integer.size()) {
            SIze = anotherReal.integer.size() - integer.size();
            for (int i = 0; i < SIze; ++i) {
                integer = "0" + integer;
            }
        }

        if (fraction.size() > anotherReal.fraction.size())
        {
            res.fraction = fraction.substr(anotherReal.fraction.size(), fraction.size() - 1);
        }
        else
        {
            res.fraction = anotherReal.fraction.substr(fraction.size(), anotherReal.fraction.size() - 1);
        }
        int common = fraction.size();
        if (fraction.size() > anotherReal.fraction.size()) {
            common = anotherReal.fraction.size();
        }
        else {
            common = fraction.size();
        }
        for (int i = common - 1; i >= 0; i--) {
            temp = carry + fraction[i] + anotherReal.fraction[i] - '0';
            carry = 0;
            if (temp > '9') {
                carry = 1;
                temp -= 10;
            }
            res.fraction = temp + res.fraction;
        }
        //------------------------------------------------------------
        if (integer.size() > anotherReal.integer.size()) {
            int_size = anotherReal.integer.size();
        }
        else {
            int_size = integer.size();
        }
        for (int i = int_size - 1; i >= 0; i--) {
            temp = carry + integer[i] + anotherReal.integer[i] - '0';
            carry = 0;
            if (temp > '9') {
                carry = 1;
                temp -= 10;
            }
            res.integer = temp + res.integer;
        }
        if (carry == 1) {
            res.integer = "1" + res.integer;
        }

    }
        //-----------------------------------------------------------------------------------
    else {
        res.sign = sign;
        if (integer > anotherReal.integer) {
            bigger = true;
        }
        else if (integer == anotherReal.integer) {
            if (fraction > anotherReal.fraction) {
                bigger = true;
            }
        }

        if (bigger == false) {
            cup.integer = integer; cup.fraction = fraction;
            integer = anotherReal.integer; fraction = anotherReal.fraction;
            anotherReal.integer = cup.integer; anotherReal.fraction = cup.fraction;
            res.sign = anotherReal.sign;
        }
        int SIze;
        if (fraction.size() > anotherReal.fraction.size())
        {
            SIze = fraction.size() - anotherReal.fraction.size();
            for (int i = 0; i < SIze; ++i) {
                anotherReal.fraction += "0";
            }
        }
        else if (anotherReal.fraction.size() > fraction.size()) {
            SIze = anotherReal.fraction.size() - fraction.size();
            for (int i = 0; i < SIze; ++i) {
                fraction += "0";
            }
        }
        //----------------------------------------
        if (fraction.size() > anotherReal.fraction.size())
        {
            res.fraction = fraction.substr(anotherReal.fraction.size(), fraction.size() - 1);
        }
        else
        {
            res.fraction = anotherReal.fraction.substr(fraction.size(), anotherReal.fraction.size() - 1);
        }
        int common;
        if (fraction.size() > anotherReal.fraction.size()) {
            common = anotherReal.fraction.size();
        }
        else
            common = fraction.size();
        int temp, borrow = 0;
        for (int i = common - 1; i >= 0; --i) {
            temp = fraction[i] - anotherReal.fraction[i] - borrow;
            if (temp < 0)
            {
                temp += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            res.fraction = char(temp + '0') + res.fraction;
        }
        SIze = integer.size() - anotherReal.integer.size();
        for (int i = 0; i < SIze; ++i) {
            anotherReal.integer = "0" + anotherReal.integer;
        }
        for (int i = integer.size() - 1; i >= 0; --i) {
            temp = integer[i] - anotherReal.integer[i] - borrow;
            if (temp < 0)
            {
                temp += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            res.integer = char(temp + '0') + res.integer;
        }


    }
    return  res;
}

BigReal BigReal::operator-(BigReal anotherReal) {
    BigReal res;
    if (anotherReal.sign == '+') anotherReal.sign = '-';
   else if (anotherReal.sign == '-') anotherReal.sign = '+';


    BigReal cup;
    bool bigger = false;
    if (sign == anotherReal.sign) {
        int carry = 0, int_size; char temp;
        int SIze;
        res.sign = sign;
        if (integer.size() > anotherReal.integer.size())
        {
            SIze = integer.size() - anotherReal.integer.size();
            for (int i = 0; i < SIze; ++i) {
                anotherReal.integer = "0" + anotherReal.integer;
            }
        }
        else if (anotherReal.integer.size() > integer.size()) {
            SIze = anotherReal.integer.size() - integer.size();
            for (int i = 0; i < SIze; ++i) {
                integer = "0" + integer;
            }
        }

        if (fraction.size() > anotherReal.fraction.size())
        {
            res.fraction = fraction.substr(anotherReal.fraction.size(), fraction.size() - 1);
        }
        else
        {
            res.fraction = anotherReal.fraction.substr(fraction.size(), anotherReal.fraction.size() - 1);
        }
        int common = fraction.size();
        if (fraction.size() > anotherReal.fraction.size()) {
            common = anotherReal.fraction.size();
        }
        else {
            common = fraction.size();
        }
        for (int i = common - 1; i >= 0; i--) {
            temp = carry + fraction[i] + anotherReal.fraction[i] - '0';
            carry = 0;
            if (temp > '9') {
                carry = 1;
                temp -= 10;
            }
            res.fraction = temp + res.fraction;
        }
        //------------------------------------------------------------
        if (integer.size() > anotherReal.integer.size()) {
            int_size = anotherReal.integer.size();
        }
        else {
            int_size = integer.size();
        }
        for (int i = int_size - 1; i >= 0; i--) {
            temp = carry + integer[i] + anotherReal.integer[i] - '0';
            carry = 0;
            if (temp > '9') {
                carry = 1;
                temp -= 10;
            }
            res.integer = temp + res.integer;
        }
        if (carry == 1) {
            res.integer = "1" + res.integer;
        }

    }
        //-----------------------------------------------------------------------------------
    else {
        res.sign = sign;
        if (integer > anotherReal.integer) {
            bigger = true;
        }
        else if (integer == anotherReal.integer) {
            if (fraction > anotherReal.fraction) {
                bigger = true;
            }
        }

        if (bigger == false) {
            cup.integer = integer; cup.fraction = fraction;
            integer = anotherReal.integer; fraction = anotherReal.fraction;
            anotherReal.integer = cup.integer; anotherReal.fraction = cup.fraction;
            res.sign = anotherReal.sign;
        }
        int SIze;
        if (fraction.size() > anotherReal.fraction.size())
        {
            SIze = fraction.size() - anotherReal.fraction.size();
            for (int i = 0; i < SIze; ++i) {
                anotherReal.fraction += "0";
            }
        }
        else if (anotherReal.fraction.size() > fraction.size()) {
            SIze = anotherReal.fraction.size() - fraction.size();
            for (int i = 0; i < SIze; ++i) {
                fraction += "0";
            }
        }
        //----------------------------------------
        if (fraction.size() > anotherReal.fraction.size())
        {
            res.fraction = fraction.substr(anotherReal.fraction.size(), fraction.size() - 1);
        }
        else
        {
            res.fraction = anotherReal.fraction.substr(fraction.size(), anotherReal.fraction.size() - 1);
        }
        int common;
        if (fraction.size() > anotherReal.fraction.size()) {
            common = anotherReal.fraction.size();
        }
        else
            common = fraction.size();
        int temp, borrow = 0;
        for (int i = common - 1; i >= 0; --i) {
            temp = fraction[i] - anotherReal.fraction[i] - borrow;
            if (temp < 0)
            {
                temp += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            res.fraction = char(temp + '0') + res.fraction;
        }
        SIze = integer.size() - anotherReal.integer.size();
        for (int i = 0; i < SIze; ++i) {
            anotherReal.integer = "0" + anotherReal.integer;
        }
        for (int i = integer.size() - 1; i >= 0; --i) {
            temp = integer[i] - anotherReal.integer[i] - borrow;
            if (temp < 0)
            {
                temp += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            res.integer = char(temp + '0') + res.integer;
        }


    }

    return  res;
}
void BigReal:: print (){
    cout<<sign<<integer<<"."<<fraction;
}

BigReal::BigReal() {
sign='+';
integer="";
fraction="";
}
bool BigReal::isValidReal(string realNum) {
    if(realNum.empty()){//if the string is empty then it is not valid as a number
        return false;
    }

    if(realNum[realNum.length()-1]=='.'){
        return false;
    }

    string dot;
    for(int i=0;i<realNum.length();++i){
        if((realNum[i]=='+'&&i!=0)||(realNum[i]=='-'&&i!=0)){
            return false;
        }

        if(realNum[i]>='a'&&realNum[i]<='z'){
            return false;
        }
        else  if(!(realNum[i]>='0'&&realNum[i]<='9')&& (realNum[i]!='+')&&(realNum[i]!='-')&&(realNum[i]!='.')){

            return false;

        }

        else if(realNum[i]=='.'){
            if(dot.empty()){
                dot+=realNum[i];
            }
            else{
                return false;//if there is more than one dot
            }
        }
    }
    return true;
}