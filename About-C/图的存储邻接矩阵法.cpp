#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100    // ������Ŀ�����ֵ

/*
    �ڽӾ���洢����ͼ
    �ڽӱ�洢ϡ��ͼ
*/

// �ڽӾ��󷨴洢
typedef struct{
    char Vex[MaxVertexNum]; // �����
    int Edge[MaxVertexNum][MaxVertexNum];   // �ڽӾ��󣬱߱�
    int vexnum,arcnum;  // ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;

// ��/��
typedef struct ArcNode{
    int adjvex; // �߻�ָ���ĸ����
    struct ArcNode *next;   // ָ����һ������ָ��
    // InfoType info;   // ��Ȩֵ
}ArcNode;

// �ڽӱ�洢
typedef struct VNode{
    int data;    // ������Ϣ
    ArcNode *first; // ��һ����/��
}VNode,AdjList[MaxVertexNum];

int main(){
    return 0;
}
