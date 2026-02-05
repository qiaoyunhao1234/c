#include<iostream>
#include<cstdio>
using namespace std;


//给n个正整数，任取两个数作为分子和分母成最简真分数，求组合数
//分子小于分母，且分子和分母的最大公约数为 1（即分数已经约到最简）

int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

const int MAXN=1000;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int count = 0;
        int arr[MAXN];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i] < arr[j] && GCD(arr[i], arr[j]) == 1) {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}