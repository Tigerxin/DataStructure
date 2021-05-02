#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLen 255  // 预定义最大串长为255

// 顺序存储静态定义方式
typedef struct{
    char arr[MaxLen];   // 每个分量存储一个字符串
    int length;
}MySString;

// 顺序存储动态定义方式
typedef struct{
    char *arr;  // 按串长分配存储区，arr指向串的基地址
    int length;
}MyDString;

// 链式存储（存储密度低）
typedef struct LMyStringNode{
    char ch;    // 每个结点存储1个字符
    struct LMyStringNode *next;
}LMyStringNode,*LMyString;

// 链式存储（存储密度高）
typedef struct MLMyStringNode{
    char ch[4]; // 每个结点存多个字符
    struct MLMyStringNode *next;
}MLMyStringNode, *MLMyString;

void applySpaceForD(MyDString mds);
// 求子串
bool SubString(MySString &str, MySString S, int pos, int len);
// 串的比较操作
int StrCompare(MySString S, MySString T);
// 串的定位操作
int Index(MySString S, MySString T);
// 获取串的长度
int GetStrLength(MySString str);
// 朴素模式匹配串
int SimpleMatch(MySString S, MySString T);
// KMP算法代码
int KMPMatch(MySString S, MySString T);
// 求模式串T的next数组
void Get_Next(MySString T, int next[]);

int main(){
    MySString S = {"woaini",0};
    char arr[255] = "woaini";
    printf("字符串的长度为:%s\n",arr);
    int len = GetStrLength(S);
    printf("字符串的长度为:%d\n",len);
    return 0;
}

void applySpaceForD(MyDString mds){
    mds.arr = (char *)malloc(MaxLen*sizeof(char));
    mds.length = 0;
}

// 获取串的长度
int GetStrLength(MySString str){
    int len = sizeof(str.arr)/sizeof(char);
    int length;
    for(int i=0;i<len;i++){
        if(str.arr[i] == '\0'){
            str.length = length;
            return str.length;
        }
        length++;
    }
    return str.length;
}

// 求子串
bool SubString(MySString &str, MySString S, int pos, int len){
    // 子串范围越界
    if(pos+len-1 > S.length)
        return false;
    for(int i=pos;i<pos+len;i++){
        str.arr[i-pos+1] = S.arr[i];
    }
    str.length = len;
    return true;
}

// 串的比较操作
int StrCompare(MySString S, MySString T){
    for(int i=1;i<=S.length && i<=T.length;i++){
        if(S.arr[i]!=T.arr[i])
            return S.arr[i]-T.arr[i];
    }
    // 扫描过所有字符都相同，则长度长的串更大
    return S.length-T.length;
}

// 串的定位操作
int Index(MySString S, MySString T){
    int i=1, n=GetStrLength(S), m=GetStrLength(T);
    MySString sub;
    while(i <= n-m+1){
        SubString(sub, S, i, m);
        if(StrCompare(sub, T) != 0)
            ++i;
        else
            return i;   // 返回子串在主串中的位置
    }
    return 0;   // S中不存在与T相等的子串
}

// 朴素模式匹配串
int SimpleMatch(MySString S, MySString T){
    int k=1;
    int i=k, j=1;
    while(i<=S.length && j<=T.length){
        if(S.arr[i] == T.arr[j]){
            ++i;
            ++j;    // 继续比较后继字符
        }else{
            k++;    // 检查下一个子串
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
}

// KMP算法代码
int KMPMatch(MySString S, MySString T){
    int i=1,j=1;
    int next[T.length+1];
    Get_Next(S,next);   // 求模式串的next数组
    while(i<=S.length && j<=T.length){
        if(j==0 || S.arr[i]==T.arr[j]){
            ++i;
            ++j;    // 继续比较后继字符
        }else{
            j = next[j];    // 模式串向右移动
        }
    }
    if(j>T.length)
        return i-T.length;  // 匹配成功
    else
        return 0;
}

// 求模式串T的next数组
void Get_Next(MySString T, int next[]){
    int i=1, j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0 || T.arr[i]==T.arr[j]){
            ++i;
            ++j;
            // 若pi=pj，则next[j+1]=next[j]+1
            next[i]=j;
        }else{
            // 否则令j=next[j],循环继续
            j=next[j];
        }
    }
    // nextval数组的求法
    /*
    int nextval[(sizeof(next)/sizeof(int))];
    for(int k=2;k<T.length;k++){
        if(T.arr[next[k] == T.arr[k])
            nextval[k] = nextval[next[j]];
        else
            nextval[k] = next[k];
    }
    */
}



