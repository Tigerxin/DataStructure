#include <stdio.h>
#include <stdlib.h>

// 二叉树的结点(链式存储)
typedef struct BinTreeNode{
    int data;
    struct BinTreeNode *lchild,*rchild;
}BinTreeNode, *BinTree;

// 线索二叉树
typedef struct IndexBinTreeNode{
    int data;
    struct IndexBinTreeNode *lchild,*rchild;
    int ltag,rtag;  // 左右线索标点
}IndexBinTreeNode, *IndexBinTree;

// 辅助全局变量,用于查找p的前驱
BinTreeNode *p; // p指向目标结点
BinTreeNode *pre=NULL; // 指向当前访问结点的前驱
BinTreeNode *endData=NULL; // 用于记录最终结果

IndexBinTreeNode *indexPre = NULL;
IndexBinTreeNode *indexEndData = NULL;

// 中序遍历
void InOrder(BinTree T);
// 打印当前结点
void MyPrint(BinTreeNode *q);
// 中序线索化二叉树
void CreateIndexBinTree(IndexBinTree T);
// 中序线索二叉树
void IndexInOrder(IndexBinTree T);
// 查找前驱
void SearchPre(IndexBinTreeNode *q);

int main(){
    return 0;
}

// 中序遍历
void InOrder(BinTree T){
    if(T != NULL){
        InOrder(T->lchild);
        MyPrint(T);
        InOrder(T->rchild);
    }
}

// 打印当前结点
void MyPrint(BinTreeNode *q){
    if(q == p)
        endData = pre;  // 找到p的前驱
    else
        pre = q;    // pre指向当前访问的结点
}

// 中序线索化二叉树
void CreateIndexBinTree(IndexBinTree T){
    indexPre = NULL;    // indexPre初始为NULL
    if(T != NULL){  // 非空二叉树才能线索化
        IndexInOrder(T);    // 中序线索化二叉树
        if(indexPre->rchild == NULL)
            indexPre->rtag = 1; // 处理遍历的最后一个结点
    }
}

// 中序线索二叉树
void IndexInOrder(IndexBinTree T){
    if(T != NULL){
        IndexInOrder(T->lchild);
        SearchPre(T);
        IndexInOrder(T->rchild);
    }
}
// 查找前驱
void SearchPre(IndexBinTreeNode *q){
    if(q->lchild == NULL){  // 左孩子为空，建立前驱线索
        q->lchild = indexPre;
        q->ltag = 1;
    }
    if(indexPre != NULL && indexPre->rchild == NULL){
        indexPre->rchild = q;    // 建立前驱结点的后继线索
        indexPre->rtag = 1;
    }
    indexPre = q;
}




