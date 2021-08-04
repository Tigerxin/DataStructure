#include <stdio.h>
#include <stdlib.h>

typedef struct{ // ���ұ�����ݽṹ��˳���
    int *arr;   // ��̬�����ַ
    int length; // ��ĳ���
}SequenceTable;

// �ֿ����������
typedef struct{
    int maxValue;
    int low,high;
}MyIndex;
// �ֿ������˳���洢��ʵ��Ԫ��
int List[100];

// ˳�����
int Search_Seq(SequenceTable ST, int data);
// �۰����
int Binary_Search(SequenceTable ST, int data);

int main(){
    return 0;
}

// ˳�����
int Search_Seq(SequenceTable ST, int data){
    int i;
    for(i=0; i < ST.length && ST.arr[i] != data; ++i);
    // ���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�-1
    return i==ST.length ? -1 : i;
}

// �۰����
int Binary_Search(SequenceTable ST, int data){
    int low = 0;
    int high = ST.length-1;
    int mid;
    while(low <= high){
        mid = (low + high)/2;   // ȡ�м�λ��
        if(ST.arr[mid] == data){
            return mid; // ���ҳɹ��򷵻�����λ��
        }else if(ST.arr[mid] > key){
            high = mid - 1; // ��ǰ�벿�ּ�������
        }else{
            low = mid + 1;  // �ں�벿�ּ�������
        }
        return -1;  // ����ʧ�ܣ�����-1
    }

}
