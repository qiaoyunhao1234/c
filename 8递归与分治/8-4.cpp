#include<iostream>
#include<cstdio>
using namespace std;

int f(int m, int n){
    if (m>n){
        return 0;
    }else{
        return f(2*m,n)+f(2*m+1,n)+1;
    }
}
int main(){
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF){
        printf("%d\n",f(m,n));
    }
    return 0;
}
