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
// 线性表的查找
int GetIndexById(PersonList *pl, int id);
// 线性表数据添加在末尾
Status AddData(PersonList *pl, Person p);
// 线性表数据的插入
Status InsertData(PersonList *pl, int index,Person p);
// 线性表的删除
Status DeleteData(PersonList *pl, int index);

int main(){
    PersonList *pl;
    int status = InitList(pl);
    if(status){
        for(int i=0;i<5;i++){
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
#if 1
    //获取第几号元素
    // Person *person = GetData(pl,3);
    //printf("%p地址=》id为：%d\n",person,person->id);
    //printf("%p地址=》name为：%s\n",person,person->name);
    //printf("%p地址=》age为：%d\n",person,person->age);
    // 查找id为几的下标
    //int index = GetIndexById(pl,3);
    //printf("在顺序表中的位置为：%d\n",index);
    // 测试添加删除
    Person p;
    p.id = 10;
    // 向末尾添加元素
    //int sta = AddData(pl,p);
    //printf("添加状态%d,插入的id为%d",sta1,GetData(pl,pl->length)->id);
    // 向指定位置插入元素
    //int sta1 = InsertData(pl,1,p);
    //printf("插入状态%d,插入的id为%d",sta1,GetData(pl,0)->id);
    // 删除元素
    int sta2 = DeleteData(pl,0);
    printf("删除状态%d,测试顺序表长度为%d",sta2,pl->length);
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
    if(i<0 || i>pl->length){
        return ERROR;
    }
    return (pl->per+i);
}

// 线性表的查找
int GetIndexById(PersonList *pl, int id){
    for(int i=0;i<pl->length;i++){
        if((pl->per+i)->id == id){
            return i+1;
        }
    }
    return 0;   // 查找失败返回0
}

// 线性表数据的添加
Status AddData(PersonList *pl, Person p){
    if(pl->length == MAXSIZE){
        return ERROR;
    }
    int len = pl->length+1;
    pl->per[len] = p;
    pl->length++;
    return 1;
}

// 线性表数据的插入
Status InsertData(PersonList *pl, int index,Person p){
    if(index<1 || index>pl->length) return ERROR;   // 输入的值不合法
    if(pl->length == MAXSIZE) return ERROR; // 存储空间已满
    for(int i=pl->length-1;i>=index-1;i--){
        (pl->per[i+1]) = pl->per[i];   //  插入位置及其后的元素后移
    }
    (pl->per[index-1]) = p;
    pl->length++;
    return 1;
}

// 线性表的删除
Status DeleteData(PersonList *pl, int index){
    if(index<0 || index>pl->length) return ERROR;
    for(int i=index+1;i<pl->length;i++){
        pl->per[i-1] = pl->per[i];
    }
    pl->length--;
    return 1;
}




