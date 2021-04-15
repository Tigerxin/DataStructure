#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];  // 静态数组存放队列元素
    int qhead, qend;    // 队头指针和对尾指针
    // int size;    // 可以通过size变量记录存储数据的个数
    // int tag;     // 最后进行的是删除0/插入1
}SeqQueue;

// 初始化队列
void InitQueue(SeqQueue &Q);
// 判断队列是否为空
bool IsEmpty(SeqQueue &Q);
// 入队
bool InQueue(SeqQueue &Q, int data);
// 出队
bool OutQueue(SeqQueue &Q, int &data);
// 获得头元素
bool GetQueueHead(SeqQueue &Q, int &data);

int main(){
    // 声明一个队列
    SeqQueue Q;
    InitQueue(Q);
    printf("队列是否为空:%s\n",IsEmpty(Q) ? "是" : "否");
    bool isIn = InQueue(Q,3);
    printf("入队是否成功:%s\n",isIn ? "是" : "否");
    printf("队列是否为空:%s\n",IsEmpty(Q) ? "是" : "否");
    int data;
    printf("是否含有队首元素:%s\n",GetQueueHead(Q,data) ? "是" : "否");
    printf("此时队首元素为:%d\n",data);
    return 0;
}

// 初始化队列
void InitQueue(SeqQueue &Q){
    // 初始化时队头队尾指向0
    Q.qhead = Q.qend = 0;
}

// 判断队列是否为空
bool IsEmpty(SeqQueue &Q){
    if(Q.qhead == Q.qend)   // 意味着还在初始位置
        return true;
    else
        return false;
}

// 入队
bool InQueue(SeqQueue &Q, int data){
    if((Q.qend+1) % MaxSize == Q.qhead) // 判断队满
        return false;
    Q.data[Q.qend] = data;  // 将数据插入队尾
    Q.qend = (Q.qend+1) % MaxSize;    // 队尾指针加1取模
    return true;
}

// 出队
bool OutQueue(SeqQueue &Q, int &data){
    if(Q.qend == Q.qhead)
        return false;   // 队空
    data = Q.data[Q.qhead];
    Q.qhead = (Q.qhead+1) % MaxSize;
    return true;
}

// 获得头元素
bool GetQueueHead(SeqQueue &Q, int &data){
    if(Q.qhead == Q.qend)
        return false;
    data = Q.data[Q.qhead];
    return true;
}




