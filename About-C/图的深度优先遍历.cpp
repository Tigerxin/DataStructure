#include <stdio.h>
#include <stdlib.h>

#define Max_Vertex_Num 10
// 访问标记数组
bool visited[Max_Vertex_Num];
// 邻接矩阵法存储
typedef struct{
    char Vex[MaxVertexNum]; // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum];   // 邻接矩阵，边表
    int vexnum,arcnum;  // 图的当前顶点数和边数/弧数
}MGraph;

void DFSTraverse(MGraph G);
void DFS(MGraph G,int v);

int main(){
    return 0;
}
void DFSTraverse(MGraph G){
    for(int v=0;v<G.vexnum;++v)
        visited[v] = false; // 初始化已访问标记数据
    for(int v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}

void DFS(MGraph G,int v){   // 从顶点v出发，深度优先遍历图G
    visit(v);   // 访问顶点v
    visited[v] = true;  // 设已访问标记
    for(w=FirstNerghbor(G,v);w>=0;w=NextNeighor(G,v,w))
        if(!visited[w]){    // w为u的尚未访问的邻接顶点
            DFS(G,w);
        }

}



