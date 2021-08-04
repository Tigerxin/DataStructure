#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100    // 顶点树目的最大值

/*
    邻接矩阵存储稠密图
    邻接表存储稀疏图
*/

// 邻接矩阵法存储
typedef struct{
    char Vex[MaxVertexNum]; // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum];   // 邻接矩阵，边表
    int vexnum,arcnum;  // 图的当前顶点数和边数/弧数
}MGraph;

// 边/弧
typedef struct ArcNode{
    int adjvex; // 边弧指向哪个结点
    struct ArcNode *next;   // 指向下一条弧的指针
    // InfoType info;   // 边权值
}ArcNode;

// 邻接表存储
typedef struct VNode{
    int data;    // 顶点信息
    ArcNode *first; // 第一条边/弧
}VNode,AdjList[MaxVertexNum];

int main(){
    return 0;
}
