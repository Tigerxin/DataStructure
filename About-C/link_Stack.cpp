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

// 后插操作
Status InsertNextNode(LNode *p, int e);

int main(){
    return 0;
}

// 后插操作
Status InsertNextNode(LNode *p, int e){
    if(p == NULL)
        return Error;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL)   // 内存分配失败
        return Error;
    s->data = e;    // 用结点s保存数据元素e
    s->next = p->next;
    p->next = s;    // 将结点s连到p之后
    return Success;
}
