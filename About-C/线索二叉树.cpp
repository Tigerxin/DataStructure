#include <stdio.h>
#include <stdlib.h>

// �������Ľ��(��ʽ�洢)
typedef struct BinTreeNode{
    int data;
    struct BinTreeNode *lchild,*rchild;
}BinTreeNode, *BinTree;

// ����������
typedef struct IndexBinTreeNode{
    int data;
    struct IndexBinTreeNode *lchild,*rchild;
    int ltag,rtag;  // �����������
}IndexBinTreeNode, *IndexBinTree;

// ����ȫ�ֱ���,���ڲ���p��ǰ��
BinTreeNode *p; // pָ��Ŀ����
BinTreeNode *pre=NULL; // ָ��ǰ���ʽ���ǰ��
BinTreeNode *endData=NULL; // ���ڼ�¼���ս��

IndexBinTreeNode *indexPre = NULL;
IndexBinTreeNode *indexEndData = NULL;

// �������
void InOrder(BinTree T);
// ��ӡ��ǰ���
void MyPrint(BinTreeNode *q);
// ����������������
void CreateIndexBinTree(IndexBinTree T);
// ��������������
void IndexInOrder(IndexBinTree T);
// ����ǰ��
void SearchPre(IndexBinTreeNode *q);

int main(){
    return 0;
}

// �������
void InOrder(BinTree T){
    if(T != NULL){
        InOrder(T->lchild);
        MyPrint(T);
        InOrder(T->rchild);
    }
}

// ��ӡ��ǰ���
void MyPrint(BinTreeNode *q){
    if(q == p)
        endData = pre;  // �ҵ�p��ǰ��
    else
        pre = q;    // preָ��ǰ���ʵĽ��
}

// ����������������
void CreateIndexBinTree(IndexBinTree T){
    indexPre = NULL;    // indexPre��ʼΪNULL
    if(T != NULL){  // �ǿն���������������
        IndexInOrder(T);    // ����������������
        if(indexPre->rchild == NULL)
            indexPre->rtag = 1; // ������������һ�����
    }
}

// ��������������
void IndexInOrder(IndexBinTree T){
    if(T != NULL){
        IndexInOrder(T->lchild);
        SearchPre(T);
        IndexInOrder(T->rchild);
    }
}
// ����ǰ��
void SearchPre(IndexBinTreeNode *q){
    if(q->lchild == NULL){  // ����Ϊ�գ�����ǰ������
        q->lchild = indexPre;
        q->ltag = 1;
    }
    if(indexPre != NULL && indexPre->rchild == NULL){
        indexPre->rchild = q;    // ����ǰ�����ĺ������
        indexPre->rtag = 1;
    }
    indexPre = q;
}




