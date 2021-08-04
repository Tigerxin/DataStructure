#include <stdio.h>
#include <stdlib.h>

// 二叉树的结点（链式存储）
typedef struct BinNode{
    char data;
    struct BinNode *lchild, *rchild;
}BinNode, *BinTree;

// 链式队列结点
typedef struct LinkNode{
    BinNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *pre,*rear;    // 队头队尾
}LinkQueue;

// 层序遍历
void LevelOrder(BinTree T);

int main(){
    return 0;
}

// 层序遍历
void LevelOrder(BinTree T){
    LinkQueue Q;
    InitQueue(Q);
    BinTree p;
    EnQueue(Q, T);
    while(!IsEmpty(Q)){
        DeQueue(Q, p);
        printf(" %c ",p->data);
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}







