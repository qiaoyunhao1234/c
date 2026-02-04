#include <iostream>
using namespace std;

// 递归打印 n 的二进制分解表达式
void printDecomposition(int n) {
	if (n == 0) {
		cout << "0";
		return;
	}

/* 0111
10001001
76543210
2（7）+2（3）+2（0） */

	bool first = true;
	for (int i = 31; i >= 0; --i) {
		if ((n >> i) & 1) {    //右移操作，按位与（同1为1）
			if (!first) cout << "+";
			first = false;

			if (i == 0) {
				cout << "2(0)";
			} else if (i == 1) {
				cout << "2";
			} else {
				cout << "2(";
				printDecomposition(i);    //10001001   第一个1，i为7，应该为2（7）
                                          //递归调用
                                          //7继续递归，变成2（2（2）+2+2(0)）
				cout << ")";
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	printDecomposition(n);
	cout << endl;
	return 0;
}



