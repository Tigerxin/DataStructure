#include <stdio.h>
#include <stdlib.h>

typedef struct{ // 查找表的数据结构（顺序表）
    int *arr;   // 动态数组基址
    int length; // 表的长度
}SequenceTable;

// 分块查找索引表
typedef struct{
    int maxValue;
    int low,high;
}MyIndex;
// 分块查找中顺序表存储的实际元素
int List[100];

// 顺序查找
int Search_Seq(SequenceTable ST, int data);
// 折半查找
int Binary_Search(SequenceTable ST, int data);

int main(){
    return 0;
}

// 顺序查找
int Search_Seq(SequenceTable ST, int data){
    int i;
    for(i=0; i < ST.length && ST.arr[i] != data; ++i);
    // 查找成功，则返回元素下标；查找失败，则返回-1
    return i==ST.length ? -1 : i;
}

// 折半查找
int Binary_Search(SequenceTable ST, int data){
    int low = 0;
    int high = ST.length-1;
    int mid;
    while(low <= high){
        mid = (low + high)/2;   // 取中间位置
        if(ST.arr[mid] == data){
            return mid; // 查找成功则返回所在位置
        }else if(ST.arr[mid] > key){
            high = mid - 1; // 在前半部分继续查找
        }else{
            low = mid + 1;  // 在后半部分继续查找
        }
        return -1;  // 查找失败，返回-1
    }

}
