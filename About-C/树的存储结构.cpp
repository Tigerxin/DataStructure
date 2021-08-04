#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100   // �����������

// ˫�ױ�ʾ��:ÿ������б���ָ��˫�׵ġ�ָ�롱
typedef struct{
    int data;
    int parent; // ˫��λ����
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];    // ˫�ױ�ʾ
    int n;  // ������
}PTree;

// ���ӱ�ʾ����˳��+��ʽ�洢��
struct CTNode{
    int child;  // ���ӽ���������е�λ��
    struct CTNode *next;    // ��һ������
};
typedef struct{
    int data;
    struct CTNode *firstChild;  // ��һ������
}CTBox;

typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;   //������͸���λ��
}CTree;

/*
    ���⣺���Ͷ�������ת��
    �ŵ㣺��������Ϥ�Ķ�����������������
*/
// �����ֵܱ�ʾ��
typedef struct CSNode{
    int data;   // ������
    struct CSNode *firstchild,*nextsibling; // ��һ�����Ӻ����ֵ�ָ��
}CSNode, *CSTree;

// �����ȸ�����
void PreOrder(CSNode *R);
// ���ĺ������
void PostOrder(CSNode *R);


int main(){
    return 0;
}

// �����ȸ�����
void PreOrder(CSNode *R){
    if(R != NULL){
        printf("����Ϊ%d\n",R->data);
        while(R->nextsibling != NULL){
            PreOrder(R->nextsibling);   // �ȸ�������һ������
        }
    }
}

// ���ĺ������
void PostOrder(CSNode *R){
    if(R != NULL){
        while(R->nextsibling != NULL)
            PostOrder(R->nextsibling);  // ���������һ������
        printf("�Ӻ���%d\n",R->firstchild->data);
    }
}
