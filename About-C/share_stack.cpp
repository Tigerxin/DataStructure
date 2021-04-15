#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];  // 静态数组存放栈中元素
    int top0;   // 0号栈栈顶元素
    int top1;   // 1号栈栈顶元素
}ShareStack;

// 初始化栈
void InitStack(ShareStack &S);

int main(){
    ShareStack S;
    InitStack(S);
    printf("0号栈栈顶为%d,1号栈栈顶为%d\n", S.top0, S.top1);
    return 0;
}

// 初始化栈
void InitStack(ShareStack &S){
    S.top0 = -1;    // 初始化栈顶指针
    S.top1 = MaxSize;   // 栈满条件 top0+1==top1
}
