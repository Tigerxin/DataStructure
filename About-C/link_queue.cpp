#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{    // ��ʽ���н��
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *qhead, *qend; // ���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;

// ��ʼ������(��ͷ���)
void InitQueue(LinkQueue &Q);
// �ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q);
// ��Ԫ�����
void InQueue(LinkQueue &Q, int data);
// ���Ӳ���
bool OutQueue(LinkQueue &Q, int &data);


int main(){
    LinkQueue Q;    // ����һ������
    InitQueue(Q);
    printf("��������Ƿ�Ϊ��:%s\n",IsEmpty(Q) ? "��" : "��");
    return 0;
}

// ��ʼ������(��ͷ���)
void InitQueue(LinkQueue &Q){
    // ��ʼ��ʱqhead��qend��ָ��ͷ���
    Q.qhead = Q.qend = (LinkNode*)malloc(sizeof(LinkNode));
    Q.qhead->next = NULL;
}

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q){
    if(Q.qhead == Q.qend)
        return true;
    else
        return false;
}

// ��Ԫ�����
void InQueue(LinkQueue &Q, int data){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = data;
    s->next = NULL;
    Q.qend->next = s;   // �½����뵽qend֮��
    Q.qend = s; // �޸ı�βָ��
}

// ���Ӳ���
bool OutQueue(LinkQueue &Q, int &data){
    if(Q.qhead == Q.qend)
        return false;
    LinkNode *p = Q.qhead->next;
    data = p->data; // �ñ������ض�ͷָ��
    Q.qhead->next = p->next;    // �޸�ͷ����nextָ��
    if(Q.qend == p)
        Q.qend = Q.qhead;   // �޸�qendָ��
    free(p);
    return true;
}
