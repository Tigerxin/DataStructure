#include <stdio.h>

// 用第一个元素将待排序列划分成左右俩个部分
int SeparateParts(int arr[], int low, int high);
// 快速排序
void QuickSort(int arr[], int low, int high);

/**
    每一层的递归调用只需要处理剩余的待排序元素，时间复杂度不超过O(n)
    1.时间复杂度=O(n*递归层数)
        最好时间复杂度=O(n(lnn/ln2))
        最坏时间复杂度=O(n^2)
        平均时间复杂度=O(n(lnn/ln2))
        快速排序是所有内部排序算法中平均性能最优的排序算法
    2.空间复杂度=O(递归层数)——主要是递归工作栈
        最好空间复杂度=O((lnn/ln2))
        最坏空间复杂度=O(n)
    3.若初始序列有序或逆序，则快速排序的性能最差(因为每次选择的都是最靠边的元素)
    4.尽量选择可以把数据中风的基准元素
        A：选头，中，尾三个位置的元素，取中间值作为枢轴元素；
        B：随机选择一个元素作为基准
    5.稳定性：不稳定

*/
int main(){
    int arr[] = {12,45,13,56,4,78,24,56,35,56};
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    int high = (sizeof(arr)/sizeof(int))-1;
    printf("%d==\n",high);
    QuickSort(arr, 0, high);
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}

// 快速排序
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int pivotPosition = SeparateParts(arr, low, high);  // 划分
        QuickSort(arr, low, pivotPosition-1);   // 划分左子表
        QuickSort(arr, pivotPosition+1, high);  // 划分右子表
    }
}

// 用第一个元素将待排序列划分成左右俩个部分
int SeparateParts(int arr[], int low, int high){
    int pivot = arr[low]; // 数组的第一个元素作为基准
    while(low < high){
        while(low<high && arr[high]>=pivot)
            --high;
        arr[low] = arr[high];   // 比基准小的元素移动到左端
        while(low<high && arr[low]<=pivot)
            ++low;
        arr[high] = arr[low];   // 比基准大的元素移动到右端
    }
    arr[low] = pivot;   // 基准元素存放到最终位置
    return low; // 返回存放基准的最终位置
}

/**
    空间复杂度：O(1)
    时间复杂度：O(n^2)
    算法稳定性：不稳定
    适用性：既可用于顺序表，也可用于链表
*/
void SelectSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;   // 记录最小元素的位置
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;   // 查找每趟中最小的数据下标
        }
        if(minIndex != i){  // 交换元素方法很多，这里使用加减法交换
            arr[i] = arr[minIndex]+arr[i];
            arr[minIndex] = arr[i]-arr[minIndex];
            arr[i] = arr[i]-arr[minIndex];
        }
    }
}

