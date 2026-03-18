#include <iostream>
#include<cstdio>

using namespace std;

const int MAXN=1000000;
long long arr[MAXN];
long long dp[MAXN];

long long MaxSubsequence(int n){
    long long maximum=0;
    for(int i=0;i<n;i++){
        if(i==0){
            dp[i]=arr[i];
        }else{
            dp[i]=max(arr[i], dp[i-1]+arr[i]);
        }
        maximum=max(maximum, dp[i]);
    }
    return maximum;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        long long answer=MaxSubsequence(n);
        printf("%lld\n",answer);
    }
    return 0;
}