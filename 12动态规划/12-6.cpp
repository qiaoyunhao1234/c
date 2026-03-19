#include <iostream>
#include <cstring>
#include<cstdio>
using namespace std;

const int MAXN=1001;

char s1[MAXN];
char s2[MAXN];
int dp[MAXN][MAXN];

int main(){
    while(scanf("%s%s",s1+1,s2+1)!=EOF){  //下标从1开始
        int n=strlen(s1+1);            //计算字符串长度
        int m=strlen(s2+1);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                    continue;
                }
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}