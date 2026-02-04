#include <iostream>
#include <cstdio>

using namespace std;

long long Factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n*Factorial(n-1);
    }
}


int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        printf("%lld\n", Factorial(n));
    }
}


