#include <iostream>
#include <cstdio>
using namespace std;
int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int gcd=GCD(a,b);
        printf("GCD: %d\n",gcd);
        printf("LCM: %d\n",a/gcd*b);
    }
    return 0;
}