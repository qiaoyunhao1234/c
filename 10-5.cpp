#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;



struct Complex{
    int real;
    int imag;
    Complex(int r=0,int i=0):real(r),imag(i){}
    bool operator<(Complex c) const{
        return real*real+imag*imag<c.real*c.real+c.imag*c.imag;    //priority_queue优先队列，要有比较大小
    }
};


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue<Complex> myPriorityQueue;
        while(n--){
            string str;
            cin>>str;
            if(str=="Pop"){
                if(myPriorityQueue.empty()){
                    printf("empty\n");               //empty为true，即为空，输出empty
                }else{
                    Complex current=myPriorityQueue.top();
                    myPriorityQueue.pop();          //弹出栈顶元素,需要先top存起来，再pop弹出
                    printf("%d+i%d\n",current.real,current.imag);
                    printf("SIZE=%d\n",myPriorityQueue.size());
                }
            }else{
                int a,b;
                scanf("%d+i%d",&a,&b);
                myPriorityQueue.push(Complex(a,b));
                printf("SIZE=%d\n",myPriorityQueue.size());
            }
        }
    }
    return 0;
}