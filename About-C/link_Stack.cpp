#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define Success 1
#define Error 0

typedef int Status;

typedef struct LNode{
    int data[MaxSize];
    struct LNode *next;
}LNode, *LinkStack;

// ������
Status InsertNextNode(LNode *p, int e);

int main(){
    return 0;
}

// ������
Status InsertNextNode(LNode *p, int e){
    if(p == NULL)
        return Error;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL)   // �ڴ����ʧ��
        return Error;
    s->data = e;    // �ý��s��������Ԫ��e
    s->next = p->next;
    p->next = s;    // �����s����p֮��
    return Success;
}
