#include <iostream>
#include <cstdio>
using namespace std;

struct Matrix{
    int matrix[10][10];
    int row;    
    int col;
    Matrix(int r,int c):row(r),col(c){}
};


Matrix Plus(Matrix A,Matrix B){
    Matrix C(A.row,A.col);
    for(int i=0;i<A.row;i++){
        for(int j=0;j<A.col;j++){
            C.matrix[i][j]=A.matrix[i][j]+B.matrix[i][j];
        }
    }
    return C;
}


int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    Matrix A(r,c);
    Matrix B(r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&A.matrix[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&B.matrix[i][j]);
        }
    }
    Matrix C=Plus(A,B);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<C.matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    int row_zero = 0;
    int col_zero = 0;
    // 统计全为0的行
    for(int i=0;i<r;i++){
        bool all_zero = true;
        for(int j=0;j<c;j++){
            if(C.matrix[i][j]!=0){
                all_zero = false;
                break;
            }
        }
        if(all_zero) row_zero++;
    }
    // 统计全为0的列
    for(int j=0;j<c;j++){
        bool all_zero = true;
        for(int i=0;i<r;i++){
            if(C.matrix[i][j]!=0){
                all_zero = false;
                break;
            }
        }
        if(all_zero) col_zero++;
    }
    printf("%d\n", row_zero+col_zero);
    return 0;
}