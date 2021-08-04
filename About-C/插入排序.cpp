#include <stdio.h>
#include <stdlib.h>

// ֱ�Ӳ�������
void InsertSort(int arr[],int n);
/** ֱ�Ӳ������򣨴��ڱ���

    1.�ռ临�Ӷȣ�O(1)
    2.���ʱ�临�Ӷ�(ȫ������)��O(n)
    3.�ʱ�临�Ӷ�(ȫ������)��O(n^2)
    4.ƽ��ʱ�临�Ӷȣ�O(n^2)

    �㷨�ȶ��ԣ��ȶ�
*/
void InsertSortOne(int arr[],int n);
// �۰��������
void InsertSortHalf(int arr[], int n);

int main(){
    return 0;
}

// ֱ�Ӳ�������
void InsertSort(int arr[],int n){
    int i, j, temp;
    for(i=1; i<n; i++){ // ����Ԫ�ز����Ѿ��ź����������
        if(arr[i] < arr[i-1]){  // ��arr[i]�ؼ���С��ǰ��
            temp = arr[i];  // ʹ��temp�ݴ�arr[i]
            for(j=i-1; j>=0 && arr[j]>temp; --j){
                arr[j+1] = arr[j];  // ���д���temp��Ԫ�ض����Ųλ
            }
            arr[j+1] = temp;    // ���Ƶ�����λ��
        }
    }
}

// ֱ�Ӳ������򣨴��ڱ���
void InsertSortOne(int arr[],int n){
    int i,j;
    for(i=2; i<=n; i++){    // ���ν�arr[2],arr[n]���뵽ǰ�����ź����������
        if(arr[i] < arr[i-1]){  // ��arr[i]�ؼ�����С����ǰ������arr[i]���������
            arr[0] = arr[i];    // ����Ϊ�ڱ���arr[0]�����Ԫ��
            for(j=i-1; arr[0]<arr[j]; --j){ // �Ӻ���ǰ���Ҵ�����λ��
                arr[j+1] = arr[j];  // ���Ųλ
            }
            arr[j+1] = arr[0];  // ���Ƶ�����λ��
        }
    }
}

// �۰��������
void InsertSortHalf(int arr[], int n){
    int i,j,low,high,mid;
    for(i=2; i<=n; i++){    // ���ν�arr[2]��arr[n]����ǰ������ź����������
        arr[0] = arr[1];    // ��arr[i]�ݴ浽arr[0]
        low = 1;    // �����۰���ҵķ�Χ
        high = i-1;
        while(low <= high){ // �۰����
            mid = (low+high)/2; // ȡ�м��
            if(arr[mid] > arr[0]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        for(j = i-1;j >= high+1; --j){
            arr[j+1] = arr[j]; // ͳһ����Ԫ�أ��ճ�����λ��
        }
        arr[high+1] = arr[0];   // �������
    }
}







