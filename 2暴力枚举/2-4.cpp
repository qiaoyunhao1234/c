#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int h;
    while (scanf("%d", &h) != EOF)
    {
        int row = h;               // 行数为 h
        int col = h + (h - 1) * 2; // 列数为最底行中*的数量
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (j < col - (h + 2 * i))
                { // 输出空格
                    printf(" ");
                }
                else
                { // 输出*
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}