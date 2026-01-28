/* 输入一系列数建立二叉排序树，前中后序遍历 */
#include <iostream>
#include <cstdio>
using namespace std;
// 建立节点
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data),left(NULL),right(NULL){}
};

// 二叉排序树插入节点的函数
TreeNode* Insert(TreeNode* root,int x){
    if(root==NULL){
        root=new TreeNode(x);
    }
    else if(x<root->data){
        root->left=Insert(root->left,x);
    }else {
        root->right=Insert(root->right,x);
    }
    return root;        
}//注意这是递归


// 前序遍历
void PreOrder(TreeNode* root){
    if(root==NULL) {
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

// 中序遍历
void InOrder(TreeNode* root){
    if(root==NULL) {
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
    return;
}
// 后序遍历
void PostOrder(TreeNode* root){
    if(root==NULL) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
    return;
}

// 主函数
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        TreeNode* root=NULL;          
        // 建立空树
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            root=Insert(root,x);   
        }   
        // 前序遍历
        PreOrder(root);
        printf("\n");
        // 中序遍历
        InOrder(root);
        printf("\n");
        // 后序遍历
        PostOrder(root);
        printf("\n");
    }    
    return 0;
}