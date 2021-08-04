#include <stdio.h>

// 建立大根堆
void MyMaxHeap(int arr[], int len);
// 将以k为根的子树调整为大根堆
void ManageHead(int arr[], int k, int len);
// 堆排序的完整逻辑
void HeapSort(int arr[],int len);
// 建立小根堆
void MyMinHeap(int arr[], int len);
// 将以k为根的子树调整为小根堆
void ManageMinHead(int arr[], int k, int len);
/**
    堆排序：
        A.每一趟将堆顶元素加入有序子序列（与待排序序列中的最后一个元素交换）
        B.将待排序元素序列再次调整为大根堆（小元素不断“下沉”）
    1.建堆时间O(n),排序时间O(nlog2(n)),
        时间复杂度=O(n)+O(nlog2(n))=O(nlog2(n));
    2.堆排序的空间复杂度=O(1)
    3.稳定性：不稳定
    堆插入数据：
        对于小根堆，新元素放到表尾，与父节点对比，若新元素比父节点更小，则将
    二者互换。新元素就这样一路“上浮”，直到无法继续上浮为止。
    堆删除数据：被删除的元素用堆底元素替代，然后让该元素不断“下坠”，直到无法下坠为止。
*/
int main(){
    int arr[] = {0,12,45,7,8,34,65,24,75,35,36,24,18};
    int length = sizeof(arr)/sizeof(int);
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    MyMaxHeap(arr,length-1);
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    HeapSort(arr,length-1);
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}

// 建立大根堆
void MyMaxHeap(int arr[], int len){
    for(int i=len/2; i>0; i--){ // 以树为基准，从下往上调整所有非终端结点
        ManageHead(arr, i, len);
    }
}

// 将以k为根的子树调整为大根堆
void ManageHead(int arr[], int k, int len){
    arr[0] = arr[k];    // arr[0]暂存子树的根结点
    for(int i=2*k; i<=len; i*=2){
        if(i<len && arr[i]<arr[i+1]){
            i++;    // 取k较大的子结点的下标
        }
        if(arr[0]>=arr[i]){
            break;  // 筛选结束
        }else{
            arr[k] = arr[i];    // 将arr[i]调整到双亲结点上
            k = i;  // 修改k值，以便继续向下筛选
        }
    }
    arr[k] = arr[0];    // 被筛选结点的值放入最终位置
}

// 堆排序的完整逻辑
void HeapSort(int arr[],int len){
    MyMaxHeap(arr,len); // 初始化堆

    for(int i=len; i>1; i--){   // n-1趟的交换和建堆
        arr[i] = arr[i]^arr[1]; // 将堆顶元素和堆低元素互换
        arr[1] = arr[i]^arr[1];
        arr[i] = arr[i]^arr[1];
        ManageHead(arr,1,i-1);
    }
}

// 建立小根堆
void MyMinHeap(int arr[], int len){
    for(int i=len/2;i>=1;i--){
        ManageMinHead(arr, i, len);
    }
}

// 将以k为根的子树调整为小根堆
void ManageMinHead(int arr[], int k, int len){
    arr[0] = arr[k];
    for(int i=2*k; i<=len; i*=2){
        if(i<len && arr[i]>arr[i+1]){
            i++;
        }
        if(arr[0]<arr[i]){
            break;
        }else{
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}





