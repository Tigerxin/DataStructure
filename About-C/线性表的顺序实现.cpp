#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int datatype;
typedef struct{
    datatype a[MAXSIZE];
    int length;
}sequence_list;

// ��ʼ��˳���
void initseqlist(sequence_list *L){
    L->length = 0;
}
// ����˳���
void input(sequence_list *L){
    datatype x;
    initseqlist(L);
    printf("������һ�����ݣ���0��Ϊ��������\n");
    scanf("%d", &x);
    while(x){
        L->a[L->length++] = x;
        scanf("%d", &x);
    }
}
// ���ļ�����˳���
void inputfromfile(sequence_list *L, char *f){
    int i,x;
    FILE *fp = fopen(f, "r");
    L->length = 0;
    if(fp){
        while(!feof(fp)){
            fscanf(fp, "%d", &L->a[L->length++]);
        }
        fclose(fp);
    }
}
// ���˳���
void print(sequence_list *L){
    int i;
    for(i=0; i<L->length; i++){
        printf("%5d", L->a[i]);
        if((i+1)%10 == 0)
            printf("\n");
    }
}
// ˳�����
void reverse_seq(sequence_list *L){
    int length = L->length;
    datatype temp[length];
    for(int i=0; i<L->length; i++){
        temp[i] = L->a[i];
    }
    L->length=0;
    for(int i=length-1; i>=0; i--){
        L->a[L->length++] = temp[i];
    }
    printf("\n");

}
// ��˳���L1���࣬��������L2��ż������L3
void sprit_seq(sequence_list *L1, sequence_list *L2, sequence_list *L3){
    initseqlist(L2);
    initseqlist(L3);
    for(int i=0;i<L1->length;i++){
        if((L1->a[i])%2 == 0){
            L3->a[L3->length++] = L1->a[i];
        }else{
            L2->a[L2->length++] = L1->a[i];
        }
    }
}
// L1,L2�������򣬺ϲ�L1��L2��L3��ʹ������
void merge_seq(sequence_list *L1, sequence_list *L2, sequence_list *L3){
    initseqlist(L3);
    int i=0,j=0;
    while((i<L1->length) && (j<L2->length)){
        if((L1->a[i]) < (L2->a[j])){
            L3->a[L3->length++] = L1->a[i++];
        }else{
            L3->a[L3->length++] = L2->a[j++];
        }
    }
    while(i<L1->length){
        L3->a[L3->length++] = L1->a[i++];
    }
    while(j<L2->length){
        L3->a[L3->length++] = L2->a[j++];
    }
}
// ɸѡ��la��lb����Ľ������lc
void inter_seq(sequence_list *la, sequence_list *lb, sequence_list *lc){
    initseqlist(lc);
    bool isHas;
    for(int i=0;i<la->length;i++){
        isHas = false;
        for(int k=0;i<lc->length;k++){
            if(lc->a[k] == la->a[i]){
                isHas = true;
                break;
            }
        }
        if(!isHas){
            for(int j=0;j<lb->length;j++){
                if(la->a[i]==lb->a[j]){
                    lc->a[lc->length++] = la->a[i];
                    break;
                }
            }
        }
    }
}
// ����˳�������ż��
void partion(sequence_list *L){
    int len = L->length,k=0;
    datatype temp[len];
    for(int i=0; i<L->length; i++){
        if(L->a[i] % 2 == 0){
            temp[--len] = L->a[i];
        }else{
            temp[k++] = L->a[i];
        }
        L->a[i] = 0;
    }
    L->length = 0;
    for(int i=0; i<(sizeof(temp)/sizeof(int)); i++){
        L->a[L->length++] = temp[i];
    }
}
int main(){
    /*��Դ����
    sequence_list myseq, seq2, seq3;
    char *txtpath = "./sequence_data.txt";  // �ⲿ�ļ�·��
    initseqlist(&myseq);  // ��ʼ��˳���
    inputfromfile(&myseq, txtpath);  // ���ļ��ж�ȡ����
    printf("��ʼ���ݣ�");
    print(&myseq);
    */
    /*1.���Ե���
    reverse_seq(myseq);
    print(myseq);
    return 0;
    */
    /*2.������ż����
    sprit_seq(&myseq, &seq2, &seq3);
    printf("\t���ݳ���%d\n�������ݣ�",myseq.length);
    print(&seq2);
    printf("\t���ݳ���%d\nż�����ݣ�",seq2.length);
    print(&seq3);
    printf("\t���ݳ���%d",seq3.length);
    return 0;
    */
    /*3.������������ϲ�
    sequence_list L1, L2, L3;
    input(&L1);
    input(&L2);
    merge_seq(&L1, &L2, &L3);
    printf("��������ݱ���������ģ�");
    printf("L1����:");
    print(&L1);
    printf("\tL1���ݳ���%d\nL2���ݣ�",L1.length);
    print(&L2);
    printf("\tL2���ݳ���%d\nL3���ݣ�",L2.length);
    print(&L3);
    printf("\tL3���ݳ���%d",L3.length);
    */
    /*4.��la��lb��˳���Ľ���
    sequence_list la, lb, lc;
    inputfromfile(&la, "./sequence_data.txt");
    inputfromfile(&lb, "./sequence_data2.txt");
    print(&la);
    printf("\t���ݳ���%d\n",la.length);
    print(&lb);
    printf("\t���ݳ���%d\n",lb.length);
    inter_seq(&la, &lb, &lc);
    print(&lc);
    printf("\t���ݳ���%d\n",lc.length);
    */
    sequence_list L;
    inputfromfile(&L, "sequence_data.txt");
    print(&L);
    printf("\t���ݳ���%d\n",L.length);
    partion(&L);
    print(&L);
    printf("\t���ݳ���%d\n",L.length);
    return 0;
}
