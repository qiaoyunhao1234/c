#include <iostream>
#include <cstdio>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data),left(NULL),right(NULL){}
};
TreeNode* Insert(TreeNode* root,int x,int father){
    if(root==NULL){
        TreeNode* newNode=new TreeNode(x);
        printf("%d\n",father);
        // 输出父节点
    }
    else if(x<root->data){
        root->left=Insert(root->left,x,root->data);
    }else {
        root->right=Insert(root->right,x,root->data);
    }
    return root;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        TreeNode* root=NULL;          
        // 建立空树
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            root=Insert(root,x,-1);
        }   
    }    return 0;
}