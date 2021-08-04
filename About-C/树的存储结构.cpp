#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100   // 树中最多结点数

// 双亲表示法:每个结点中保存指向双亲的“指针”
typedef struct{
    int data;
    int parent; // 双亲位置域
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];    // 双亲表示
    int n;  // 结点个数
}PTree;

// 孩子表示法（顺序+链式存储）
struct CTNode{
    int child;  // 孩子结点在数组中的位置
    struct CTNode *next;    // 下一个孩子
};
typedef struct{
    int data;
    struct CTNode *firstChild;  // 第一个孩子
}CTBox;

typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;   //结点数和根的位置
}CTree;

/*
    问题：树和二叉树的转化
    优点：可以用熟悉的二叉树操作来处理树
*/
// 孩子兄弟表示法
typedef struct CSNode{
    int data;   // 数据域
    struct CSNode *firstchild,*nextsibling; // 第一个孩子和右兄弟指针
}CSNode, *CSTree;

// 树的先根遍历
void PreOrder(CSNode *R);
// 树的后根遍历
void PostOrder(CSNode *R);


int main(){
    return 0;
}

// 树的先根遍历
void PreOrder(CSNode *R){
    if(R != NULL){
        printf("数据为%d\n",R->data);
        while(R->nextsibling != NULL){
            PreOrder(R->nextsibling);   // 先根遍历下一颗子树
        }
    }
}

// 树的后根遍历
void PostOrder(CSNode *R){
    if(R != NULL){
        while(R->nextsibling != NULL)
            PostOrder(R->nextsibling);  // 后根遍历下一颗子树
        printf("子孩子%d\n",R->firstchild->data);
    }
}
