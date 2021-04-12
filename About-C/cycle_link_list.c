#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0

typedef int Status;
typedef struct LNode{   // 定义单链表结点类型
    int data;   // 每个结点存放一个数据元素
    struct LNode *next; // 指针指向下一个结点
}LNode, *CycleList;

// 初始化一个循环单链表
CycleList InitList();
// 判断循环单链表是否为空
Status IsEmpty(CycleList L);
// 判断结点p是否为循环单链表的表尾结点
Status IsEndNode(CycleList L, LNode *p);

int main(){
    CycleList L;
    L = InitList();
    if(L == NULL){
        printf("循环单链表创建失败!\n");
    }else{
        printf("循环单链表创建成功\n");
        int sta = IsEmpty(L);
        printf("循环单链表是否为空%s\n", sta==1 ? "true":"false");
    }
    return 0;
}

// 初始化一个循环单链表
CycleList InitList(){
    CycleList L = (LNode *)malloc(sizeof(LNode));   // 分配一个头结点
    if(L == NULL){
        return L;
    }
    L->next = L;    // 头结点next指向头结点
    return L;
}

// 判断循环单链表是否为空
Status IsEmpty(CycleList L){
    if(L->next == L)
        return SUCCESS;
    else
        return ERROR;
}

// 判断结点p是否为循环单链表的表尾结点
Status IsEndNode(CycleList L, LNode *p){
    if(p->next == L)
        return SUCCESS;
    else
        return ERROR;
}







