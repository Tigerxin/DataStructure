#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0

typedef int Status;

typedef struct DNode{
    char *data;
    struct DNode *pre,*next;
}DNode, *Double_LinkList;

// ��ʼ��˫����
Double_LinkList InitLinkList();
// �ж�˫�����Ƿ�Ϊ��
Status IsEmpty(Double_LinkList L);
// ��p���֮�����s���
Status InsertNextNode(DNode *p, DNode *s);
// ɾ��˫����ĺ�̽��
Status DeleteNextNode(DNode *p);
// ����˫����
Double_LinkList DestroyList(Double_LinkList L);
// �������
void BehindTraverse(Double_LinkList L);

int main(){
    Double_LinkList L;
    printf("δ��ʼ��%p===>%d\n",L,L);
    L = InitLinkList();
    printf("��ʼ����%p===>%d\n",L,L);
    if(L != NULL){
        printf("˫�����ʼ���ɹ�,��������...\n");
        L = DestroyList(L);
        printf("�������!\n");
    }
    printf("���ٺ�%p===>%d\n",L,L);
    return 0;
}

// ��ʼ��˫����
Double_LinkList InitLinkList(){
    // ��ʼ������
    Double_LinkList L;
    L = (DNode *)malloc(sizeof(DNode)); // ����һ��ͷ���
    if(L == NULL)
        return NULL;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

// �ж�˫�����Ƿ�Ϊ��
Status IsEmpty(Double_LinkList L){
    if(L->next == NULL)
        return SUCCESS;
    else
        return ERROR;
}

// ��p���֮�����s���
Status InsertNextNode(DNode *p, DNode *s){
    if(p==NULL || s==NULL)  // �Ƿ�����
        return ERROR;
    s->next = p->next;
    if(p->next != NULL) // ���p����к�̽��
        p->next->pre = s;
    s->pre = p;
    p->next = s;
    return SUCCESS;
}

// ɾ��˫����ĺ�̽��
Status DeleteNextNode(DNode *p){
    if(p == NULL)
        return ERROR;
    DNode *q = p->next; // �ҵ�p�ĺ�̽��
    if(q == NULL)   // pû�к�̽��
        return ERROR;
    p->next = q->next;
    if(q->next != NULL) // q�к�̽��
        q->next->pre = p;
    free(q);    // �ͷŴ˴��Ĵ洢�ռ�
    return SUCCESS;

}

// ����˫����
Double_LinkList DestroyList(Double_LinkList L){
    while(L->next != NULL){
        DeleteNextNode(L);
    }
    free(L);
    L=NULL;
    return L;
}

// �������
void BehindTraverse(Double_LinkList L){
    if(L == NULL){
        printf("������Ϊ��!\n");
        return;
    }
    DNode *p;
    p = L->next;
    int i=1;
    printf("����˫����ʼ...\n");
    while(p != NULL){
        printf("���ǵ�%d��Ԫ��ֵΪ%s\n",i,p->data);
        p = p->next;
        i++;
    }
    printf("����˫�������!\n");
}




