#include <stdio.h>

#define ArrSize 20

int *temp = (int *)malloc(ArrSize*sizeof(int)); // 中间数组
// arr[low...mid]和arr[mid+1...high]各自有序，将俩部分归并
void MergeArr(int arr[], int low, int mid, int high);
// 归并排序
void MergeSort(int arr[], int low, int high);

//
int main(){
    return 0;
}

// arr[low...mid]和arr[mid+1...high]各自有序，将俩部分归并
void MergeArr(int arr[], int low, int mid, int high){
    int i,j,k;
    for(k=low; k<=high; k++){
        temp[k] = arr[k];
    }
    for(i=low, j=mid+1,k=i; i<=mid && j<=high; k++){
        if(temp[i] <= temp[j]){
            arr[k] = temp[i++]; // 将较小值复制到arr中
        }else{
            arr[k] = temp[j++];
        }
    }
    while(i <= mid){
        arr[k++] = temp[i++];
    }
    while(j <= high){
        arr[k++] = temp[j++];
    }
}

// 归并排序
void MergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high)/2; // 从中间划分
        MergeSort(arr, low, mid);   // 对左分区归并排序
        MergeSort(arr, mid+1, high);   // 对右分区归并排序
        MergeArr(arr, low, mid, high)
    }
}





