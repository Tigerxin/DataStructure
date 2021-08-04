#include <stdio.h>

// 存放初始队列
typedef struct LinkNode{
    char *data;
    struct LinkNode *next;
}LinkNode, *LinkList;

// 存放分配队列
typedef struct{ // 链式队列
    LinkNode *head,*rear;   // 队列的队头和队尾指针
}LinkQueue;

/**
    需要r个辅助队列，空间复杂度=O（r）
    一趟分配O(n),一趟收集O(r),总共d趟分配，收集，总的时间复杂度=O(d(n+r))
    稳定性：稳定
*/
int main(){
    return 0;
}
