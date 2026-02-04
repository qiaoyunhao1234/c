#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1000;

struct JavaBean{
    double weight;
    double cost;
};

JavaBean arr[MAXN];

bool Compare(JavaBean a,JavaBean b){
    return (a.weight/a.cost)>(b.weight/b.cost);      //单位重量价值高的排前面
}
int main(){
    int m,n;
    while(scanf("%d %d",&m,&n) != EOF){
        if(m==-1&&n==-1){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&arr[i].weight,&arr[i].cost);     //会把输入的值存储到这两个位置。
        }
        sort(arr,arr+n,Compare);


        
        double answer=0;
        for(int i=0;i<n;i++){
            if(m>=arr[i].cost){
                m-=arr[i].cost;
                answer+=arr[i].weight;
            }else{
                answer+=arr[i].weight*(double)m/arr[i].cost;
                break;
            }
        }
        printf("%.2lf\n",answer);
    }
    return 0;
}