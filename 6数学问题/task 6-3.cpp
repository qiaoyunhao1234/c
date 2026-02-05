#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int CharToInt(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }else if(c>='a'&&c<='f'){
        return c-'a'+10;
    }else{
        return c-'A'+10;
    }
}

int main(){
    string str;
    while(cin>>str){
        int answer = 0;
        // for(int i=0;i<str.size();++i){
        for(char c : str){
            answer*=16;
            answer +=CharToInt(c);
        }
        cout<<answer<<endl;
    }
    return 0;
}