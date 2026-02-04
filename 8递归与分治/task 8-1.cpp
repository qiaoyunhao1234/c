// 支持中文输出
#include <iostream>
#include <windows.h>
using namespace std;

// 递归函数，计算杨辉三角第row行第col列的值（从1开始计数）
int pascalValue(int row, int col) {
    if (col == 1 || col == row) return 1;
    return pascalValue(row - 1, col - 1) + pascalValue(row - 1, col);
}

int main() {
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8，支持中文
    int n;
    cout << "请输入杨辉三角的行数n: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        // 输出空格用于格式化
        for (int k = 0; k < n - i; ++k) cout << ",,";
        for (int j = 1; j <= i; ++j) {
            cout << pascalValue(i, j) << "...";
        }
        cout << endl;
    }
    return 0;
}