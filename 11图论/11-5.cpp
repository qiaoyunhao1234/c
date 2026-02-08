#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Edge{
    int from;
    int to;
    int length;
    bool operator<(const Edge& e) const{
        return length<e.length;
    }
};
const int MAXN=100;
int father[MAXN];
int height[MAXN];
Edge edge[MAXN*MAXN];


void initial(int n){
    for(int i=0;i<n;i++){
        father[i]=i;
        height[i]=0;
    }
}

int Find(int x){
    if(x!=father[x]){
        father[x]=Find(father[x]);
    }
    return father[x];
}

void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        if(height[x]<height[y]) father[x]=y;
        else if(height[x]>height[y]) father[y]=x;
        else father[y]=x;height[x]++;
    }
    return;
}

int Kruskal(int n,int edgeNumber){
    initial(n);
    sort(edge,edge+edgeNumber);
    int sum=0;
    for(int i=0;i<edgeNumber;i++){
        Edge current=edge[i];
        if(Find(current.from)!=Find(current.to));{
            Union(current.from,current.to);
            sum+=current.length;
        }
    }
    return sum;
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        int edgeNumber=n*(n-1)/2;
        for(int i=0;i<edgeNumber;i++){
            int status;
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].length,&status);
            if(status==1){
                edge[i].length=0;
            }
        }
        int answer=Kruskal(n,edgeNumber);
        printf("%d\n",answer);
    }
    return 0;
}