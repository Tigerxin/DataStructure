#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 20  // 定义栈中元素的最大个数
#define Success 1
#define Error 0

typedef int Status;

typedef struct{
    char data[MaxSize]; // 静态数组存放栈中元素
    int top;    // 栈顶指针
}MatchStack;

// 匹配栈中括号的算法
bool match_parentheses(char arr[], int length);
// 初始化栈
void InitStack(MatchStack &S);
// 判断栈空
bool IsEmpty(MatchStack S);
// 新元素进栈
Status Push(MatchStack &S, char x);
// 栈顶元素出栈
Status Pop(MatchStack &S, char &data);

int main(){
    char str1[] = "{[(9+1)]}+(";
    char str2[] = "{[(9+1)]}+)";
    char str3[] = "{[([])]{}{}[]}";
    bool one = match_parentheses(str1, strlen(str1));
    bool two = match_parentheses(str2, strlen(str2));
    //bool three = match_parentheses(str3, sizeof(str3)/sizeof(char));
    bool three = match_parentheses(str3, strlen(str3));
    printf("字符串%s括号匹配%d\n",str1,one);
    printf("字符串%s括号匹配%d\n",str2,two);
    printf("字符串%s括号匹配%d\n",str3,three);
    return 0;
}

bool match_parentheses(char arr[], int length){
    //printf("字符串长度为%d\n",length);
    //printf("第13号元素为%c\n",arr[13]);
    MatchStack S;
    InitStack(S);   // 初始化一个栈
    for(int i=0;i<length;i++){
        //printf("第%d号元素%c\n",i,arr[i]);
        if(arr[i]=='(' || arr[i]=='[' || arr[i]=='{'){
            //printf("%c入栈\n",arr[i]);
            Push(S, arr[i]);    // 扫描到左括号入栈
        }else if(arr[i]==')' || arr[i]==']' || arr[i]=='}'){
            if(IsEmpty(S)){ // 扫描到右括号，且当前栈空
                return false;   // 匹配失败
            }
            char topData;
            Pop(S, topData);    // 栈顶元素出栈
            //printf("%c出栈匹配%c\n",topData,arr[i]);
            if(arr[i] == ')' && topData != '(')
                return false;
            if(arr[i] == ']' && topData != '[')
                return false;
            if(arr[i] == '}' && topData != '{')
                return false;
        }
    }
    return IsEmpty(S);  // 检索完全部括号后，栈空说明匹配成功
}

// 初始化栈
void InitStack(MatchStack &S){
    S.top = -1;
}

// 判断栈空
bool IsEmpty(MatchStack S){
    //printf("此时栈顶指针为%d\n",S.top);
    if(S.top == -1)
        return true;
    else
        return false;
}

// 新元素进栈
Status Push(MatchStack &S, char x){
    if(S.top == MaxSize-1)
        return Error;
    S.top++;
    S.data[S.top] = x;
    return Success;
}

// 栈顶元素出栈
Status Pop(MatchStack &S, char &data){
    if(S.top == -1)
        return Error;
    data = S.data[S.top];
    S.top--;
    return Success;
}
