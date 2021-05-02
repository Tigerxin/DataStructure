#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

// 链式存储
// n个结点的二叉树表共有n+1个空链域
struct TreeType{
    int value;
};

typedef struct BinTNode{
    TreeType data;
    struct BinTNode *lchild, *rchild;   // 左右孩子指针
    // struct BinTNode *parent; 父结点指针
}BinTNode, *BinTree;

// 初始化二叉树
void InitBinTree(BinTree &root);
// 插入结点
bool InsertNode(BinTree root, int data);

int main(){
    BinTree root = NULL;
    InitBinTree(root);
    bool isInsert = InsertNode(root,1);
    printf("插入是否成功：%s\n",isInsert ? "成功" : "失败");
    return 0;
}

// 初始化二叉树
void InitBinTree(BinTree &root){
    root = (BinTree)malloc(sizeof(BinTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
}

// 插入结点
bool InsertNode(BinTree root, int data){
    if(root == NULL)
        return false;
    BinTNode *p = (BinTNode*)malloc(sizeof(BinTNode));
    p->data = {data};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;   // 做为根结点的左孩子
    return true;
}



