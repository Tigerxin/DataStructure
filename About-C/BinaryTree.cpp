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
// �������
void PreOrder(BinTree T);
// �������
void InOrder(BinTree T);
// �������
void PostOrder(BinTree T);
// ��ӡ���
void MyPrint(BinTree T);
// ���������
int treeDepth(BinTree T);

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

// �������
void PreOrder(BinTree T){
    if(T != NULL){
        MyPrint(T); // ���ʸ��ڵ�
        PreOrder(T->lchild);    // �ݹ����������
        PreOrder(T->rchild);    // �ݹ����������
    }
}

// �������
void InOrder(BinTree T){
    if(T != NULL){
        InOrder(T->lchild); // �ݹ����������
        MyPrint(T); // ���ʸ����
        InOrder(T->rchild); // �ݹ����������
    }
}

// �������
void PostOrder(BinTree T){
    if(T != NULL){
        InOrder(T->lchild); // �ݹ����������
        InOrder(T->rchild); // �ݹ����������
        MyPrint(T); // ���ʸ����
    }
}

// ��ӡ���
void MyPrint(BinTree T){
    printf(" %d ", T->data.value);
}

// ���������
int treeDepth(BinTree T){
    if(T == NULL){
        return 0;
    }else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //�������=���������������ϴ���+1
        return l>r ? l+1 : r+1;
    }
}








