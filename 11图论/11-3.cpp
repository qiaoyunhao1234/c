#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 10000;
int father[MAXN];
int height[MAXN];
int inDegree[MAXN];
bool visit[MAXN];

void  init(){
    for (int  i = 0; i <MAXN ; i++){
        father[i] = i;
        height[i] = 0;
        inDegree[i] = 0;
        visit[i] = false;
    }
}

int Find(int x){
    if (father[x] != x){
        father[x] = Find(father[x]);
    }
    return father[x];
}   

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if (x != y){
        if(height[x] < height[y]){
            father[x]= y;
        }else if(height[x] > height[y]){
            father[y] = x;
        }else{
        father[y] = x;
        height[x]++;
        }
    }
    return;
}

bool IsTree(){
    bool flag = true;
    int root = 0;
    int component=0;//看连通分量
    for(int i=0;i<MAXN;i++){
        if(!visit[i]){
            continue;
        }
        if(father[i]==i){
            component++;
        }
        if(inDegree[i]==0){
            root++;
        }else if(inDegree[i]>1){
            flag =false;
        }
    }
    if(component!=1||root!=1){
        flag = false;
    }
    if(component==0&&root==0){
        flag=true;
    }//空树也是树,啥都没有
    return flag;
}

int main(){
    int x,y;
    int caseNumber = 0;
    init();
    while (scanf("%d%d",&x,&y) != EOF){
        if(x==-1&&y==-1){
            break;
        }   
        if(x==0&&y==0){
            if(IsTree()){
                printf("Case %d is a tree.\n", ++caseNumber);
            }else{
                printf("Case %d is not a tree.\n", ++caseNumber);
            }
            init();    //为什么有个init(),按照运行顺序，就是先是下面的，然后就是0，0，每个case算完后要init，最后是-1，-1，break
        }else{
            Union(x,y);
            inDegree[y]++;   //记录入度
            visit[x] = true;
            visit[y] = true;
        }
    }
    return 0;
}



//考虑以下几点：
//1.树是一个连通无环的有向图，所以要检查连通性和入度
//2.树有且仅有一个入度为0的节点（根节点）， 其他节点入度为1
//3.使用并查集检查连通性，连通度要为1
//4.使用visit数组记录出现过的节点，避免遍历整个father和inDegree数组，提高效率（如果例子是100-500）    
//5.空树也是树，啥都没有连通度为0，入度全为0；