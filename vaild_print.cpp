void BigReal::print()
{
    cout << sign << integer << "." << fraction;
}

BigReal::BigReal()
{
    sign = '+';
    integer = "";
    fraction = "";
}
bool BigReal::isValidReal(string realNum)
{
    if (realNum.empty())
    { // if the string is empty then it is not valid as a number
        return false;
    }

    if (realNum[realNum.length() - 1] == '.')
    {
        return false;
    }

    string dot;
    for (int i = 0; i < realNum.length(); ++i)
    {
        if ((realNum[i] == '+' && i != 0) || (realNum[i] == '-' && i != 0))
        {
            return false;
        }

        if (realNum[i] >= 'a' && realNum[i] <= 'z')
        {
            return false;
        }
        else if (!(realNum[i] >= '0' && realNum[i] <= '9') && (realNum[i] != '+') && (realNum[i] != '-') && (realNum[i] != '.'))
        {

            return false;
        }

        else if (realNum[i] == '.')
        {
            if (dot.empty())
            {
                dot += realNum[i];
            }
            else
            {
                return false; // if there is more than one dot
            }
        }
    }
    return true;
}