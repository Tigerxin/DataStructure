#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10  // ��̬�������󳤶�

struct Node{    // ��̬����ṹ���͵Ķ���
    char *name; // �洢����Ԫ��
    int next;   // ��һ��Ԫ�ص������±�
};

typedef struct{
    char *name;
    int next;
}static_list[MaxSize];  // ���õ�ʱ�����������

int main(){
    struct Node arr1[MaxSize];   // ������Ķ�������
    static_list arr2;
    return 0;
}
