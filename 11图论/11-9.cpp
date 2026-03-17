#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN=501;
vector<int> graph[MAXN];
int inDegree[MAXN];    //入度

vector<int> TopologicalSort(int n){
    vector<int>topology;   //用于输出最终排名
    priority_queue<int,vector<int>,greater<int>> node;     //小根堆，每次访问或取出为最小值
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            node.push(i);
        }
    }

    while(!node.empty()){
        int u=node.top();
        node.pop();     //弹出最强的

        topology.push_back(u);   //最强的放进去

        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            inDegree[v]--;

            if(inDegree[v]==0){
                node.push(v);
            }
        }
    }
    return topology;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(graph,0,sizeof(graph));   //初始化vector graph
        memset(inDegree,0,sizeof(inDegree));
        while(m--){
            int from,to;
            scanf("%d%d",&from,&to);
            graph[from].push_back(to);     //邻接表
            inDegree[to]++;
        }
        vector<int> answer=TopologicalSort(n);

        //输出最终排名
        for(int i =0;i<answer.size();i++){
            if(i==0){
                printf("%d",answer[i]);
            }else{
                printf(" %d",answer[i]);
            }
        }
        printf("\n");
    }
    return 0;
    


}


