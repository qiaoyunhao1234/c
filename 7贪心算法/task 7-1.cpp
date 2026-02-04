//http://t.cn/E9emuS9


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n = 0, m = 0;
    int terminal = 0;
    vector<string> a;
    vector<string> b;
    string temp;
    while (cin >> n) { //录入数据
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> temp;
            b.push_back(temp);
        }
        if (n == 1) { //只有1个***
            for (int i = 0; i < m; i++) {
                if (a[0] == b[i]) {
                    cout << -1 << endl;
                    break;
                } else if (i == m - 1)cout << 0 << endl;
            }

        } else { //多个***
            int count = 0; //目前访问到第几个服务器
            int countnei = 0;
            int max = -1;
            int whichone = -1; //目前在用哪个***服务器线路
            while (count != m) { //访问服务器没到最后则持续执行
                for (int i = 0; i < n; i++) { //***服务器轮流判断最长不需换路步数
                    if (i == whichone)continue;
                    for (int j = count; j < m; j++) { //判断步数取最长
                        if (a[i] == b[j]) {
                            if (max < j - count) {
                                max = j - count;
                                whichone = i;
                                if (j > countnei)countnei = j;
                            }
                            break;
                        } else if (j == m - 1) {
                            count = m;
                            break;
                        }
                    }
                }
                if (count != m) {
                    terminal++;
                    count = countnei;
                }
                max = -1;
            }
            cout << terminal << endl;
            terminal = 0;
        }
        a.clear();
        b.clear();
    }
    return 0;
}