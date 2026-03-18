#include<iostream>
#include<cstdio>

using namespace std;
const int MAXN=10000;
int dp[MAXN];  // dp[i]变成了以 A[i]作为末尾的最大上升子序列和
int arr[MAXN];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=arr[i];
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+arr[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}