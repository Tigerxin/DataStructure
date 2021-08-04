#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int datatype;
typedef struct{
    datatype a[MAXSIZE];
    int length;
}sequence_list;

// 初始化顺序表
void initseqlist(sequence_list *L){
    L->length = 0;
}
// 输入顺序表
void input(sequence_list *L){
    datatype x;
    initseqlist(L);
    printf("请输入一组数据，以0做为结束符：\n");
    scanf("%d", &x);
    while(x){
        L->a[L->length++] = x;
        scanf("%d", &x);
    }
}
// 从文件输入顺序表
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
// 输出顺序表
void print(sequence_list *L){
    int i;
    for(i=0; i<L->length; i++){
        printf("%5d", L->a[i]);
        if((i+1)%10 == 0)
            printf("\n");
    }
}
// 顺序表倒置
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
// 对顺序表L1分类，奇数放在L2，偶数放在L3
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
// L1,L2数据升序，合并L1，L2到L3并使其有序
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
// 筛选出la，lb俩表的交集存进lc
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
// 调整顺序表，奇左偶右
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
    /*读源数据
    sequence_list myseq, seq2, seq3;
    char *txtpath = "./sequence_data.txt";  // 外部文件路径
    initseqlist(&myseq);  // 初始化顺序表
    inputfromfile(&myseq, txtpath);  // 从文件中读取数据
    printf("初始数据：");
    print(&myseq);
    */
    /*1.测试倒置
    reverse_seq(myseq);
    print(myseq);
    return 0;
    */
    /*2.测试奇偶分类
    sprit_seq(&myseq, &seq2, &seq3);
    printf("\t数据长度%d\n奇数数据：",myseq.length);
    print(&seq2);
    printf("\t数据长度%d\n偶数数据：",seq2.length);
    print(&seq3);
    printf("\t数据长度%d",seq3.length);
    return 0;
    */
    /*3.测试有序数组合并
    sequence_list L1, L2, L3;
    input(&L1);
    input(&L2);
    merge_seq(&L1, &L2, &L3);
    printf("输入的数据必须是有序的！");
    printf("L1数据:");
    print(&L1);
    printf("\tL1数据长度%d\nL2数据：",L1.length);
    print(&L2);
    printf("\tL2数据长度%d\nL3数据：",L2.length);
    print(&L3);
    printf("\tL3数据长度%d",L3.length);
    */
    /*4.求la，lb俩顺序表的交集
    sequence_list la, lb, lc;
    inputfromfile(&la, "./sequence_data.txt");
    inputfromfile(&lb, "./sequence_data2.txt");
    print(&la);
    printf("\t数据长度%d\n",la.length);
    print(&lb);
    printf("\t数据长度%d\n",lb.length);
    inter_seq(&la, &lb, &lc);
    print(&lc);
    printf("\t数据长度%d\n",lc.length);
    */
    sequence_list L;
    inputfromfile(&L, "sequence_data.txt");
    print(&L);
    printf("\t数据长度%d\n",L.length);
    partion(&L);
    print(&L);
    printf("\t数据长度%d\n",L.length);
    return 0;
}
