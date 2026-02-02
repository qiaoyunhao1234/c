#include <iostream>
#include <cstdio>
#include <queue>
 using namespace std;


 int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,greater<int> > myPriorityQueue;
      /*三个参数"存什么"、"用什么存"、"怎么比"  
      greater<int>将优先队列变成了最小堆。
       也就是说，每次访问队首元素时，得到的都是当前队列中最小的整数
       默认是less<int> */
        while(n--){
            int x;
            scanf("%d",&x);
            myPriorityQueue.push(x);
        }
        int answer=0;
        while(1<myPriorityQueue.size()){
            int a=myPriorityQueue.top();
            myPriorityQueue.pop();
            // 弹出最小的一个
            int b=myPriorityQueue.top();
            myPriorityQueue.pop();
            // 弹出第二小的一个
            answer+=a+b;
            myPriorityQueue.push(a+b);       // 将合并后的新数值放回优先队列
        }
        printf("%d\n",answer);
    }
    return 0;
 }