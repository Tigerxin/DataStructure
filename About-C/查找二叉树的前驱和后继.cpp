#include <stdio.h>
#include <stdlib.h>

// 线索二叉树
typedef struct IndexBinTreeNode{
    int data;
    struct IndexBinTreeNode *lchild,*rchild;
    int ltag,rtag;  // 左右线索标点
}IndexBinTreeNode, *IndexBinTree;

// 找到以p为根的子树，第一个被中序遍历的结点
IndexBinTreeNode *Firstnode(IndexBinTreeNode *p);
// 在中序线索二叉树中找到结点p的后继结点
IndexBinTreeNode *Nextnode(IndexBinTreeNode *p);
// 对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(IndexBinTreeNode *T);

// 找到以p为根的子树中，最后一个被中序遍历的结点
IndexBinTreeNode *Lastnode(IndexBinTreeNode *p);
// 在中序线索二叉树中找到结点p的前驱结点
IndexBinTreeNode *Prenode(IndexBinTreeNode *p);
// 对中序线索二叉树进行逆向中序遍历
void RevInorder(IndexBinTreeNode *T);


int main(){
    return 0;
}

// 找到以p为根的子树，第一个被中序遍历的结点
IndexBinTreeNode *Firstnode(IndexBinTreeNode *p){
    // 循环找到最左下结点（不一定是叶结点）
    while(p->ltag == 0)
        p=p->lchild;
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
IndexBinTreeNode *Nextnode(IndexBinTreeNode *p){
    // 右子树最左下结点
    if(p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;   // rtag==1直接返回后继线索
}

// 对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(IndexBinTreeNode *T){
    for(IndexBinTreeNode *p=Firstnode(T); p!=NULL; p=Nextnode(p))
        printf("数据为%d\n", p->data);
}

// 找到以p为根的子树中，最后一个被中序遍历的结点
IndexBinTreeNode *Lastnode(IndexBinTreeNode *p){
    // 循环找到最右下结点（不一定是叶结点）
    while(p->rtag == 0)
        p = p->rchild;
    return p;
}

// 在中序线索二叉树中找到结点p的前驱结点
IndexBinTreeNode *Prenode(IndexBinTreeNode *p){
    // 左子树中最右下结点
    if(p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;   // ltag==1直接返回前驱线索
}

// 对中序线索二叉树进行逆向中序遍历
void RevInorder(IndexBinTreeNode *T){
    for(IndexBinTreeNode *p=Lastnode(T); p!=NULL; p=Prenode(p))
        printf("数据为%d\n", p->data);
}





