#include <iostream>
#include <cstdio>

using namespace std;

/* int main(){
    int a;
    while (scanf("%d",&a) != EOF){
        if(a%2==1){               //不符合
            printf("0 0");
        }else{
            if(a%4==0){
                int max=a/2;
                int min=a/4;
                printf("%d %d",&min,&max);
            }else{
                int max=a/2;
                int min=a/4+1;
                printf("%d %d",&min,&max);
            }
        }
    }
    return 0;
    
} */
int main(){
    int a;
    while(scanf("%d",&a)==1){                //检测到不是整数即退出
    // while(scanf("%d",&a)!=EOF){
        int min=0;
        int max=0;
        if(a%2==0){
            min=a/4+(a%4)/2;               //不能整除4比整除4多1
            max=a/2;           
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}