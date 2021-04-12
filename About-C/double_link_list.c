#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0

typedef int Status;

typedef struct DNode{
    char *data;
    struct DNode *pre,*next;
}DNode, *Double_LinkList;

// 初始化双链表
Double_LinkList InitLinkList();
// 判断双链表是否为空
Status IsEmpty(Double_LinkList L);
// 在p结点之后插入s结点
Status InsertNextNode(DNode *p, DNode *s);
// 删除双链表的后继结点
Status DeleteNextNode(DNode *p);
// 销毁双链表
Double_LinkList DestroyList(Double_LinkList L);
// 后向遍历
void BehindTraverse(Double_LinkList L);

int main(){
    Double_LinkList L;
    printf("未初始化%p===>%d\n",L,L);
    L = InitLinkList();
    printf("初始化后%p===>%d\n",L,L);
    if(L != NULL){
        printf("双链表初始化成功,正在销毁...\n");
        L = DestroyList(L);
        printf("销毁完成!\n");
    }
    printf("销毁后%p===>%d\n",L,L);
    return 0;
}

// 初始化双链表
Double_LinkList InitLinkList(){
    // 初始化链表
    Double_LinkList L;
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if(L == NULL)
        return NULL;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

// 判断双链表是否为空
Status IsEmpty(Double_LinkList L){
    if(L->next == NULL)
        return SUCCESS;
    else
        return ERROR;
}

// 在p结点之后插入s结点
Status InsertNextNode(DNode *p, DNode *s){
    if(p==NULL || s==NULL)  // 非法参数
        return ERROR;
    s->next = p->next;
    if(p->next != NULL) // 如果p结点有后继结点
        p->next->pre = s;
    s->pre = p;
    p->next = s;
    return SUCCESS;
}

// 删除双链表的后继结点
Status DeleteNextNode(DNode *p){
    if(p == NULL)
        return ERROR;
    DNode *q = p->next; // 找到p的后继结点
    if(q == NULL)   // p没有后继结点
        return ERROR;
    p->next = q->next;
    if(q->next != NULL) // q有后继结点
        q->next->pre = p;
    free(q);    // 释放此处的存储空间
    return SUCCESS;

}

// 销毁双链表
Double_LinkList DestroyList(Double_LinkList L){
    while(L->next != NULL){
        DeleteNextNode(L);
    }
    free(L);
    L=NULL;
    return L;
}

// 后向遍历
void BehindTraverse(Double_LinkList L){
    if(L == NULL){
        printf("该链表为空!\n");
        return;
    }
    DNode *p;
    p = L->next;
    int i=1;
    printf("遍历双链表开始...\n");
    while(p != NULL){
        printf("这是第%d个元素值为%s\n",i,p->data);
        p = p->next;
        i++;
    }
    printf("遍历双链表结束!\n");
}




