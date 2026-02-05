#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string Divide(string str,int x){
    int remainder=0;
    for(int i=0;i<str.size();++i){
        int current=remainder*10+(str[i]-'0');
        str[i]=(current/x)+'0';
        remainder=current%x;
    }
    int pos=0;
    while(str[pos]=='0'){
        pos++;
    }
    return str.substr(pos);
}

int main(){
    string str;
    while(cin>>str){
        vector<int> binary;
        while(str.size() != 0){
            int last =str[str.size()-1]-'0';   //取最低位，因为数太大了
            binary.push_back(last % 2);        //last%2   last只有一位
            str=Divide(str,2);                 //不能用str/2，因为数太大，只能用字符串
        }
        for(int i=binary.size() - 1; i >= 0; --i) {
            printf("%d", binary[i]);
        }
        printf("\n");
    }
    return 0;
}


