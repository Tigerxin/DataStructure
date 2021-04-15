#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10  // ����ջ��Ԫ�ص�������
#define Success 1
#define Error 0

typedef int Status;
typedef struct{
    int data[MaxSize];  // ��̬������ջ��Ԫ��
    int top;    // ջ��ָ��
}SeqStack;

// ��ʼ��ջ
void InitStack(SeqStack S);
// �ж�ջ��
Status StackIsEmpty(SeqStack S);
// ��Ԫ�ؽ�ջ
Status Push(SeqStack S, int x);
// ��ջ����
Status Pop(SeqStack S, int x);
// ��ȡջ��Ԫ��
int GetPop(SeqStack S);

int main(){
    SeqStack S; // ����һ��˳��ջ������ռ䣩
    InitStack(S);
    return 0;
}

// ��ʼ��ջ
void InitStack(SeqStack S){
    S.top = -1; // ��ʼ��ջָ��
    printf("��ʼ���ɹ�\n");
}

// �ж�ջ��
Status StackIsEmpty(SeqStack S){
    if(S.top == -1) // ջ��
        return Success;
    else
        return Error;
}

// ��Ԫ�ؽ�ջ
Status Push(SeqStack S, int x){
    if(S.top == MaxSize-1)  //  ջ��������
        return Error;
    S.top = S.top + 1;  // ָ���ȼ�1
    S.data[S.top] = x;  // ��Ԫ����ջ
    return Success;
}

// ��ջ����
Status Pop(SeqStack S, int x){
    if(S.top == -1) // ջ�ձ���
        return Error;
    x = S.data[S.top];  // ջ��Ԫ���ȳ�ջ
    S.top = S.top - 1;  // ָ���ټ�1
    return Success;
}

// ��ȡջ��Ԫ��
int GetPop(SeqStack S){
    if(S.top == -1)
        return Error;
    return S.data[S.top];   // ����ջ��Ԫ��
}
