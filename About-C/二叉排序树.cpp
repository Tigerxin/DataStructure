#include <stdio.h>
#include <stdlib.h>

// �����������Ľ��
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BSTree;

/* �ڶ����������в���ֵΪkey�Ľ��
    ���������ֵ<�����ֵ<���������ֵ
*/
BSTNode *BST_Search(BSTNode T,int key);
// �ڶ��������в���ֵΪkey�Ľ�㣨�ݹ�ʵ�֣�
BSTNode *BSTSearch(BSTree T, int key);
// �ڶ����������в����½��,�ݹ�ʵ��,��ռ临�Ӷ�O(h)
int BST_Insert(BSTree &T,int k);
// ��������arr[]�еĹؼ������н�������������
void Creat_BST(BSTree &T, int arr[], int n);


int main(){
    /*  ����Ч�ʷ���
        ���ҳ���--�ڲ��������У���Ҫ�Աȹؼ��ֵĴ�����Ϊ���ҳ��ȣ���ӳ�˲��Ҳ���ʱ�临�Ӷ�
        ���ҳɹ���ƽ�����ҳ���ASL:
        ASL=(1*1 + 2*2 + 3*4 + (...)*(��ǰ����еĽ�����))/�ɹ����ܽ�����
        ����ʧ�ܵ�ƽ�����ҳ���ASL:
        ASL=((Ҷ�ӽ�����ڵĸ߶�)*(���²�û���ӽ�������)+...)/(û�в��ҵ���Ҷ�ӽ������)
    */

}

// �ڶ����������в���ֵΪkey�Ľ��,��ռ临�Ӷ�ΪO(1)
BSTNode *BST_Search(BSTNode T,int key){
    while(T!=NULL && key!=T->key){  // �����ջ���ڸ��ڵ�ֵ�������ѭ��
        if(key < T->key)
            T = T->lchild;    // С�ڲ�ѯ������
        else
            T = T->rchild;
    }
    return T;
}
// �ڶ��������в���ֵΪkey�Ľ�㣨�ݹ�ʵ�֣����Ӷ�O(h),hΪ���ĸ߶�
BSTNode *BSTSearch(BSTree T, int key){
    if(T == NULL)
        return NULL;
    if(key == T->key)
        return T;
    else if(key < T->key)
        return BSTSearch(T->lchild, key);   // ������������
    else
        return BSTSearch(T->rchild, key);   // ������������
}

// �ڶ����������в����½��,�ݹ�ʵ��
int BST_Insert(BSTree &T,int k){
    if(T == NULL){  // ԭ��Ϊ�գ��²���Ľ��Ϊ�����
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }else if(k == T->key){  // ���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
        return 0;
    }else if(k < T->key){
        return BST_Insert(T->lchild, k);
    }else{
        return BST_Insert(T->rchild, k);
    }
}

// ��������arr[]�еĹؼ������н�������������
void Creat_BST(BSTree &T, int arr[], int n){
    T = NULL;   // ��ʼʱTΪ����
    int i = 0;
    while(i < n){   // ���ν�ÿ�����ݲ��������������
        BST_Insert(T, arr[i]);
        i++;
    }
}


