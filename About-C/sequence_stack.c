#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10  // 定义栈中元素的最大个数
#define Success 1
#define Error 0

typedef int Status;
typedef struct{
    int data[MaxSize];  // 静态数组存放栈中元素
    int top;    // 栈顶指针
}SeqStack;

// 初始化栈
void InitStack(SeqStack S);
// 判断栈空
Status StackIsEmpty(SeqStack S);
// 新元素进栈
Status Push(SeqStack S, int x);
// 出栈操作
Status Pop(SeqStack S, int x);
// 读取栈顶元素
int GetPop(SeqStack S);

int main(){
    SeqStack S; // 声明一个顺序栈（分配空间）
    InitStack(S);
    return 0;
}

// 初始化栈
void InitStack(SeqStack S){
    S.top = -1; // 初始化栈指针
    printf("初始化成功\n");
}

// 判断栈空
Status StackIsEmpty(SeqStack S){
    if(S.top == -1) // 栈空
        return Success;
    else
        return Error;
}

// 新元素进栈
Status Push(SeqStack S, int x){
    if(S.top == MaxSize-1)  //  栈满，报错
        return Error;
    S.top = S.top + 1;  // 指针先加1
    S.data[S.top] = x;  // 新元素入栈
    return Success;
}

// 出栈操作
Status Pop(SeqStack S, int x){
    if(S.top == -1) // 栈空报错
        return Error;
    x = S.data[S.top];  // 栈顶元素先出栈
    S.top = S.top - 1;  // 指针再减1
    return Success;
}

// 读取栈顶元素
int GetPop(SeqStack S){
    if(S.top == -1)
        return Error;
    return S.data[S.top];   // 返回栈顶元素
}
