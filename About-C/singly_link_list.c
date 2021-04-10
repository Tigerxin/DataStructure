#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0
#define HAVENODE 0 // 使用有头结点0，无头结点1初始化链表

typedef int Status;

typedef struct LNode{   // 定义单链表结点类型
    int data;       // 定义结点存放一个数据类型
    struct LNode *next;     // 定义指向下一个结点
}LNode, *Single_LinkList;

// 初始化单链表
Single_LinkList InitList();
// 判断单链表是否为空
Status Empty(Single_LinkList L);
// 按位序插入（带头结点）
Status InsertDataToList(Single_LinkList L, int i, int data);
// 后插操作（在p结点之后插入元素data）
Status InsertNextNode(LNode *p, int data);
// 前插操作（在p结点之前插入元素data）
Status InsertPreNode(LNode *p, int data);
// 按位序删除节点
Status DeleteListNodeByI(Single_LinkList L, int i);
// 删除指定结点p
Status DeleNodeByNode(LNode *p);
// 按位查找，返回第i个元素（带头结点）
LNode * GetNodeByPosition(Single_LinkList L, int position);
// 按值查找
LNode * GetNodeByData(Single_LinkList L, int data);
// 求表的长度
int GetLength(Single_LinkList L);
// 尾插法建立单链表
Single_LinkList BuildMyList(Single_LinkList L);
// 头插法建立单链表
Single_LinkList BuildMyListOnHead(Single_LinkList L);

int main(){
    Single_LinkList L;
#if 0   // 测试初始化链表
    L = InitList(L);
    if(L==NULL){
        printf("初始化无头结点单链表成功%d\n",L);
        printf("%p==>%d\n",L,L);
    }else if(L->next==NULL){
        printf("初始化有头结点单链表成功%d\n",L);
        printf("%p==>%d\n",L,L);
    }
#endif
#if 1   // 测试尾插法和获取数据
    printf("请输出需要存储的数据,输入9999退出\n");
    L = BuildMyList(L);
    int length = GetLength(L);
    printf("尾插法有%d个数据！\n",length);
#endif
}

// 初始化一个空的单链表
Single_LinkList InitList(){
#if HAVENODE
    return NULL;
#else
    Single_LinkList L = NULL;
    L = (Single_LinkList)malloc(sizeof(Single_LinkList));   // 分配一个头结点
    // C语言对判断L是否为空有歧义
    if(L == NULL)
        return L;
    L->next = NULL; // 头结点之后暂时没有节点
    return L;
#endif
}

// 判断单链表是否为空
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

// 按位序插入（带头结点）
Status InsertDataToList(Single_LinkList L, int i, int data){
    if(i < 1)
        return ERROR;
    /*
    if(i==1){   // 插入第1个结点的操作与其他结点操作不同
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return SUCCESS;
    }
    */
    LNode *p;   // 指针p指向当前扫描到的结点
    int j = 0;  // 当前p指向第几个结点
    p = L;  // L指向头结点，头结点是第0个结点（不存数据）
    while(p!=NULL && j<i-1){
        p = p->next;
        j++;
    }
    return InsertNextNode(p, data);
    /* 封装
    if(p == NULL)   // i值不合法
        return ERROR;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = data;
    s->next = p->next;
    p->next = s;    // 将结点s连到p之后
    return SUCCESS; // 插入成功
    */
}

// 后插操作（在p结点之后插入元素data）
Status InsertNextNode(LNode *p, int data){
    if(p == NULL){
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)   // 内存分配失败
        return ERROR;
    s->data = data;
    s->next = p->next;
    p->next = s;
    return SUCCESS;
}

// 前插操作（在p结点之前插入元素data）
Status InsertPreNode(LNode *p, int data){
    if(p == NULL)
        return ERROR;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return ERROR;
    s->next = p->next;
    p->next = s;    // 先把s插入p的后继
    s->data = p->data;  // 再把p中的数据赋值给s的数据
    p->data = data; // 把新数据赋值给p的数据
    return SUCCESS;
}

// 按位序删除节点
Status DeleteListNodeByI(Single_LinkList L, int i){
    if(i < 1)
        return ERROR;
    LNode *p;
    int j = 0;
    p = L;
    while(p!=NULL && j<i-1){    // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if(p == NULL)
        return ERROR;
    if(p->next == NULL)
        return ERROR;
    LNode *q = p->next; // 令q指向删除的结点
    // int data = q->data;可返回删除结点的值
    p->next = q->next;  // 将*q结点从链表中断开
    free(q);    // 释放结点的存储空间
    return SUCCESS;
}

// 删除指定结点p
Status DeleNodeByNode(LNode *p){
    if(p == NULL)
        return ERROR;
    LNode *q = p->next; // 令q指向*p的后继结点
    p->data = p->next->data;    // 和后继结点交换数据域
    p->next = q->next;  // 将*q结点从链表中断开
    free(q);
    return SUCCESS;
}

// 按位查找，返回第i个元素（带头结点）
LNode * GetNodeByPosition(Single_LinkList L, int position){
    if(position < 0)
        return NULL;
    LNode *p;   // 指针p指向当前扫描的结点
    int j = 0;  // 当前p指向的是第几个结点
    p = L;
    while(p!=NULL && j<position){
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode * GetNodeByData(Single_LinkList L, int data){
    LNode *p = L->next;
    while(p!=NULL && p->data!=data){
        p = p->next;
    }
    return p;
}

// 求表的长度
int GetLength(Single_LinkList L){
    int len = 0;    // 统计表长
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

// 尾插法建立单链表
Single_LinkList BuildMyList(Single_LinkList L){
    int inputData;
    L = (Single_LinkList)malloc(sizeof(LNode));
    LNode *node,*end = L;   // end为表尾指针
    scanf("%d",&inputData);
    while(inputData != 9999){
        node = (LNode*)malloc(sizeof(LNode));
        node->data = inputData;
        end->next = node;
        end = node;
        scanf("%d",&inputData);
    }
    end->next = NULL;
    return L;
}

// 头插法建立单链表
Single_LinkList BuildMyListOnHead(Single_LinkList L){
    LNode *node;
    int inputData;
    L = (Single_LinkList)malloc(sizeof(LNode)); // 创建头结点
    L->next = NULL;
    scanf("%d",&inputData);
    while(inputData != 9999){
        node = (LNode*)malloc(sizeof(LNode));
        node->data = inputData;
        node->next = L->next;
        L->next = node; // 将新结点插入表中，L为头指针
        scanf("%d",&inputData);
    }
    return L;
}









