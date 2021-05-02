#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

// ��ʽ�洢
// n�����Ķ���������n+1��������
struct TreeType{
    int value;
};

typedef struct BinTNode{
    TreeType data;
    struct BinTNode *lchild, *rchild;   // ���Һ���ָ��
    // struct BinTNode *parent; �����ָ��
}BinTNode, *BinTree;

// ��ʼ��������
void InitBinTree(BinTree &root);
// ������
bool InsertNode(BinTree root, int data);

int main(){
    BinTree root = NULL;
    InitBinTree(root);
    bool isInsert = InsertNode(root,1);
    printf("�����Ƿ�ɹ���%s\n",isInsert ? "�ɹ�" : "ʧ��");
    return 0;
}

// ��ʼ��������
void InitBinTree(BinTree &root){
    root = (BinTree)malloc(sizeof(BinTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
}

// ������
bool InsertNode(BinTree root, int data){
    if(root == NULL)
        return false;
    BinTNode *p = (BinTNode*)malloc(sizeof(BinTNode));
    p->data = {data};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;   // ��Ϊ����������
    return true;
}



