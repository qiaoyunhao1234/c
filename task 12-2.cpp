#include <iostream>
#include<cstdio>
using namespace std;
const int MAXN=10000;
long long arr[MAXN];
long long dp[MAXN];

void Subsequence(int k){
    long long maximum=-1;
    int first=0,last=0,t=0;
    for(int i=0;i<k;i++){
        if(i==0) {dp[i]=arr[i];}
        else if(arr[i]>dp[i-1]+arr[i]){
            dp[i]=arr[i];
            t=i;
        }else{
            dp[i]=dp[i-1]+arr[i];
        }
        if(maximum<dp[i]){
            maximum=dp[i];
            first=t;
            last=i;
        }
    }
    printf("%lld %lld %lld\n", maximum, arr[first], arr[last]);
    
}
int main() {
    int k;
    while(scanf("%d",&k)!=EOF){
        if(k==0){
            break;
        }
        bool allNeg=true; //全负
        for(int i=0;i<k;i++){
            scanf("%lld",&arr[i]);
            if(arr[i]>=0){
                allNeg=false;
            }
        }
        if(allNeg){
            printf("0 %lld %lld\n", arr[0], arr[k-1]);
            continue;
        }
        Subsequence(k);
    }
    return 0;
}
