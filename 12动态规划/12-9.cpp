#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 10000;
int dp[MAXN];
int v[MAXN];      // 物品价值
int w[MAXN];      // 物品质量
int k[MAXN];      // 物品数目
int value[MAXN];  // 分解后物品价值
int weight[MAXN]; // 分解后物品质量
int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--)
    {
        int n, m;
        scanf("%d%d", &m, &n); // n 件物品，m 容量的背包
        int number = 0;        // 分解后物品的数量
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d", &w[i], &v[i], &k[i]);
            for (int j = 1; j <= k[i]; j <<= 1)   //左移，j=1 2 4 8
            {
                value[number] = j * v[i];
                weight[number] = j * w[i];
                number++;
                k[i] -= j;
            }
            if (k[i] > 0)
            {
                value[number] = k[i] * v[i];
                weight[number] = k[i] * w[i];
                number++;
            }
        }
        for (int i = 0; i <= m; ++i)
        {
            dp[i] = 0; // 初始化
        }
        for (int i = 0; i < number; ++i)
        {
            for (int j = m; j >= weight[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}