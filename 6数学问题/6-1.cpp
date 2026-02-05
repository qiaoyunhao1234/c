#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        int n = a;
        int bits = 0, temp = n;
        while (temp) {
            bits++;
            temp >>= 1;
        }//bits表示二进制位数，7（111）的bits为3
        if (bits == 0) bits = 1; // n为0时特殊处理
        
        int width = ((bits + 3) / 4) * 4; // 补齐到4的倍数


        vector<int> binary;
        temp = n;
        for(int i = 0; i < width; ++i) {
            binary.push_back(temp % 2);
            temp /= 2;
        }
        for(int i = width - 1; i >= 0; --i) {
            printf("%d", binary[i]);
        }
        printf("\n");
    }
    return 0;
}