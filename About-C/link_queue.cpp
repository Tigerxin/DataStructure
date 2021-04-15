#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{    // 链式队列结点
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *qhead, *qend; // 队列的队头和队尾指针
}LinkQueue;

// 初始化队列(带头结点)
void InitQueue(LinkQueue &Q);
// 判断队列是否为空
bool IsEmpty(LinkQueue Q);
// 新元素入队
void InQueue(LinkQueue &Q, int data);
// 出队操作
bool OutQueue(LinkQueue &Q, int &data);


int main(){
    LinkQueue Q;    // 声明一个队列
    InitQueue(Q);
    printf("链表队列是否为空:%s\n",IsEmpty(Q) ? "是" : "否");
    return 0;
}

// 初始化队列(带头结点)
void InitQueue(LinkQueue &Q){
    // 初始化时qhead和qend都指向头结点
    Q.qhead = Q.qend = (LinkNode*)malloc(sizeof(LinkNode));
    Q.qhead->next = NULL;
}

// 判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.qhead == Q.qend)
        return true;
    else
        return false;
}

// 新元素入队
void InQueue(LinkQueue &Q, int data){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = data;
    s->next = NULL;
    Q.qend->next = s;   // 新结点插入到qend之后
    Q.qend = s; // 修改表尾指针
}

// 出队操作
bool OutQueue(LinkQueue &Q, int &data){
    if(Q.qhead == Q.qend)
        return false;
    LinkNode *p = Q.qhead->next;
    data = p->data; // 用变量返回队头指针
    Q.qhead->next = p->next;    // 修改头结点的next指针
    if(Q.qend == p)
        Q.qend = Q.qhead;   // 修改qend指针
    free(p);
    return true;
}
