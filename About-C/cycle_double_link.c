#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0

typedef int Status;

typedef struct LNode{
    int data;
    struct LNode *pre,*next;
}LNode, *DCycleList;

// 初始化空的循环双链表
DCycleList InitDList();
// 判断循环双链表是否为空
Status IsEmpty(DCycleList L);
// 判断结点p是否为循环链表的表尾结点
Status IsEndNode(DCycleList L, LNode *p);
// 在p结点之后插入s结点
Status InsertNextNode(LNode *p, LNode *s);
// 删除p的后继结点q
Status DeleteNextNode(LNode *p);

int main(){
    DCycleList L;
    L = InitDList();
    if(L == NULL){
        printf("循环双链表创建失败!\n");
    }else{
        printf("循环双链表创建成功\n");
        int sta = IsEmpty(L);
        printf("循环双链表是否为空%s\n", sta==1 ? "true":"false");
    }
    return 0;
}

// 初始化空的循环双链表
DCycleList InitDList(){
    DCycleList L;
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)
        return L;
    L->pre = L; // 头结点的pre指向头结点
    L->next = L;    // 头结点的next指向头结点
    return L;
}

// 判断循环双链表是否为空
Status IsEmpty(DCycleList L){
    if(L->next == L)
        return SUCCESS;
    else
        return ERROR;
}

// 判断结点p是否为循环链表的表尾结点
Status IsEndNode(DCycleList L, LNode *p){
    if(p->next == NULL)
        return SUCCESS;
    else
        return ERROR;
}

// 在p结点之后插入s结点
Status InsertNextNode(LNode *p, LNode *s){
    if(p==NULL || s==NULL)
        return ERROR;
    s->next = p->next;  // 将结点*s插入到结点*p之后
    p->next->pre = s;
    s->pre = p;
    p->next = s;
    return SUCCESS;
}

// 删除p的后继结点q
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







