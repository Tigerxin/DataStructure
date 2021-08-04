#include <stdio.h>
#include <stdlib.h>

// ����������
typedef struct IndexBinTreeNode{
    int data;
    struct IndexBinTreeNode *lchild,*rchild;
    int ltag,rtag;  // �����������
}IndexBinTreeNode, *IndexBinTree;

// �ҵ���pΪ������������һ������������Ľ��
IndexBinTreeNode *Firstnode(IndexBinTreeNode *p);
// �������������������ҵ����p�ĺ�̽��
IndexBinTreeNode *Nextnode(IndexBinTreeNode *p);
// �������������������������������������ʵ�ֵķǵݹ��㷨��
void Inorder(IndexBinTreeNode *T);

// �ҵ���pΪ���������У����һ������������Ľ��
IndexBinTreeNode *Lastnode(IndexBinTreeNode *p);
// �������������������ҵ����p��ǰ�����
IndexBinTreeNode *Prenode(IndexBinTreeNode *p);
// �������������������������������
void RevInorder(IndexBinTreeNode *T);


int main(){
    return 0;
}

// �ҵ���pΪ������������һ������������Ľ��
IndexBinTreeNode *Firstnode(IndexBinTreeNode *p){
    // ѭ���ҵ������½�㣨��һ����Ҷ��㣩
    while(p->ltag == 0)
        p=p->lchild;
    return p;
}

// �������������������ҵ����p�ĺ�̽��
IndexBinTreeNode *Nextnode(IndexBinTreeNode *p){
    // �����������½��
    if(p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;   // rtag==1ֱ�ӷ��غ������
}

// �������������������������������������ʵ�ֵķǵݹ��㷨��
void Inorder(IndexBinTreeNode *T){
    for(IndexBinTreeNode *p=Firstnode(T); p!=NULL; p=Nextnode(p))
        printf("����Ϊ%d\n", p->data);
}

// �ҵ���pΪ���������У����һ������������Ľ��
IndexBinTreeNode *Lastnode(IndexBinTreeNode *p){
    // ѭ���ҵ������½�㣨��һ����Ҷ��㣩
    while(p->rtag == 0)
        p = p->rchild;
    return p;
}

// �������������������ҵ����p��ǰ�����
IndexBinTreeNode *Prenode(IndexBinTreeNode *p){
    // �������������½��
    if(p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;   // ltag==1ֱ�ӷ���ǰ������
}

// �������������������������������
void RevInorder(IndexBinTreeNode *T){
    for(IndexBinTreeNode *p=Lastnode(T); p!=NULL; p=Prenode(p))
        printf("����Ϊ%d\n", p->data);
}





