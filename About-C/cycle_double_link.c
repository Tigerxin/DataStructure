#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0

typedef int Status;

typedef struct LNode{
    int data;
    struct LNode *pre,*next;
}LNode, *DCycleList;

// ��ʼ���յ�ѭ��˫����
DCycleList InitDList();
// �ж�ѭ��˫�����Ƿ�Ϊ��
Status IsEmpty(DCycleList L);
// �жϽ��p�Ƿ�Ϊѭ������ı�β���
Status IsEndNode(DCycleList L, LNode *p);
// ��p���֮�����s���
Status InsertNextNode(LNode *p, LNode *s);
// ɾ��p�ĺ�̽��q
Status DeleteNextNode(LNode *p);

int main(){
    DCycleList L;
    L = InitDList();
    if(L == NULL){
        printf("ѭ��˫������ʧ��!\n");
    }else{
        printf("ѭ��˫�������ɹ�\n");
        int sta = IsEmpty(L);
        printf("ѭ��˫�����Ƿ�Ϊ��%s\n", sta==1 ? "true":"false");
    }
    return 0;
}

// ��ʼ���յ�ѭ��˫����
DCycleList InitDList(){
    DCycleList L;
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)
        return L;
    L->pre = L; // ͷ����preָ��ͷ���
    L->next = L;    // ͷ����nextָ��ͷ���
    return L;
}

// �ж�ѭ��˫�����Ƿ�Ϊ��
Status IsEmpty(DCycleList L){
    if(L->next == L)
        return SUCCESS;
    else
        return ERROR;
}

// �жϽ��p�Ƿ�Ϊѭ������ı�β���
Status IsEndNode(DCycleList L, LNode *p){
    if(p->next == NULL)
        return SUCCESS;
    else
        return ERROR;
}

// ��p���֮�����s���
Status InsertNextNode(LNode *p, LNode *s){
    if(p==NULL || s==NULL)
        return ERROR;
    s->next = p->next;  // �����*s���뵽���*p֮��
    p->next->pre = s;
    s->pre = p;
    p->next = s;
    return SUCCESS;
}

// ɾ��p�ĺ�̽��q
Status DeleteNextNode(LNode *p){
    if(p == NULL)
        return ERROR;
    LNode *q;
    q = p->next;
    p->next = q->next;
    q->next->pre = p;
    free(q);
    return SUCCESS;
}







