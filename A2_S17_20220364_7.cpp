// File: A2_S17_20220364_7.cpp
// Purpose:calculate the prime numbers from 1 to n number
// Author: Nour El-dien Mohamed Rabie
// Section: s17
// ID: 20220364
// TA: rana abdelkader
// Date: 12 Oct 2023
BigReal BigReal::operator+(BigReal Realnum) {
    if (Realnum.Sign == Sign) {
        BigReal answer;
        answer.Sign = Sign;
        answer.num = "";
        string Before_dec1 = "";
        string After_dec1 = "";
       string Before_dec2 = "";
        string After_dec2 = "";

        bool check_valid{0};

        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '.') {
                check_valid = 1;
                continue;
            }
            if (!check_valid)
                Before_dec1 += num[i];
            else
                After_dec1 += num[i];
        }
        check_valid = 0;
        for (int i = 0; i < Realnum.num.size(); i++) {
            if (Realnum.num[i] == '.') {
                check_valid = true;
                continue;
            }
            if (!check_valid)
                Before_dec2 += Realnum.num[i];
            else
                After_dec2 += Realnum.num[i];
        }

        //Filling the zeros
        while (Before_dec1.size() < Before_dec2.size()) Before_dec1 = '0' + Before_dec1;
        while (Before_dec1.size() > Before_dec2.size()) Before_dec2 = '0' + Before_dec2;
        while (After_dec1.size() < After_dec2.size()) After_dec1 = After_dec1 + '0';
        while (After_dec1.size() > After_dec2.size()) After_dec2 = After_dec2 + '0';
        //adding The after
        int carry = 0;

        for (int i = After_dec2.size() - 1; i >= 0; i--) {
            answer.num = ((char) (((After_dec2[i] - '0' + After_dec1[i] - '0' + carry) % 10) + '0')) + answer.num;
            carry = (After_dec2[i] - '0' + After_dec1[i] - '0' + carry) / 10;
        }

        answer.num = '.' + answer.num;

        for (int i = Before_dec2.size() - 1; i >= 0; i--) {
            answer.num =
                    ((char) (((Before_dec2[i] - '0' + Before_dec1[i] - '0' + carry) % 10) + '0')) + answer.num;
            carry = (Before_dec2[i] - '0' + Before_dec1[i] - '0' + carry) / 10;
        }

       if (carry != 0) {
            answer.num = (char) (carry + '0') + answer.num;
        }
        //Debugging . at the end
        if (answer.num.back() == '.') answer.num.pop_back();


        return answer;
    }
    else {
        // We Will Change The sign because the (-) operator changes the sign of the input
        if (Realnum.Sign == '+')    Realnum.Sign = '-';
        else    Realnum.Sign = '+';
        return BigReal::operator-(Realnum);
    }
}