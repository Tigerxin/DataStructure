#include <stdio.h>

/**
    冒泡排序
    空间复杂度：O(1)
    最好情况（有序）：O(n)
    最坏情况（逆序）：O(n^2)
    平均时间复杂度：O(n^2)
    稳定性：稳定
    对链表进行排序：是
*/
void MyBubbleSort(int arr[], int n);

int main(){
    return 0;
}

// 冒泡排序
void MyBubbleSort(int arr[], int n){
    int temp;   // 定义暂存变量
    int flag;   // 如果一趟没有发生交换则直接退出循环
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=n-1;j>i;j--){
            if(arr[j-1] > arr[j]){
                temp = arr[j-1];    // 交换俩者
                arr[j-1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            return;
        }
    }
}
