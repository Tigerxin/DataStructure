#include <stdio.h>
#include <stdlib.h>

// �������Ľ�㣨��ʽ�洢��
typedef struct BinNode{
    char data;
    struct BinNode *lchild, *rchild;
}BinNode, *BinTree;

// ��ʽ���н��
typedef struct LinkNode{
    BinNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *pre,*rear;    // ��ͷ��β
}LinkQueue;

// �������
void LevelOrder(BinTree T);

int main(){
    return 0;
}

// �������
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







