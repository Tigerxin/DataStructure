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

void DFSTraverse(MGraph G);
void DFS(MGraph G,int v);

int main(){
    return 0;
}
void DFSTraverse(MGraph G){
    for(int v=0;v<G.vexnum;++v)
        visited[v] = false; // ��ʼ���ѷ��ʱ������
    for(int v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}

void DFS(MGraph G,int v){   // �Ӷ���v������������ȱ���ͼG
    visit(v);   // ���ʶ���v
    visited[v] = true;  // ���ѷ��ʱ��
    for(w=FirstNerghbor(G,v);w>=0;w=NextNeighor(G,v,w))
        if(!visited[w]){    // wΪu����δ���ʵ��ڽӶ���
            DFS(G,w);
        }

}



