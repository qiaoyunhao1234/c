#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        bool flag=false;
        for(int i=2;i*i<=n;++i){
            if(n%i==0){
                flag=true;
                break;
            }
        }
        printf("%s\n",flag?"No":"Yes");
    }
    return 0;
}