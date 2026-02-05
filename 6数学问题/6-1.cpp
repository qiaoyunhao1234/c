#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        vector<int> binary;
        while(a!=0){
            binary.push_back(a%2);
            a/=2;
        }
        for(int i=binary.size()-1;i>=0;--i){
            printf("%d",binary[i]);
        }
        printf("\n");
    }
    return 0;
}