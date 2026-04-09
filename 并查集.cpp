#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
using namespace std;
int father[1005];
void init(int n){
    for(int i=0;i<n;i++){
        father[i]=i;
    }
}
int find(int x){
    if(father[x]==x){
        return x;
    }else{
        return father[x]=find(father[x]);
    }
}
void Union(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb){
        father[fa]=fb;
    }
}

struct edge{
    int u;
    int v;
    int w;
    edge(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    };

bool compare(edge a,edge b){
    return a.w<b.w;
}
// vector<edge>edgevec;
// int main(){
//     int n,m;
//     while(scanf("%d%d",&n,&m)!=EOF){
//         init(n);
//         edgevec.clear();
//         for(int i=0;i<m;i++){
//             int u,v,w;
//             scanf("%d%d%d",&u,&v,&w);
//             edgevec.push_back(edge(u,v,w));
//         }
//     }
//     sort(edgevec.begin(),edgevec.end(),compare);
// }