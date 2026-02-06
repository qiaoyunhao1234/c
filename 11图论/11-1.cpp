#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1000;
int father[maxn];
int height[maxn];
void Initial(int n){
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
        if(height[x]<height[y]){
            father[x]=y;
        }else if(height[y]<height[x]){
            father[y]=x;
        }else{
            father[y]=x;
            height[x]++;
        }
    }
    return;
}

int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%d",&m);
        Initial(n);
        while(m--){
            int x,y;
            scanf("%d",&x);
            scanf("%d",&y);
            Union(x,y);

        }
        int answer=-1;
        for(int i=1;i<=n;i++){
            if(Find(i)==i){   //至少有一个，那就是根，剩下的就是从始至终没有提及的，被冷落的；
                answer++;
            }

        }
        printf("%d\n",answer);

    }
    return 0;

}