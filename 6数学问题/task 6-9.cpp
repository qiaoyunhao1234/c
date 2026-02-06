#include<iostream>
#include<cstdio>
using namespace std;
int QuickPower(int x,int y,int n){    //取x^y的n进制的个位数
    int ans=1;
    while(y){
        if(y%2){
            ans*=x;
            ans%=n;
        }
        y/=2;
        x%=n;
        x*=x;
    }
    return ans;
}
int main(){
    int x,y,k;
    while(scanf("%d%d%d",&x,&y,&k)!=EOF){
        if(QuickPower(x, y, k-1))printf("%d\n",QuickPower(x, y, k-1));
        else printf("%d\n",k-1);
    }
    return 0;
}