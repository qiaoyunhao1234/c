#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN=10001;
vector<int> prime;
bool isPrime[MAXN];

void Initial(){
    for(int i=0;i<MAXN;++i){
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<MAXN;i++){
        if(!isPrime[i]){
            continue;
        }
        prime.push_back(i);

        for(int j=i*i;j<MAXN;j+=i){
            isPrime[j]=false;
        }
    }
    return;
}
int countDivisors(int x) {
    int cnt = 1;
    for (size_t i = 0; i < prime.size() && prime[i] * prime[i] <= x; ++i) {
        int p = prime[i];
        int exp = 0;
        while (x % p == 0) {
            x /= p;
            ++exp;
        }
        cnt *= (exp + 1);
    }
    if (x > 1) cnt *= 2;
    return cnt;
}

int main() {
    Initial();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << countDivisors(x) << endl;
    }
    return 0;
}
