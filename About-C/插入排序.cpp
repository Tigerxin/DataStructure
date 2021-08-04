#include <stdio.h>
#include <stdlib.h>

// 直接插入排序
void InsertSort(int arr[],int n);
/** 直接插入排序（带哨兵）

    1.空间复杂度：O(1)
    2.最好时间复杂度(全部有序)：O(n)
    3.最坏时间复杂度(全部逆序)：O(n^2)
    4.平均时间复杂度：O(n^2)

    算法稳定性：稳定
*/
void InsertSortOne(int arr[],int n);
// 折半插入排序
void InsertSortHalf(int arr[], int n);

int main(){
    return 0;
}

// 直接插入排序
void InsertSort(int arr[],int n){
    int i, j, temp;
    for(i=1; i<n; i++){ // 将各元素插入已经排好序的序列中
        if(arr[i] < arr[i-1]){  // 若arr[i]关键字小于前驱
            temp = arr[i];  // 使用temp暂存arr[i]
            for(j=i-1; j>=0 && arr[j]>temp; --j){
                arr[j+1] = arr[j];  // 所有大于temp的元素都向后挪位
            }
            arr[j+1] = temp;    // 复制到插入位置
        }
    }
}

// 直接插入排序（带哨兵）
void InsertSortOne(int arr[],int n){
    int i,j;
    for(i=2; i<=n; i++){    // 依次将arr[2],arr[n]插入到前面已排好序额序列中
        if(arr[i] < arr[i-1]){  // 若arr[i]关键字码小于其前驱，将arr[i]插入有序表
            arr[0] = arr[i];    // 复制为哨兵，arr[0]不存放元素
            for(j=i-1; arr[0]<arr[j]; --j){ // 从后往前查找待插入位置
                arr[j+1] = arr[j];  // 向后挪位
            }
            arr[j+1] = arr[0];  // 复制到插入位置
        }
    }
}

// 折半插入排序
void InsertSortHalf(int arr[], int n){
    int i,j,low,high,mid;
    for(i=2; i<=n; i++){    // 依次将arr[2]到arr[n]插入前面的已排好序的序列中
        arr[0] = arr[1];    // 将arr[i]暂存到arr[0]
        low = 1;    // 设置折半查找的范围
        high = i-1;
        while(low <= high){ // 折半查找
            mid = (low+high)/2; // 取中间点
            if(arr[mid] > arr[0]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        for(j = i-1;j >= high+1; --j){
            arr[j+1] = arr[j]; // 统一后移元素，空出插入位置
        }
        arr[high+1] = arr[0];   // 插入操作
    }
}







