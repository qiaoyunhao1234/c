#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100001;
long long gun[MAXN];
long long monster[MAXN];

bool Compare(long long x,long long y){
    return x>y;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m); //n把枪，m头怪兽
        for(int i=0;i<n;i++){
            scanf("%lld",&gun[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%lld",&monster[i]);
        }
        sort(gun,gun+n,Compare);
        sort(monster,monster+n);



        long long answer=0;
        for(int i=0;i<n;i++){
            if(i>=m||gun[i]<=monster[i]){
                break;
            }
            answer+=(gun[i]-monster[i]);
        }
        printf("%lld\n",answer);
    }
    return 0;
}