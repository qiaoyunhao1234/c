#include<iostream>
#include<cstdio>
#include<cmath> 
#include<vector>
using namespace std;



/* bool isPrime(int n){
    if(n<2) return false;
    int limit=sqrt(n);
    for(int i=2;i<=limit;++i){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=2;i<=n;++i){
            if(i%10==1){
                if(isPrime(i)){
                    printf("%d ",i);
                }   
            }
        }
    }
    return 0;
} */





//优化后--适用于于多次输入
const int MAXN=10001;
vector<int> prime;
bool isPrime[MAXN];

void Initial(){
    for(int i=0;i<MAXN;++i){
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=MAXN;i++){
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


/*  for(int i=2;i<=MAXN;i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j=i*i;j<MAXN;j+=i){
                isPrime[j]=false;
            }
        }
        return;
    } */
int main(){
    Initial();
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<(int)prime.size()&&prime[i]<=n;++i){
            if(prime[i]%10==1){
                printf("%d ",prime[i]);
            }
        }
        printf("\n");
    }
    return 0;
}