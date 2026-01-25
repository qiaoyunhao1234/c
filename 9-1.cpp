#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=100001;
struct Status{
    int n,t;
    Status(int n,int t):n(n),t(t){}
};
bool visit[MAXN];
int BFS(int n,int k){
    queue<Status> myQueue;
    myQueue.push(Status(n,0));
    visit[n]=true;
    while(!myQueue.empty()){
        Status current=myQueue.front();
        myQueue.pop();
        if(current.n==k){
            return current.t;
        }
        for(int i=0;i<3;++i){
            Status next(current.n,current.t+1);
            if(i==0){
                next.n+=1;
            }else if(i==1){
                next.n-=1;
            }else{
                next.n*=2;
            }
            if(next.n<0 || next.n>=MAXN || visit[next.n]){
                continue;
            }
            myQueue.push(next);
            visit[next.n]=true;
        }
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    memset(visit,false,sizeof(visit));
    printf("%d\n",BFS(n,k));
    return 0;   
}
