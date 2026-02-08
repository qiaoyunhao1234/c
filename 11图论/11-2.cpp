#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1000;
int father[MAXN];
int height[MAXN];

void Initial(int n){
    for(int i = 0; i < n; i++) {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x){
    if(x != father[x]){
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        if(height[x]>height[y]){
            father[x]=y;
        } else if(height[x]<height[y]){
            father[y]=x;
        } else {
            father[y]=x;
            height[x]++;
        }
    }
    return;
}

int main() {
    int m, n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) break;
        scanf("%d", &m);
        Initial(n);
        while(m--){
            int x,y;
            scanf("%d", &x);
            scanf("%d", &y);
            Union(x, y);
        }        
        int component=0;
        for(int i=1;i<=n;i++){
            if(Find(i)==i){   
                component++;
            }
        }
        if(component==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
