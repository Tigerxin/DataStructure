#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100 // 图中顶点树目的最大值

typedef struct ArcNode{ // 边表结点
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *nextarc;    // 指向下一条弧的指针
    // InfoType info;   网的边权值
}ArcNode;
typedef struct VNode{   // 顶点表结点
    int data;   // 顶点信息
    ArcNode *firstarc;  // 指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;   // 邻接表
    int vexnum,arcnum;  // 图的顶点数和弧数
}Graph; // 是以邻接表存储的图类型

int indegree[10];   // 存储图中每个结点的入度
int print[10];  // 存储拓扑序列

// 拓扑排序
bool TopologicalSort(Graph G);
// 逆拓扑排序
bool NiTopologicalSort(Graph G);

int main(){
    return 0;
}

// 拓扑排序
bool TopologicalSort(Graph G){
    InitStack(S);   // 初始化栈，存储入度为0的顶点
    for(int i=0;i<G.vexnum;i++){
        if(indegree[i] == 0){
            Push(S, i); // 将所有入度为0的顶点进栈
        }
    }
    int mycount = 0;    // 计数，记录当前已经输出的顶点数
    while(!IsEmpty(S)){ // 栈不空，则存在入度为0的顶点
        Pop(S, i);  // 栈顶元素出栈
        print[mycount] = i; // 输出顶点i
        int v;
        for(ArcNode p=G.vertices[i].firstarc;p;p->nextarc){
            // 将所有i指向的顶点的入度减1，并且将入度减为0的顶点压入栈S
            v = p->adjvex;
            if(!(--indegree[v])){
                Push(S,v);  // 入度为0，则入栈
            }
        }
    }
    if(mycount < G.vexnum)
        return false;   // 排序失败，有向图中有回路
    else
        return true;    // 拓扑排序成功
}




