#include <iostream>
#include <cstring>

using namespace std;

// 递推公式构造的矩阵大小为 2*2
const int MAXN = 2;
const int mod = 10000;

// 矩阵类，通用
struct Matrix{
    int matrix[MAXN][MAXN];
    int row, col;
    Matrix(int r, int c):row(r),col(c){
        // 构造函数内将矩阵元素全部初始化为0
        memset(matrix, 0, sizeof(matrix));
    };
};

// 计算矩阵乘法
Matrix Multiply(Matrix x, Matrix y){
    Matrix answer(x.row, y.col);
    for(int i = 0; i<answer.row; i++){
        for(int j = 0; j<answer.col; j++){
            for(int k = 0; k<x.col; k++){
                // 注意中间结果也要进行取模运算
                answer.matrix[i][j] = (answer.matrix[i][j] + x.matrix[i][k] * y.matrix[k][j]) % mod;
            }
        }
    }
    return answer;
}

// 构造单位矩阵初始化快速幂结果矩阵
Matrix InitAnswer(Matrix x){
    Matrix answer(x.row, x.col);    // 元素已全部初始化为0
    for(int i=0;i<answer.row;i++)
        answer.matrix[i][i] = 1;            // 对角线元素初始化为1，构造单位矩阵
    return answer;
}

// 核心函数：计算矩阵快速幂
Matrix FastExponentiation(Matrix x, int k){
    Matrix answer = InitAnswer(x);
    while(k>0){
        if(k%2==1)    // k为奇数则answer累乘当前x
            answer = Multiply(answer, x);
        // 矩阵平方，指数减半
        x = Multiply(x, x);
        k /= 2;   // 等价于右移一位 k>>=1;
    }
    return answer;
}


int main() {
    int a0, a1, p, q, k;
    while (cin >> a0 >> a1 >> p >> q >> k) {
        // 构造参数矩阵A
        Matrix answer(MAXN, MAXN);
        answer.matrix[0][0] = p, answer.matrix[0][1] = q;
        answer.matrix[1][0] = 1, answer.matrix[1][1] = 0;
        // 利用矩阵快速幂对参数矩阵A求解k-1次幂
        answer = FastExponentiation(answer, k - 1);
        // A的第一行乘以起始元素列向量 [a1, a0]' 即为an的值，注意大数需要随时取模
        int res = ((answer.matrix[0][0] * a1) % mod + (answer.matrix[0][1] * a0) % mod) % mod;
        cout << res << endl;
    }
    return 0;
}
