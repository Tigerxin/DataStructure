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

// 广度优先遍历
void BFS(MGraph G, int v);
// BFS只能处理个结点相连接的图，但是图中可能包含俩个分离的子图
void BFSTraverse(MGraph G);

int main(){
    return 0;
}

// 广度优先遍历
void BFS(MGraph G, int v){
    visit(v);   // 访问初始顶点v
    visited[v]=true;    // 对v做已访问标记
    Enqueue(Q,v);   // 顶点v入队列Q
    while(!isEmpty(0)){
        DeQueue(Q,v);   // 顶点v出队列
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            // 检测v所有邻接点
            if(!visited[w]){    // w为v的尚未访问的邻接结点
                visit(w);   // 访问顶点w
                visited[w]=true;    // 对w做已访问标记
                EnQueue(Q,w);   // 顶点w入队列
            }
        }
    }
}

// BFS只能处理个结点相连接的图，但是图中可能包含俩个分离的子图
void BFSTraverse(MGraph G){
    for(int i=0;i<G.vexnum;++i){
        visited[i]=false;   // 访问标记数组初始化
    }
    InitQueue(Q);   // 初始化队列
    for(int i=0;i<G.vexnum;i++){    // 从0号顶点开始遍历
        if(!visited[i]){    // 对每一个连通分量调用一次BFS
            BFS(G,i);   // vi未访问过，从vi开始BFS
        }
    }
}
