#include "biGreal.h"
using namespace std;
//___________________________________________________________
BigReal::BigReal(string real)
{
    if (regex_match(real, regex("[+-]?\\d*.?\\d+")))
    {
        if (real[0] == '-')
        {
            sign = '-';
            real.erase(0, 1);
        }
        else if (real[0] == '+')
        {
            real.erase(0, 1);
        }

        if (real[0] == '.')
        {
            integer = "0";
            fraction = real.substr(1, real.size() - 1);
        }
        else if (real.find(".") != string::npos)
        {
            integer = real.substr(0, real.find("."));
            fraction = real.substr(real.find(".") + 1, real.size() - 1);
        }
        else
        {
            integer = real;
            fraction = "0";
        }
    }
    while (integer[0] == '0')
    {
        integer.erase(0, 1);
    }
    while (fraction[fraction.size() - 1] == '0' && fraction.size() > 1)
    {
        fraction.erase(fraction.size() - 1, 1);
    }
    if (integer.size() == 0)
        integer = "0";
    if (fraction.size() == 0)
        fraction = "0";
}
//___________________________________________________________
bool BigReal::operator<(BigReal anotherReal)
{
    if (sign == '-' && anotherReal.sign == '+')
    {
        return true;
    }
    else if (sign == '+' && anotherReal.sign == '+')
    {
        if (integer < anotherReal.integer)
        {
            return true;
        }
        else if (integer == anotherReal.integer)
        {
            if (fraction < anotherReal.fraction)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else if (sign == '-' && anotherReal.sign == '-')
    {
        if (integer > anotherReal.integer)
        {
            return true;
        }
        if (integer == anotherReal.integer)
        {
            if (fraction > anotherReal.fraction)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool BigReal::operator>(BigReal anotherReal)
{
    if (sign == '+' && anotherReal.sign == '-')
    {
        return true;
    }
    else if (sign == '+' && anotherReal.sign == '+')
    {
        if (integer > anotherReal.integer)
        {
            return true;
        }
        else if (integer == anotherReal.integer)
        {
            if (fraction > anotherReal.fraction)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else if (sign == '-' && anotherReal.sign == '-')
    {
        if (integer < anotherReal.integer)
        {
            return true;
        }
        if (integer == anotherReal.integer)
        {
            if (fraction < anotherReal.fraction)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool BigReal::operator==(BigReal anotherReal)
{
    if (sign == anotherReal.sign && integer == anotherReal.integer && fraction == anotherReal.fraction)
    {
        return true;
    }
    else
    {
        return false;
    }
}