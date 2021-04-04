#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 线性表存储空间的初始分配量
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

// Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

typedef struct{
    int id;
    char *name;
    int age;
} Person;

typedef struct{
    Person *per;
    int length;
} PersonList;

int main(){
    return 0;
}
