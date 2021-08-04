#include <stdio.h>

// ���������
void MyMaxHeap(int arr[], int len);
// ����kΪ������������Ϊ�����
void ManageHead(int arr[], int k, int len);
// ������������߼�
void HeapSort(int arr[],int len);
// ����С����
void MyMinHeap(int arr[], int len);
// ����kΪ������������ΪС����
void ManageMinHead(int arr[], int k, int len);
/**
    ������
        A.ÿһ�˽��Ѷ�Ԫ�ؼ������������У�������������е����һ��Ԫ�ؽ�����
        B.��������Ԫ�������ٴε���Ϊ����ѣ�СԪ�ز��ϡ��³�����
    1.����ʱ��O(n),����ʱ��O(nlog2(n)),
        ʱ�临�Ӷ�=O(n)+O(nlog2(n))=O(nlog2(n));
    2.������Ŀռ临�Ӷ�=O(1)
    3.�ȶ��ԣ����ȶ�
    �Ѳ������ݣ�
        ����С���ѣ���Ԫ�طŵ���β���븸�ڵ�Աȣ�����Ԫ�رȸ��ڵ��С����
    ���߻�������Ԫ�ؾ�����һ·���ϸ�����ֱ���޷������ϸ�Ϊֹ��
    ��ɾ�����ݣ���ɾ����Ԫ���öѵ�Ԫ�������Ȼ���ø�Ԫ�ز��ϡ���׹����ֱ���޷���׹Ϊֹ��
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

// ���������
void MyMaxHeap(int arr[], int len){
    for(int i=len/2; i>0; i--){ // ����Ϊ��׼���������ϵ������з��ն˽��
        ManageHead(arr, i, len);
    }
}

// ����kΪ������������Ϊ�����
void ManageHead(int arr[], int k, int len){
    arr[0] = arr[k];    // arr[0]�ݴ������ĸ����
    for(int i=2*k; i<=len; i*=2){
        if(i<len && arr[i]<arr[i+1]){
            i++;    // ȡk�ϴ���ӽ����±�
        }
        if(arr[0]>=arr[i]){
            break;  // ɸѡ����
        }else{
            arr[k] = arr[i];    // ��arr[i]������˫�׽����
            k = i;  // �޸�kֵ���Ա��������ɸѡ
        }
    }
    arr[k] = arr[0];    // ��ɸѡ����ֵ��������λ��
}

// ������������߼�
void HeapSort(int arr[],int len){
    MyMaxHeap(arr,len); // ��ʼ����

    for(int i=len; i>1; i--){   // n-1�˵Ľ����ͽ���
        arr[i] = arr[i]^arr[1]; // ���Ѷ�Ԫ�غͶѵ�Ԫ�ػ���
        arr[1] = arr[i]^arr[1];
        arr[i] = arr[i]^arr[1];
        ManageHead(arr,1,i-1);
    }
}

// ����С����
void MyMinHeap(int arr[], int len){
    for(int i=len/2;i>=1;i--){
        ManageMinHead(arr, i, len);
    }
}

// ����kΪ������������ΪС����
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





