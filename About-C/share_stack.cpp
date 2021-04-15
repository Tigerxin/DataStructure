#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];  // ��̬������ջ��Ԫ��
    int top0;   // 0��ջջ��Ԫ��
    int top1;   // 1��ջջ��Ԫ��
}ShareStack;

// ��ʼ��ջ
void InitStack(ShareStack &S);

int main(){
    ShareStack S;
    InitStack(S);
    printf("0��ջջ��Ϊ%d,1��ջջ��Ϊ%d\n", S.top0, S.top1);
    return 0;
}

// ��ʼ��ջ
void InitStack(ShareStack &S){
    S.top0 = -1;    // ��ʼ��ջ��ָ��
    S.top1 = MaxSize;   // ջ������ top0+1==top1
}
