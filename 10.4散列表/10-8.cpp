#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string,string> dictionary;


int main(){
    string str;
    while(getline(cin,str)){
        if(str=="@END@"){
            break;
        }
        int pos=str.find("]");
        string key=str.substr(0,pos+1);
        string value=str.substr(pos+2);
        dictionary[key]=value;
        dictionary[value]=key;
    }
    int n;
    scanf("%d", &n);
    getchar(); //吃掉回车
    while(n--){
        string key;
        getline(cin,key);
        string answer=dictionary[key];
        if(answer==""){
            answer="What?";
        }else if(answer[0]=='['){
            answer=answer.substr(1,answer.size()-2);
        }
    }return 0;

}