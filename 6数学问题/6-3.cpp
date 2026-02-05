#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string Divide(string str,int x){
    int remainder=0;
    for(size_t i=0;i<str.size();i++){
        int current=remainder*10+str[i]-'0';
        str[i]=(current/x)+'0';
        remainder=current%x;
    }
    int pos=0;
    while(str[pos]=='0'){
        pos++;
    }
    return str.substr(pos);
}

string Multiple(string str,int x){
    int carry=0;
    for(int i=str.size()-1;i>=0;--i){
        int current=x*(str[i]-'0')+carry;
        str[i]=(current%10)+'0';
        carry=current/10;
    }
    if(carry>0){
        str="1"+str;
    }   
    return str;
}

string Add(string str,int x){
    int carry=x;
    for(int i=str.size()-1;i>=0;--i){
        int current=(str[i]-'0')+carry;
        str[i]=(current%10)+'0';
        carry=current/10;
        } 
        if(carry!=0){
            str="1"+str;
    }
    return str;
}



int main(){
    string str;
    while(cin>>str){
        vector<int> binary;
        while(str.size()!=0){
            int last=str[str.size()-1]-'0';
            binary.push_back(last % 2);
            str=Divide(str,2);
        }
        string answer="0";
        for(size_t i=0;i<binary.size();i++){
            answer=Multiple(answer,2);          //字符串形式 乘法
            answer=Add(answer,binary[i]);       //字符串形式 加法
        }
        cout<<answer<<endl;
    }
    return 0;
}