#include<iostream>
#include<cstdio>

using namespace std;
int Reserve(int x){
    int revx=0;
    while(x!=0){
        revx*=10;
        revx+=x%10;
        x/=10;
    }
    return revx;
}
int main(){
    for(int i=1000;i<=9999;i++){
        if(i*9==Reserve(i)){
            printf("%d\n",i);
        }
    }
    return 0;
}