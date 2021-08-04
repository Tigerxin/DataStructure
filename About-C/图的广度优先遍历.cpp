#include <stdio.h>
#include <stdlib.h>

#define Max_Vertex_Num 10
// ���ʱ������
bool visited[Max_Vertex_Num];
// �ڽӾ��󷨴洢
typedef struct{
    char Vex[MaxVertexNum]; // �����
    int Edge[MaxVertexNum][MaxVertexNum];   // �ڽӾ��󣬱߱�
    int vexnum,arcnum;  // ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;

// ������ȱ���
void BFS(MGraph G, int v);
// BFSֻ�ܴ������������ӵ�ͼ������ͼ�п��ܰ��������������ͼ
void BFSTraverse(MGraph G);

int main(){
    return 0;
}

// ������ȱ���
void BFS(MGraph G, int v){
    visit(v);   // ���ʳ�ʼ����v
    visited[v]=true;    // ��v���ѷ��ʱ��
    Enqueue(Q,v);   // ����v�����Q
    while(!isEmpty(0)){
        DeQueue(Q,v);   // ����v������
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            // ���v�����ڽӵ�
            if(!visited[w]){    // wΪv����δ���ʵ��ڽӽ��
                visit(w);   // ���ʶ���w
                visited[w]=true;    // ��w���ѷ��ʱ��
                EnQueue(Q,w);   // ����w�����
            }
        }
    }
}

// BFSֻ�ܴ������������ӵ�ͼ������ͼ�п��ܰ��������������ͼ
void BFSTraverse(MGraph G){
    for(int i=0;i<G.vexnum;++i){
        visited[i]=false;   // ���ʱ�������ʼ��
    }
    InitQueue(Q);   // ��ʼ������
    for(int i=0;i<G.vexnum;i++){    // ��0�Ŷ��㿪ʼ����
        if(!visited[i]){    // ��ÿһ����ͨ��������һ��BFS
            BFS(G,i);   // viδ���ʹ�����vi��ʼBFS
        }
    }
}
