#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10  // 静态链表的最大长度

struct Node{    // 静态链表结构类型的定义
    char *name; // 存储数据元素
    int next;   // 下一个元素的数组下标
};

typedef struct{
    char *name;
    int next;
}static_list[MaxSize];  // 引用的时候和数组类似

int main(){
    struct Node arr1[MaxSize];   // 与数组的定义类似
    static_list arr2;
    return 0;
}
