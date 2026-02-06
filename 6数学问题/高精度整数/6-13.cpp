#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 10000;

struct Biginteger{
    int digit[MAXN];
    int length;
    Biginteger() {
        memset(digit, 0, sizeof(digit));
        length = 0;
    }
    Biginteger(string str) {
        memset(digit, 0, sizeof(digit));
        length = str.size();
        for(int i = 0; i < length; i++) {
            digit[i] = str[length - 1 - i] - '0';
        }
    }
    Biginteger& operator=(const string& str) {
        memset(digit, 0, sizeof(digit));
        length = str.size();
        for(int i = 0; i < length; i++) {
            digit[i] = str[length - 1 - i] - '0';
        }
        return *this;
    }
    Biginteger operator+(const Biginteger &b) const {
        Biginteger answer;
        answer.length = 0;
        int carry = 0;
        int maxlen = max(length, b.length);
        for(int i = 0; i < maxlen; i++) {
            int a_digit = (i < length) ? digit[i] : 0;
            int b_digit = (i < b.length) ? b.digit[i] : 0;
            int current = carry + a_digit + b_digit;
            answer.digit[answer.length++] = current % 10;
            carry = current / 10;
        }
        if(carry != 0) {
            answer.digit[answer.length++] = carry;
        }
        return answer;
    }
    friend istream& operator>>(istream& in, Biginteger &x);
    friend ostream& operator<<(ostream& out, const Biginteger &x);
};

istream& operator>>(istream& in, Biginteger& x) {
    string str;
    in >> str;
    x = str;
    return in;
}

ostream& operator<<(ostream& out, const Biginteger &x) {
    if(x.length == 0) {
        out << 0;
        return out;
    }
    for(int i = x.length - 1; i >= 0; i--) {
        out << x.digit[i];
    }
    return out;
}

int main() {
    Biginteger A, B;
    while(cin >> A >> B) {
        Biginteger C = A + B;
        cout << C << endl;
    }
    return 0;
}