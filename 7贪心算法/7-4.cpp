#include<iostream>
#include<cstdio>
#include<algorithm> //sort
using namespace std;

struct Program{
    int startTime;
    int endTime;
};

const int MAXN= 100;
Program arr[MAXN];


bool Compare(Program x,Program y){
    return x.endTime<y.endTime;
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if (n==0){
            break;
        }
        for(int i=0;i<n;++i){
            scanf("%d%d",&arr[i].startTime,&arr[i].endTime);
        }            //将信息填入数组
        sort(arr,arr+n,Compare); //将数组进行排序

        //前期工作完成，开始计算
        int currentTime=0;
        int answer=0;
        for(int i=0;i<n;i++){
            if(currentTime<=arr[i].startTime){
                currentTime=arr[i].endTime;
                answer++;
            }
        }
        printf("%d",answer);
    }
    return 0;
}