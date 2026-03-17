#include<iostream>
#include<cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN=1001;
const int INF=INT_MAX;
struct Edge{
    int to;
    int length;
    Edge(int t,int l):to(t),length(l){}
};

vector<Edge> graph[MAXN];
int earliest[MAXN];
int latest[MAXN];
int inDegree[MAXN];

void CriticalPath(int n){
    vector<int> topology;
    queue<int>node;
    for(int i=0;i<n;++i){
        if(inDegree[i]==0){
            node.push(i);
            earliest[i]=1;
        }
    }
    while(!node.empty()){
        int u=node.front();
        topology.push_back(u);
        node.pop();
        for(int i=0;i<graph[u].size();++i){
            int v=graph[u][i].to;
            int l=graph[u][i].length;
            earliest[v]=max(earliest[v],earliest[u]+l);
            inDegree[v]--;
            if(inDegree[v]==0){
                node.push(v);
            }
        }
    }
    for(int i=topology.size()-1;i>=0;--i){
        int u=topology[i];
        if(graph[u].size()==0){
            latest[u]=earliest[u];
        }else{
            latest[u]=INF;
        }
        for(int j=0;j<graph[u].size();j++){
            int v=graph[u][j].to;
            int l=graph[u][j].length;
            latest[u]=min(latest[u],latest[v]-l);
        }
    }

}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(graph,0,sizeof(graph));
        memset(earliest,0,sizeof(earliest));
        memset(latest,0,sizeof(latest));
        memset(inDegree,0,sizeof(inDegree));
        while(m--){
            int from,to,length;
            scanf("%d%d%d",&from,&to,&length);
            graph[from].push_back(Edge(to,length));
            inDegree[to]++;
        }
        CriticalPath(n);
        int answer=0;
        for(int i=0;i<n;i++){
            answer=max(answer,earliest[i]);
        }
        printf("%d\n",answer);
    }
    return 0;
}
