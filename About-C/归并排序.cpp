#include <stdio.h>

#define ArrSize 20

int *temp = (int *)malloc(ArrSize*sizeof(int)); // �м�����
// arr[low...mid]��arr[mid+1...high]�������򣬽������ֹ鲢
void MergeArr(int arr[], int low, int mid, int high);
// �鲢����
void MergeSort(int arr[], int low, int high);

//
int main(){
    return 0;
}

// arr[low...mid]��arr[mid+1...high]�������򣬽������ֹ鲢
void MergeArr(int arr[], int low, int mid, int high){
    int i,j,k;
    for(k=low; k<=high; k++){
        temp[k] = arr[k];
    }
    for(i=low, j=mid+1,k=i; i<=mid && j<=high; k++){
        if(temp[i] <= temp[j]){
            arr[k] = temp[i++]; // ����Сֵ���Ƶ�arr��
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

// �鲢����
void MergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high)/2; // ���м仮��
        MergeSort(arr, low, mid);   // ��������鲢����
        MergeSort(arr, mid+1, high);   // ���ҷ����鲢����
        MergeArr(arr, low, mid, high)
    }
}





