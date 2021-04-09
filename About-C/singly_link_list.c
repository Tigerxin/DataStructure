#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0
#define HAVENODE 0 // ʹ����ͷ���0����ͷ���1��ʼ������

typedef int Status;

typedef struct LNode{   // ���嵥����������
    int data;       // ��������һ����������
    struct LNode *next;     // ����ָ����һ�����
}LNode, *Single_LinkList;

// ��ʼ��������
Single_LinkList InitList();
// �жϵ������Ƿ�Ϊ��
Status Empty(Single_LinkList L);
// ��λ����루��ͷ��㣩
Status InsertDataToList(Single_LinkList L, int i, int data);
// ����������p���֮�����Ԫ��data��
Status InsertNextNode(LNode *p, int data);
// ǰ���������p���֮ǰ����Ԫ��data��
Status InsertPreNode(LNode *p, int data);
// ��λ��ɾ���ڵ�
Status DeleteListNodeByI(Single_LinkList L, int i);
// ɾ��ָ�����p
Status DeleNodeByNode(LNode *p);

int main(){
    Single_LinkList L;
    L = InitList(L);
    if(L==NULL){
        printf("��ʼ����ͷ��㵥����ɹ�%d\n",L);
        printf("%p==>%d\n",L,L);
    }else if(L->next==NULL){
        printf("��ʼ����ͷ��㵥����ɹ�%d\n",L);
        printf("%p==>%d\n",L,L);
    }
}

// ��ʼ��һ���յĵ�����
Single_LinkList InitList(){
#if HAVENODE
    return NULL;
#else
    Single_LinkList L = NULL;
    L = (Single_LinkList)malloc(sizeof(Single_LinkList));   // ����һ��ͷ���
    // C���Զ��ж�L�Ƿ�Ϊ��������
    if(L == NULL)
        return L;
    L->next = NULL; // ͷ���֮����ʱû�нڵ�
    return L;
#endif
}

// �жϵ������Ƿ�Ϊ��
Status Empty(Single_LinkList L){
#if HAVENODE
    if(L == NULL){
        return SUCCESS;
    }else{
        return ERROR;
    }
#else
    if(L->next == NULL)
        return SUCCESS;
    else
        return ERROR;
#endif
}

// ��λ����루��ͷ��㣩
Status InsertDataToList(Single_LinkList L, int i, int data){
    if(i < 1)
        return ERROR;
    /*
    if(i==1){   // �����1�����Ĳ�����������������ͬ
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return SUCCESS;
    }
    */
    LNode *p;   // ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;  // ��ǰpָ��ڼ������
    p = L;  // Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
    while(p!=NULL && j<i-1){
        p = p->next;
        j++;
    }
    return InsertNextNode(p, data);
    /* ��װ
    if(p == NULL)   // iֵ���Ϸ�
        return ERROR;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = data;
    s->next = p->next;
    p->next = s;    // �����s����p֮��
    return SUCCESS; // ����ɹ�
    */
}

// ����������p���֮�����Ԫ��data��
Status InsertNextNode(LNode *p, int data){
    if(p == NULL){
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)   // �ڴ����ʧ��
        return ERROR;
    s->data = data;
    s->next = p->next;
    p->next = s;
    return SUCCESS;
}

// ǰ���������p���֮ǰ����Ԫ��data��
Status InsertPreNode(LNode *p, int data){
    if(p == NULL)
        return ERROR;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return ERROR;
    s->next = p->next;
    p->next = s;    // �Ȱ�s����p�ĺ��
    s->data = p->data;  // �ٰ�p�е����ݸ�ֵ��s������
    p->data = data; // �������ݸ�ֵ��p������
    return SUCCESS;
}

// ��λ��ɾ���ڵ�
Status DeleteListNodeByI(Single_LinkList L, int i){
    if(i < 1)
        return ERROR;
    LNode *p;
    int j = 0;
    p = L;
    while(p!=NULL && j<i-1){    // ѭ���ҵ���i-1�����
        p = p->next;
        j++;
    }
    if(p == NULL)
        return ERROR;
    if(p->next == NULL)
        return ERROR;
    LNode *q = p->next; // ��qָ��ɾ���Ľ��
    // int data = q->data;�ɷ���ɾ������ֵ
    p->next = q->next;  // ��*q���������жϿ�
    free(q);    // �ͷŽ��Ĵ洢�ռ�
    return SUCCESS;
}

// ɾ��ָ�����p
Status DeleNodeByNode(LNode *p){
    if(p == NULL)
        return ERROR;
    LNode *q = p->next; // ��qָ��*p�ĺ�̽��
    p->data = p->next->data;    // �ͺ�̽�㽻��������
    p->next = q->next;  // ��*q���������жϿ�
    free(q);
    return SUCCESS;
}







