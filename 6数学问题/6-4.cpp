#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int CharTolnt(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }else{
        return c-'A'+10;         //这样的话A表示10，B表示11。。。
    }
}

char IntToChar(int x){
    if(x<10){
        return x+'0';
    }else{
        return x-10+'a';         //10表示a，11表示b。。。
    }
}

int main(){
    int m, n;
    while (true) {
        printf("Please enter the original base and the target base (e.g. 2 16): ");
        if (scanf("%d%d", &m, &n) == EOF) break;
        printf("Please enter the number to convert: ");
        string str;
        cin >> str;
        long long number = 0;
        for (int i = 0; i < str.size(); ++i) {
            number *= m;
            number += CharTolnt(str[i]);
        }
        if (number == 0) {
            printf("0\n");
            continue;
        }
        vector<char> answer;
        while (number != 0) {
            answer.push_back(IntToChar(number % n));
            number /= n;
        }
        printf("Result: ");
        for (int i = answer.size() - 1; i >= 0; --i) {
            cout << answer[i];
        }
        cout << endl;
    }
    return 0;
}