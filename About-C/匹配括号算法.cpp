#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 20  // ����ջ��Ԫ�ص�������
#define Success 1
#define Error 0

typedef int Status;

typedef struct{
    char data[MaxSize]; // ��̬������ջ��Ԫ��
    int top;    // ջ��ָ��
}MatchStack;

// ƥ��ջ�����ŵ��㷨
bool match_parentheses(char arr[], int length);
// ��ʼ��ջ
void InitStack(MatchStack &S);
// �ж�ջ��
bool IsEmpty(MatchStack S);
// ��Ԫ�ؽ�ջ
Status Push(MatchStack &S, char x);
// ջ��Ԫ�س�ջ
Status Pop(MatchStack &S, char &data);

int main(){
    char str1[] = "{[(9+1)]}+(";
    char str2[] = "{[(9+1)]}+)";
    char str3[] = "{[([])]{}{}[]}";
    bool one = match_parentheses(str1, strlen(str1));
    bool two = match_parentheses(str2, strlen(str2));
    //bool three = match_parentheses(str3, sizeof(str3)/sizeof(char));
    bool three = match_parentheses(str3, strlen(str3));
    printf("�ַ���%s����ƥ��%d\n",str1,one);
    printf("�ַ���%s����ƥ��%d\n",str2,two);
    printf("�ַ���%s����ƥ��%d\n",str3,three);
    return 0;
}

bool match_parentheses(char arr[], int length){
    //printf("�ַ�������Ϊ%d\n",length);
    //printf("��13��Ԫ��Ϊ%c\n",arr[13]);
    MatchStack S;
    InitStack(S);   // ��ʼ��һ��ջ
    for(int i=0;i<length;i++){
        //printf("��%d��Ԫ��%c\n",i,arr[i]);
        if(arr[i]=='(' || arr[i]=='[' || arr[i]=='{'){
            //printf("%c��ջ\n",arr[i]);
            Push(S, arr[i]);    // ɨ�赽��������ջ
        }else if(arr[i]==')' || arr[i]==']' || arr[i]=='}'){
            if(IsEmpty(S)){ // ɨ�赽�����ţ��ҵ�ǰջ��
                return false;   // ƥ��ʧ��
            }
            char topData;
            Pop(S, topData);    // ջ��Ԫ�س�ջ
            //printf("%c��ջƥ��%c\n",topData,arr[i]);
            if(arr[i] == ')' && topData != '(')
                return false;
            if(arr[i] == ']' && topData != '[')
                return false;
            if(arr[i] == '}' && topData != '{')
                return false;
        }
    }
    return IsEmpty(S);  // ������ȫ�����ź�ջ��˵��ƥ��ɹ�
}

// ��ʼ��ջ
void InitStack(MatchStack &S){
    S.top = -1;
}

// �ж�ջ��
bool IsEmpty(MatchStack S){
    //printf("��ʱջ��ָ��Ϊ%d\n",S.top);
    if(S.top == -1)
        return true;
    else
        return false;
}

// ��Ԫ�ؽ�ջ
Status Push(MatchStack &S, char x){
    if(S.top == MaxSize-1)
        return Error;
    S.top++;
    S.data[S.top] = x;
    return Success;
}

// ջ��Ԫ�س�ջ
Status Pop(MatchStack &S, char &data){
    if(S.top == -1)
        return Error;
    data = S.data[S.top];
    S.top--;
    return Success;
}
