#include <stdio.h>

// ��ų�ʼ����
typedef struct LinkNode{
    char *data;
    struct LinkNode *next;
}LinkNode, *LinkList;

// ��ŷ������
typedef struct{ // ��ʽ����
    LinkNode *head,*rear;   // ���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;

/**
    ��Ҫr���������У��ռ临�Ӷ�=O��r��
    һ�˷���O(n),һ���ռ�O(r),�ܹ�d�˷��䣬�ռ����ܵ�ʱ�临�Ӷ�=O(d(n+r))
    �ȶ��ԣ��ȶ�
*/
int main(){
    return 0;
}
