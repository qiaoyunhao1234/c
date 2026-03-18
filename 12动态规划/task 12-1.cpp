#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN=20;
long long dp[MAXN];

int main(){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<MAXN;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",dp[n]);
    }
}
