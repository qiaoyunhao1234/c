#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string,string> student;
int main(){
    int n;
    scanf("%d", &n);            //不能用while因为样例中第一个4表示以后4个输入的，第二个5表示以后5个查询的
        getchar();     //吃掉回车？？？
        for(int i=0;i<n;i++){
            string str;
            getline(cin,str);
            int pos=str.find(' ');    //用于分割字符串
            string key=str.substr(0,pos);   //从0开始，长度为pos
            student[key]=str;
        }
        int m;
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            string key;
            cin>>key;
            string answer=student[key];
            if(answer==""){
                answer="No Answer!";
            }
            cout<<answer<<endl;
        }
        return 0;
}