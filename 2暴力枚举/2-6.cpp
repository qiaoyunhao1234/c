#include<iostream>
#include<cstdio>
#include<vector>
// 八皇后问题

using namespace std;
vector<vector<int>>queenVec;
void DFS(vector<int>&queen,int pos){
    for(int i=1;i<=8;i++){
        bool isOK=true;
        for(int j=0;j<pos;j++){
            if(queen[j]==i||queen[j]-i==j-pos||j-pos==i-queen[j]){
                isOK=false;
                break;//跳出遍历已有皇后的循环
            }
        }
        if(isOK==true){
            queen.push_back(i);
            if(pos==7){
                queenVec.push_back(queen);
                printf("\"");
                printf("\",\n");

            }else{
                DFS(queen,pos+1);
            }
            queen.pop_back();

        }
    }

}
int main(){
    vector<int> queen;
    
}