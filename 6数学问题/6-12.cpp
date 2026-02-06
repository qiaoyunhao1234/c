#include <iostream>
#include <cstdio>
using namespace std;

struct Matrix{
    int matrix[10][10];
    int row;    
    int col;
    Matrix(int r,int c):row(r),col(c){}
};


Matrix Multiply(Matrix A,Matrix B){
    Matrix C(A.row,B.col);
    for(int i=0;i<A.row;i++){
        for(int j=0;j<B.col;j++){
            C.matrix[i][j]=0;
            for(int k=0;k<A.col;k++){
                C.matrix[i][j]+=A.matrix[i][k]*B.matrix[k][j];
            }
        }
    }
    return C;
}

void PrintMatrix(Matrix M){
    for(int i=0;i<M.row;i++){
        for(int j=0;j<M.col;j++){
            cout<<M.matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}


Matrix FastExponentiation(Matrix x,int k){
    Matrix answer(x.row,x.col);
    // 紧接着初始化，类似等于1
    for(int i=0;i<answer.row;i++){
        for(int j=0;j<answer.col;j++){
            if(i==j){
                answer.matrix[i][j]=1;
            } else {
                answer.matrix[i][j]=0;
            }
        }
    }


    while(k!=0){
        if(k%2==1){
            answer=Multiply(answer,x);    
        }
        k=k/2;
        x=Multiply(x,x);
    }
    return answer;
    
}


int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        Matrix x(n,n);
        for(int i=0;i<x.row;i++){
            for(int j=0;j<x.col;++j){
                scanf("%d",&x.matrix[i][j]);
            }
        }
        Matrix answer=FastExponentiation(x,k);
        PrintMatrix(answer);
    }
    return 0;
}