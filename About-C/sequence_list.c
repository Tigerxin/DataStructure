#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 初始化列表
Status InitList(PersonList *pl);
// 销毁线性表L
void DestroyList(PersonList *pl);
// 清空线性表L
void ClearList(PersonList *pl);
// 线性表L的长度
int GetLength(PersonList *pl);
// 判断线性表L是否为空
int IsEmpty(PersonList *pl);
// 线性表取值
Person* GetData(PersonList *pl, int i);

int main(){
    PersonList *pl;
    int status = InitList(pl);
    if(status){
        for(int i=0;i<10;i++){
            (pl->per+i)->age = 10+i;
            (pl->per+i)->name = "lily";
            (pl->per+i)->id = i;
            pl->length++;
        }
        printf("顺序表长度为:%d\n",pl->length);
        for(int i=0;i<pl->length;i++){
           printf("%p地址=》id为：%d\n",pl->per+i,(pl->per+i)->id);
           printf("%p地址=》name为：%s\n",pl->per+i,(pl->per+i)->name);
           printf("%p地址=》age为：%d\n",pl->per+i,(pl->per+i)->age);
           printf("=========================\n");
        }
    }
#if 0   //查找某一个元素
    Person *person = GetData(pl,3);
    printf("%p地址=》id为：%d\n",person,person->id);
    printf("%p地址=》name为：%s\n",person,person->name);
    printf("%p地址=》age为：%d\n",person,person->age);
#endif
    return 0;
}

// 初始化列表
Status InitList(PersonList *pl){
    pl->per = (Person *)malloc(sizeof(Person)*MAXSIZE);
    if(!(pl->per)) exit(OVERFLOW);
    pl->length = 0;
    return OK;
}

// 销毁线性表L
void DestroyList(PersonList *pl){
    if(pl->per){
        free(pl->per);
        pl->length = 0;
    }; // 释放存储空间
}

// 清空线性表L
void ClearList(PersonList *pl){
    pl->length = 0; // 将线性表的长度置为0
}

// 线性表L的长度
int GetLength(PersonList *pl){
    return pl->length;
}

// 判断线性表L是否为空
int IsEmpty(PersonList *pl){
    if(pl->length == 0){
        return 1;
    }else{
        return 0;
    }
}

// 线性表取值
Person* GetData(PersonList *pl, int i){
    if(i<=0 || i>pl->length){
        return ERROR;
    }
    return (pl->per+(i-1));
}

