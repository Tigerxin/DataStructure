#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];  // ��̬�����Ŷ���Ԫ��
    int qhead, qend;    // ��ͷָ��Ͷ�βָ��
    // int size;    // ����ͨ��size������¼�洢���ݵĸ���
    // int tag;     // �����е���ɾ��0/����1
}SeqQueue;

// ��ʼ������
void InitQueue(SeqQueue &Q);
// �ж϶����Ƿ�Ϊ��
bool IsEmpty(SeqQueue &Q);
// ���
bool InQueue(SeqQueue &Q, int data);
// ����
bool OutQueue(SeqQueue &Q, int &data);
// ���ͷԪ��
bool GetQueueHead(SeqQueue &Q, int &data);

int main(){
    // ����һ������
    SeqQueue Q;
    InitQueue(Q);
    printf("�����Ƿ�Ϊ��:%s\n",IsEmpty(Q) ? "��" : "��");
    bool isIn = InQueue(Q,3);
    printf("����Ƿ�ɹ�:%s\n",isIn ? "��" : "��");
    printf("�����Ƿ�Ϊ��:%s\n",IsEmpty(Q) ? "��" : "��");
    int data;
    printf("�Ƿ��ж���Ԫ��:%s\n",GetQueueHead(Q,data) ? "��" : "��");
    printf("��ʱ����Ԫ��Ϊ:%d\n",data);
    return 0;
}

// ��ʼ������
void InitQueue(SeqQueue &Q){
    // ��ʼ��ʱ��ͷ��βָ��0
    Q.qhead = Q.qend = 0;
}

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(SeqQueue &Q){
    if(Q.qhead == Q.qend)   // ��ζ�Ż��ڳ�ʼλ��
        return true;
    else
        return false;
}

// ���
bool InQueue(SeqQueue &Q, int data){
    if((Q.qend+1) % MaxSize == Q.qhead) // �ж϶���
        return false;
    Q.data[Q.qend] = data;  // �����ݲ����β
    Q.qend = (Q.qend+1) % MaxSize;    // ��βָ���1ȡģ
    return true;
}

// ����
bool OutQueue(SeqQueue &Q, int &data){
    if(Q.qend == Q.qhead)
        return false;   // �ӿ�
    data = Q.data[Q.qhead];
    Q.qhead = (Q.qhead+1) % MaxSize;
    return true;
}

// ���ͷԪ��
bool GetQueueHead(SeqQueue &Q, int &data){
    if(Q.qhead == Q.qend)
        return false;
    data = Q.data[Q.qhead];
    return true;
}




