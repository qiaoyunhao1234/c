#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int INF = INT_MAX / 10;
const int MAXN = 10000;
int dp[MAXN];
int v[MAXN]; // 物品价值
int w[MAXN]; // 物品重量
int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--)
    {
        int e, f;
        scanf("%d%d", &e, &f);
        int m = f - e; // 背包容量
        int n;         // 物品种类
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &v[i], &w[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            dp[i] = INF; // 注意初始化
        }
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = w[i]; j <= m; ++j)
            {
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        if (dp[m] == INF)
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",
                   dp[m]);
        }
    }
    return 0;
}