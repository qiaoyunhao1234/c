#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN=10001;
vector<int> prime;
bool isPrime[MAXN];
/* void Initial(){
    for(int i=0;i<=MAXN;i++){
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=MAXN;i++){
        if(!isPrime[i]){
            continue;
        }
        prime.push_back(i);
        for(int j=i*2;j<=MAXN;j+=i){
            isPrime[j]=false;
        }
    }
    return;
} */
void Initial(){
    for(int i=0;i<=MAXN;i++){
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=MAXN;i++){
        if(isPrime[i]){   
        prime.push_back(i);
            for(int j=i*2;j<=MAXN;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return;
}

int main(){
    Initial();
    int n;
    for(size_t i=0; i<prime.size(); i++){
        cout<<prime[i]<<" ";
        
    } cout<<endl;  
    while(scanf("%d",&n) != EOF){
        int answer=0;
            for(size_t i=0; i < prime.size() && prime[i] <= n; i++) {
                int factor=prime[i];
                while(n % factor == 0) {
                    n /= factor;
                    answer++;
                }
            }
            if(n > 1) {
                answer++;
            }
            printf("%d\n",answer);
    }
    return 0;
}