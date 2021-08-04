#include <stdio.h>

/** 希尔排序
    时间复杂度：和增量序列d1，d2，d3...的选择有关，无法使用数学的手段证明确切的时间复杂度
        当增量n为1时，最坏时间复杂度为O(n^2),当n在某个范围内时，可达O(n^1.3)
    稳定性：不稳定
    适用性：仅适用于顺序表，不适用于链表
*/
void ShellSort(int arr[], int n);

int main(){
    float FPI = 3.14;
    float data1 = 3.78;
    int IPI = FPI;
    int Idata1 = data1;
    int data2 = 5.234;
    int data3 = 5.56;
    printf("%f===%d\n",FPI, IPI);
    printf("%f===%d\n",data1, Idata1);
    printf("%d===%d\n",data2, data3);
    int arr[] = {0,12,56,24,45,66,67,35,25,2};
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    ShellSort(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}


// 希尔排序
void ShellSort(int arr[], int n){
    int d, i, j;
    // arr[0]只是暂存单元，不是哨兵，当j<=0时，插入位置以到
    for(d=n/2; d>=1; d=d/2){    // 步长变化
        for(i=d+1; i<=n; ++i){
            if(arr[i]<arr[i-d]){
                arr[0] = arr[i];    // 暂存在arr[0]
                for(j=i-d; j>0 && arr[0]<arr[j]; j-=d){
                    arr[j+d] = arr[j];  // 记录后移，查找插入位置
                }
                arr[j+d] = arr[0];  // 插入
            }
        }
    }
}
