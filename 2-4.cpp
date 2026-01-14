#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int h;
    while(scanf("%d", &h) != EOF) {
        int rows = h;
        int cols = h + 2 * (h - 1);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(j<cols-(h+2*i)){
                    printf(" ");
                } else {
                    printf("*");
                }
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}