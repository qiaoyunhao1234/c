// http://t.cn/AiOzTX5c
//难
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 50;
    
int son[MAXN];      //父节点是儿子，所以以son命名
int height[MAXN];    //表示结点高度，最小的儿子高度为0，越往下辈分越大

//并查集思想

void Initial(){                //初始化函数  父节点默认设为自己，高度默认为0
    for(int i=0;i<MAXN;i++){
        son[i] = i;
        height[i] = 0;
    }
}

int Find(int x,int y,int count){   
    if(son[x]==son[y] && x!=y && son[x]!=x && son[y]!=y) return -1;  //若当前两个节点的父节点是同一个，即拥有同个儿子，则不是直系
    if(height[x]<height[y]){  //高度高的辈分大，则辈分高取自己的儿子，然后递归find，count作为记录取儿子的次数，取一次表面差一个辈分
        y = son[y];
        count++;
        return Find(x,y,count);
    }else if(height[x]>height[y]){  //同理
        x = son[x];
        count++;
        return Find(x,y,count);
    }else{
        return count;   
    }
    return -1;
}

int main(){
    int n,m;
    while(cin >> n >> m){
        Initial();
        for(int i=0;i<n;i++){
            string str;
            cin >> str;
            int a = str[0] - 'A';    //由于是A-Z的字符，则用-'A'来变成数，方便记录son数组的值
            if(str[1]!='-'){  //如果缺失则跳过
                int b = str[1] - 'A';
                son[b] = a;       //记录自己的儿子节点
                height[b] = 1 + height[a];  //b的高度是儿子的高度加1，以此类推，高度越高辈分越大
            }
            if(str[2]!='-'){  
                int c = str[2] - 'A';
                son[c] = a;
                height[c] = 1 + height[a];
            }
        }
        for(int i=0;i<m;i++){
            string str;
            cin >> str;
            int a = str[0]-'A';
            int b = str[1]-'A';
            
            //两个判断有点冗余，可以封装成函数作为调用
            if(height[a]>=height[b]){   //若a高度大于b，则a的辈分高，输出parent
            int ans = Find(a,b,0);
            string str1 = "";
            if(ans==-1){
                str1 += "-";
                cout << str1 << endl;
            }else if(ans==1){
                str1 += "parent";
                cout << str1 << endl;
            }else if(ans==2){
                str1 += "grandparent";
                cout << str1 << endl;
            }else if(ans>2){
                str1 += "grandparent";
                while(ans>2){
                    str1 = "great-" + str1;
                    ans--;
                }
                cout << str1 << endl;
            }
            }
            else if(height[a]<height[b]){   //若a的高度低，则a的辈分低，输出child
            int ans = Find(a,b,0);
            string str1 = "";
            if(ans==-1){
                str1 += "-";
                cout << str1 << endl;
            }else if(ans==1){
                str1 += "child";
                cout << str1 << endl;
            }else if(ans==2){
                str1 += "grandchild";
                cout << str1 << endl;
            }else if(ans>2){
                str1 += "grandchild";
                while(ans>2){
                    str1 = "great-" + str1;
                    ans--;
                }
                cout << str1 << endl;
            }
            }
        
        
        
        }
        
        
    }
        
        
    
    
    
    
    
    
    return 0;
}
