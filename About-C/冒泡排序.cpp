#include <stdio.h>

/**
    ð������
    �ռ临�Ӷȣ�O(1)
    �����������򣩣�O(n)
    ���������򣩣�O(n^2)
    ƽ��ʱ�临�Ӷȣ�O(n^2)
    �ȶ��ԣ��ȶ�
    ���������������
*/
void MyBubbleSort(int arr[], int n);

int main(){
    return 0;
}

// ð������
void MyBubbleSort(int arr[], int n){
    int temp;   // �����ݴ����
    int flag;   // ���һ��û�з���������ֱ���˳�ѭ��
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=n-1;j>i;j--){
            if(arr[j-1] > arr[j]){
                temp = arr[j-1];    // ��������
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
