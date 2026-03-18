// 8
// 186 186 150 200 160 130 197 220
// 4

//最长递增序列        最长递减序列
//186                   186 160 130
//150 160 197 220       无
//150 220              160 130               
//不是先确定哪个开始，而是确定哪个作为山顶
//无          186    150 130
// 无         150
// 186        200    160 130
//150         160    130
#include <iostream>
using namespace std;


//合唱队形
int num[110];
int inde[110];
int dp[110];

int maxincrease(int n){
    for(int i=0;i<110;i++)inde[i]=0;
    for(int i=0;i<=n;i++){
        inde[i]=1;      //找比我小的，没有那就只有本身1
        for(int j=0;j<i;j++){
            if(num[j]<num[i])
                inde[i]=max(inde[i],inde[j]+1);
        }
    }
    return inde[n];
}

int maxdecrease(int k,int n){
    for(int i=0;i<110;i++)inde[i]=0;
    for(int i=n-1;i>=k;i--){
        inde[i]=1;
        for(int j=n-1;j>i;j--){
            if(num[j]<num[i])
                inde[i]=max(inde[i],inde[j]+1);
        }
    }
    return inde[k];
}

int maxinde(int n){
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=maxincrease(i)+maxdecrease(i,n)-1;
        ans=max(dp[i],ans);
    }
    return n-ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int ans=maxinde(n);
    cout<<ans<<endl;
    return 0;
}
