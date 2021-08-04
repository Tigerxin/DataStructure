#include <stdio.h>
#include <stdlib.h>

// 二叉排序树的结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BSTree;

/* 在二叉排序树中查找值为key的结点
    左子树结点值<根结点值<右子树结点值
*/
BSTNode *BST_Search(BSTNode T,int key);
// 在二叉排序中查找值为key的结点（递归实现）
BSTNode *BSTSearch(BSTree T, int key);
// 在二叉排序树中插入新结点,递归实现,最坏空间复杂度O(h)
int BST_Insert(BSTree &T,int k);
// 按照数组arr[]中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T, int arr[], int n);


int main(){
    /*  查找效率分析
        查找长度--在查找运算中，需要对比关键字的次数称为查找长度，反映了查找操作时间复杂度
        查找成功的平均查找长度ASL:
        ASL=(1*1 + 2*2 + 3*4 + (...)*(当前层具有的结点个数))/成功的总结点个数
        查找失败的平均查找长度ASL:
        ASL=((叶子结点所在的高度)*(其下层没有子结点的数量)+...)/(没有查找到的叶子结点总数)
    */

}

// 在二叉排序树中查找值为key的结点,最坏空间复杂度为O(1)
BSTNode *BST_Search(BSTNode T,int key){
    while(T!=NULL && key!=T->key){  // 若树空或等于根节点值，则结束循环
        if(key < T->key)
            T = T->lchild;    // 小于查询左子树
        else
            T = T->rchild;
    }
    return T;
}
// 在二叉排序中查找值为key的结点（递归实现）复杂度O(h),h为树的高度
BSTNode *BSTSearch(BSTree T, int key){
    if(T == NULL)
        return NULL;
    if(key == T->key)
        return T;
    else if(key < T->key)
        return BSTSearch(T->lchild, key);   // 在左子树查找
    else
        return BSTSearch(T->rchild, key);   // 在右子树中找
}

// 在二叉排序树中插入新结点,递归实现
int BST_Insert(BSTree &T,int k){
    if(T == NULL){  // 原树为空，新插入的结点为根结点
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }else if(k == T->key){  // 树中存在相同关键字的结点，插入失败
        return 0;
    }else if(k < T->key){
        return BST_Insert(T->lchild, k);
    }else{
        return BST_Insert(T->rchild, k);
    }
}

// 按照数组arr[]中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T, int arr[], int n){
    T = NULL;   // 初始时T为空树
    int i = 0;
    while(i < n){   // 依次将每个数据插入二叉排序树中
        BST_Insert(T, arr[i]);
        i++;
    }
}


