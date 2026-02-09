#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include<climits>


using namespace std;

const int MAXN=200;
const int INF=INT_MAX;       //表示无穷大，很大的数


struct Edge{
    int to;
    int length;
    Edge(int t,int l):to(t),length(l){}
};
struct Point{
    int number;
    int distance;
    Point(int n,int d):number(n),distance(d){}
    bool operator < (const Point &a) const{   //重载小于号，优先队列默认是大顶堆
        return distance>a.distance;           //所以这里要反过来写
    }        //当前distance比另一个distance大时，当前对象被认为小于另一个对象
};           //重载小于号是为了让优先队列按照从小到大排序
             //priority_queue只认小于号<;


vector<Edge> graph[MAXN];    //类型是vector<Edge>;邻接表存图
int dis[MAXN];


void Dijkstra(int s){
    priority_queue<Point>myPriorityQueue;       //使用优先队列，因为每次要选最近的
    dis[s]=0;
    myPriorityQueue.push(Point(s,dis[s]));       //存入起点和距离，根据原点知道已知点到该点的距离，可快速找到最近的点
    while(!myPriorityQueue.empty()){
        //经典先存入一个变量，再弹出
        int u=myPriorityQueue.top().number;       //因为是优先队列，所以只需要top，
        myPriorityQueue.pop();
        
        for(size_t i=0;i<graph[u].size();i++){     //遍历u的所有边
            int v=graph[u][i].to;
            int d=graph[u][i].length;
            if(dis[u]+d<dis[v]){                //由于main中添加有了u到v距离是d这条路，看看是不是可以更新一下dis数组
                dis[v]=dis[u]+d;                //更新为最短距离，即s点到to点最短距离
                myPriorityQueue.push(Point(v,dis[v]));   //又有了明确了当前最短距离的即可放进优先队列
            }
        }
    }
    return;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(graph,0,sizeof(graph));    //将邻接表清零
        fill(dis,dis+n,INF);
        while(m--){
            int from,to,length;
            scanf("%d%d%d",&from,&to,&length);
            graph[from].push_back(Edge(to,length));
            graph[to].push_back(Edge(from,length));
        }    //先把已有边形成的各个点之间的距离存进邻接表；

        int s,t;
        scanf("%d%d",&s,&t);
        Dijkstra(s);
        if(dis[t]==INF){
            dis[t]=-1;
        } 
        printf("%d\n", dis[t]);
    }
    return 0;
}
