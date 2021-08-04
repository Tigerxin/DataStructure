#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100 // ͼ�ж�����Ŀ�����ֵ

typedef struct ArcNode{ // �߱���
    int adjvex; // �û���ָ��Ķ����λ��
    struct ArcNode *nextarc;    // ָ����һ������ָ��
    // InfoType info;   ���ı�Ȩֵ
}ArcNode;
typedef struct VNode{   // �������
    int data;   // ������Ϣ
    ArcNode *firstarc;  // ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;   // �ڽӱ�
    int vexnum,arcnum;  // ͼ�Ķ������ͻ���
}Graph; // �����ڽӱ�洢��ͼ����

int indegree[10];   // �洢ͼ��ÿ���������
int print[10];  // �洢��������

// ��������
bool TopologicalSort(Graph G);
// ����������
bool NiTopologicalSort(Graph G);

int main(){
    return 0;
}

// ��������
bool TopologicalSort(Graph G){
    InitStack(S);   // ��ʼ��ջ���洢���Ϊ0�Ķ���
    for(int i=0;i<G.vexnum;i++){
        if(indegree[i] == 0){
            Push(S, i); // ���������Ϊ0�Ķ����ջ
        }
    }
    int mycount = 0;    // ��������¼��ǰ�Ѿ�����Ķ�����
    while(!IsEmpty(S)){ // ջ���գ���������Ϊ0�Ķ���
        Pop(S, i);  // ջ��Ԫ�س�ջ
        print[mycount] = i; // �������i
        int v;
        for(ArcNode p=G.vertices[i].firstarc;p;p->nextarc){
            // ������iָ��Ķ������ȼ�1�����ҽ���ȼ�Ϊ0�Ķ���ѹ��ջS
            v = p->adjvex;
            if(!(--indegree[v])){
                Push(S,v);  // ���Ϊ0������ջ
            }
        }
    }
    if(mycount < G.vexnum)
        return false;   // ����ʧ�ܣ�����ͼ���л�·
    else
        return true;    // ��������ɹ�
}




