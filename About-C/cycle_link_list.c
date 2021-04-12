#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0

typedef int Status;
typedef struct LNode{   // ���嵥����������
    int data;   // ÿ�������һ������Ԫ��
    struct LNode *next; // ָ��ָ����һ�����
}LNode, *CycleList;

// ��ʼ��һ��ѭ��������
CycleList InitList();
// �ж�ѭ���������Ƿ�Ϊ��
Status IsEmpty(CycleList L);
// �жϽ��p�Ƿ�Ϊѭ��������ı�β���
Status IsEndNode(CycleList L, LNode *p);

int main(){
    CycleList L;
    L = InitList();
    if(L == NULL){
        printf("ѭ����������ʧ��!\n");
    }else{
        printf("ѭ�����������ɹ�\n");
        int sta = IsEmpty(L);
        printf("ѭ���������Ƿ�Ϊ��%s\n", sta==1 ? "true":"false");
    }
    return 0;
}

// ��ʼ��һ��ѭ��������
CycleList InitList(){
    CycleList L = (LNode *)malloc(sizeof(LNode));   // ����һ��ͷ���
    if(L == NULL){
        return L;
    }
    L->next = L;    // ͷ���nextָ��ͷ���
    return L;
}

// �ж�ѭ���������Ƿ�Ϊ��
Status IsEmpty(CycleList L){
    if(L->next == L)
        return SUCCESS;
    else
        return ERROR;
}

// �жϽ��p�Ƿ�Ϊѭ��������ı�β���
Status IsEndNode(CycleList L, LNode *p){
    if(p->next == L)
        return SUCCESS;
    else
        return ERROR;
}







