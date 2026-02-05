#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a+b;
    int m;
    scanf("%d",&m);
    vector<int>res;
    while(c!=0){
        res.push_back(c%m);
        c/=m;
    }
    for(int i=res.size()-1;i>=0;--i){
        printf("%d",res[i]);
    }
    printf("\n");
}
