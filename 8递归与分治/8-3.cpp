#include <iostream>
#include<cstdio>
using namespace std;


long long Fibonacci(int n){
    if(n == 1 || n == 0){
        return n;             //递归终止条件
    }else{
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",Fibonacci(n));
    }
    return 0;
}