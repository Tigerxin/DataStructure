#include <stdio.h>

// �õ�һ��Ԫ�ؽ��������л��ֳ�������������
int SeparateParts(int arr[], int low, int high);
// ��������
void QuickSort(int arr[], int low, int high);

/**
    ÿһ��ĵݹ����ֻ��Ҫ����ʣ��Ĵ�����Ԫ�أ�ʱ�临�ӶȲ�����O(n)
    1.ʱ�临�Ӷ�=O(n*�ݹ����)
        ���ʱ�临�Ӷ�=O(n(lnn/ln2))
        �ʱ�临�Ӷ�=O(n^2)
        ƽ��ʱ�临�Ӷ�=O(n(lnn/ln2))
        ���������������ڲ������㷨��ƽ���������ŵ������㷨
    2.�ռ临�Ӷ�=O(�ݹ����)������Ҫ�ǵݹ鹤��ջ
        ��ÿռ临�Ӷ�=O((lnn/ln2))
        ��ռ临�Ӷ�=O(n)
    3.����ʼ������������������������������(��Ϊÿ��ѡ��Ķ�����ߵ�Ԫ��)
    4.����ѡ����԰������з�Ļ�׼Ԫ��
        A��ѡͷ���У�β����λ�õ�Ԫ�أ�ȡ�м�ֵ��Ϊ����Ԫ�أ�
        B�����ѡ��һ��Ԫ����Ϊ��׼
    5.�ȶ��ԣ����ȶ�

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

// ��������
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int pivotPosition = SeparateParts(arr, low, high);  // ����
        QuickSort(arr, low, pivotPosition-1);   // �������ӱ�
        QuickSort(arr, pivotPosition+1, high);  // �������ӱ�
    }
}

// �õ�һ��Ԫ�ؽ��������л��ֳ�������������
int SeparateParts(int arr[], int low, int high){
    int pivot = arr[low]; // ����ĵ�һ��Ԫ����Ϊ��׼
    while(low < high){
        while(low<high && arr[high]>=pivot)
            --high;
        arr[low] = arr[high];   // �Ȼ�׼С��Ԫ���ƶ������
        while(low<high && arr[low]<=pivot)
            ++low;
        arr[high] = arr[low];   // �Ȼ�׼���Ԫ���ƶ����Ҷ�
    }
    arr[low] = pivot;   // ��׼Ԫ�ش�ŵ�����λ��
    return low; // ���ش�Ż�׼������λ��
}

/**
    �ռ临�Ӷȣ�O(1)
    ʱ�临�Ӷȣ�O(n^2)
    �㷨�ȶ��ԣ����ȶ�
    �����ԣ��ȿ�����˳���Ҳ����������
*/
void SelectSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;   // ��¼��СԪ�ص�λ��
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;   // ����ÿ������С�������±�
        }
        if(minIndex != i){  // ����Ԫ�ط����ܶ࣬����ʹ�üӼ�������
            arr[i] = arr[minIndex]+arr[i];
            arr[minIndex] = arr[i]-arr[minIndex];
            arr[i] = arr[i]-arr[minIndex];
        }
    }
}

