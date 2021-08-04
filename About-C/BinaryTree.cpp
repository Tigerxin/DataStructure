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
// 先序遍历
void PreOrder(BinTree T);
// 中序遍历
void InOrder(BinTree T);
// 后序遍历
void PostOrder(BinTree T);
// 打印输出
void MyPrint(BinTree T);
// 求树的深度
int treeDepth(BinTree T);

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

// 先序遍历
void PreOrder(BinTree T){
    if(T != NULL){
        MyPrint(T); // 访问根节点
        PreOrder(T->lchild);    // 递归遍历左子树
        PreOrder(T->rchild);    // 递归遍历右子树
    }
}

// 中序遍历
void InOrder(BinTree T){
    if(T != NULL){
        InOrder(T->lchild); // 递归遍历左子树
        MyPrint(T); // 访问根结点
        InOrder(T->rchild); // 递归遍历右子树
    }
}

// 后序遍历
void PostOrder(BinTree T){
    if(T != NULL){
        InOrder(T->lchild); // 递归遍历左子树
        InOrder(T->rchild); // 递归遍历右子树
        MyPrint(T); // 访问根结点
    }
}

// 打印输出
void MyPrint(BinTree T){
    printf(" %d ", T->data.value);
}

// 求树的深度
int treeDepth(BinTree T){
    if(T == NULL){
        return 0;
    }else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //树的深度=左子树和右子树较大者+1
        return l>r ? l+1 : r+1;
    }
}








