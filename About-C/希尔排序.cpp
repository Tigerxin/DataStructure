#include <stdio.h>

/** ϣ������
    ʱ�临�Ӷȣ�����������d1��d2��d3...��ѡ���йأ��޷�ʹ����ѧ���ֶ�֤��ȷ�е�ʱ�临�Ӷ�
        ������nΪ1ʱ���ʱ�临�Ӷ�ΪO(n^2),��n��ĳ����Χ��ʱ���ɴ�O(n^1.3)
    �ȶ��ԣ����ȶ�
    �����ԣ���������˳���������������
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


// ϣ������
void ShellSort(int arr[], int n){
    int d, i, j;
    // arr[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ���Ե�
    for(d=n/2; d>=1; d=d/2){    // �����仯
        for(i=d+1; i<=n; ++i){
            if(arr[i]<arr[i-d]){
                arr[0] = arr[i];    // �ݴ���arr[0]
                for(j=i-d; j>0 && arr[0]<arr[j]; j-=d){
                    arr[j+d] = arr[j];  // ��¼���ƣ����Ҳ���λ��
                }
                arr[j+d] = arr[0];  // ����
            }
        }
    }
}
