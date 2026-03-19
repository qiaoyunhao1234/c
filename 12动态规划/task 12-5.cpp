#include <iostream>
#include <vector>
#define MAXM 101
#define MAXN 21
#define MAX 99999
using namespace std;
int main() {
    //dp数组初始化
    int dp[MAXN][MAXM];
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXM; j++) {
            dp[i][j] = MAX;
        }
    }
    for (int i = 0; i < MAXN; i++)dp[i][0] = 0; //当面额为0时，不需要邮票
    int M;//总值
    cin >> M;
    int N;//邮票数
    cin >> N;
    vector<int> stamps;//邮票的面值
    int stamp;
    for (int i = 1; i <= N; i++) {
        cin >> stamp;
        stamps.push_back(stamp);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) { //考虑前i张邮票,总值为j
            if (stamps[i - 1] <= j) { //要么选，要么不选
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - stamps[i - 1]] + 1);
            } else { //若当前面值大于总值,赋予用更小的面值凑成总值的结果。
                dp[i][j] = dp[i - 1][j];
                continue;
            }
        }
    }
    if (dp[N][M] != MAX) {
        cout << dp[N][M] << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}