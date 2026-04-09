#include<cstdio>
#include<vector>
using namespace std;
int sum=0;
int diff=0;
void DFS(vector<int>&arr,int pos,int sa){
    

}
int main(){
    vector<int>arr;
    int i;
    
    while(scanf("%d",&i)!=EOF){
        arr.push_back(i);
    }
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    diff=sum;
    return 0;
}