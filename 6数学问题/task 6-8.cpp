#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

// 分解质因数
map<int, int> factorize(int a) {
    map<int, int> factors;
    for (int i = 2; i * i <= a; ++i) {
        while (a % i == 0) {
            factors[i]++;
            a /= i;
        }
    }
    if (a > 1) factors[a]++;
    return factors;
}

// 计算n!中质因数p的幂次
int count_p_in_factorial(int n, int p) {
    int count = 0;
    while (n) {
        n /= p;
        count += n;
    }
    return count;
}

int main() {
    int n, a;
    while (scanf("%d %d", &n, &a) != EOF) {
        map<int, int> factors = factorize(a);
        int k = 1e9;
        for (auto &f : factors) {
            int p = f.first, exp = f.second;
            int cnt = count_p_in_factorial(n, p);
            k = min(k, cnt / exp);
        }
        printf("%d\n", k);
    }
    return 0;
}