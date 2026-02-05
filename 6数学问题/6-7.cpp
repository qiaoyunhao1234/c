#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

/* int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        bool flag=false;
        for(int i=2;i*i<=n;++i){
            if(n%i==0){
                flag=true;
                break;
            }
        }
        printf("%s\n",flag?"No":"Yes");
    }
    return 0;
} */


bool judge(int n){
    if(n<2) return false;
    int bound=sqrt(n);
    for(int i=2;i<=bound;++i){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if(judge(n)){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}