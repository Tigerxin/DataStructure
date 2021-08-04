#include <stdio.h>
#include <stdlib.h>

/* 平衡二叉树
    结点的平衡因子=左子树高-右子树高
    查找效率分析
        若树高为h，则最坏情况下，查找一个关键字最多需要对比h次，
    即查找操作的时间复杂度不可能超过O(h)
    平衡二叉树——树上的任一结点的左子树和右子树的高度之差不超过1。
        假设以Nh表示深度为h的平衡二叉树中含有的最小结点数，
    则有N0=0，N1=1，N2=2，并且有Nh=N(h-1) + N(h-2) + 1
*/
typedef struct AVLNode{
    int key;    // 数据域
    int balance;    // 平衡因子
    struct AVLNode *lchild,*rchild;
}AVLNode,*AVLTree;

int main(){
    /*
        1.LL型：在A的左孩子的左子树插入导致A不平衡，将A的左孩子右上旋
        2.RR型：在A的右孩子的右子树插入导致A不平衡，将A的右孩子左上旋
        3.LR型：在A的左孩子的右孩子插入导致A不平衡，将A的左孩子的右孩子 先左上旋再右上旋
        4.RL型：在A的右孩子的左孩子插入导致A不平衡，将A的右孩子的左孩子 先右上旋再左上旋
    */
}
