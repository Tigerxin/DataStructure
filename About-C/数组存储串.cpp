#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLen 255  // Ԥ������󴮳�Ϊ255

// ˳��洢��̬���巽ʽ
typedef struct{
    char arr[MaxLen];   // ÿ�������洢һ���ַ���
    int length;
}MySString;

// ˳��洢��̬���巽ʽ
typedef struct{
    char *arr;  // ����������洢����arrָ�򴮵Ļ���ַ
    int length;
}MyDString;

// ��ʽ�洢���洢�ܶȵͣ�
typedef struct LMyStringNode{
    char ch;    // ÿ�����洢1���ַ�
    struct LMyStringNode *next;
}LMyStringNode,*LMyString;

// ��ʽ�洢���洢�ܶȸߣ�
typedef struct MLMyStringNode{
    char ch[4]; // ÿ���������ַ�
    struct MLMyStringNode *next;
}MLMyStringNode, *MLMyString;

void applySpaceForD(MyDString mds);
// ���Ӵ�
bool SubString(MySString &str, MySString S, int pos, int len);
// ���ıȽϲ���
int StrCompare(MySString S, MySString T);
// ���Ķ�λ����
int Index(MySString S, MySString T);
// ��ȡ���ĳ���
int GetStrLength(MySString str);
// ����ģʽƥ�䴮
int SimpleMatch(MySString S, MySString T);
// KMP�㷨����
int KMPMatch(MySString S, MySString T);
// ��ģʽ��T��next����
void Get_Next(MySString T, int next[]);

int main(){
    MySString S = {"woaini",0};
    char arr[255] = "woaini";
    printf("�ַ����ĳ���Ϊ:%s\n",arr);
    int len = GetStrLength(S);
    printf("�ַ����ĳ���Ϊ:%d\n",len);
    return 0;
}

void applySpaceForD(MyDString mds){
    mds.arr = (char *)malloc(MaxLen*sizeof(char));
    mds.length = 0;
}

// ��ȡ���ĳ���
int GetStrLength(MySString str){
    int len = sizeof(str.arr)/sizeof(char);
    int length;
    for(int i=0;i<len;i++){
        if(str.arr[i] == '\0'){
            str.length = length;
            return str.length;
        }
        length++;
    }
    return str.length;
}

// ���Ӵ�
bool SubString(MySString &str, MySString S, int pos, int len){
    // �Ӵ���ΧԽ��
    if(pos+len-1 > S.length)
        return false;
    for(int i=pos;i<pos+len;i++){
        str.arr[i-pos+1] = S.arr[i];
    }
    str.length = len;
    return true;
}

// ���ıȽϲ���
int StrCompare(MySString S, MySString T){
    for(int i=1;i<=S.length && i<=T.length;i++){
        if(S.arr[i]!=T.arr[i])
            return S.arr[i]-T.arr[i];
    }
    // ɨ��������ַ�����ͬ���򳤶ȳ��Ĵ�����
    return S.length-T.length;
}

// ���Ķ�λ����
int Index(MySString S, MySString T){
    int i=1, n=GetStrLength(S), m=GetStrLength(T);
    MySString sub;
    while(i <= n-m+1){
        SubString(sub, S, i, m);
        if(StrCompare(sub, T) != 0)
            ++i;
        else
            return i;   // �����Ӵ��������е�λ��
    }
    return 0;   // S�в�������T��ȵ��Ӵ�
}

// ����ģʽƥ�䴮
int SimpleMatch(MySString S, MySString T){
    int k=1;
    int i=k, j=1;
    while(i<=S.length && j<=T.length){
        if(S.arr[i] == T.arr[j]){
            ++i;
            ++j;    // �����ȽϺ���ַ�
        }else{
            k++;    // �����һ���Ӵ�
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
}

// KMP�㷨����
int KMPMatch(MySString S, MySString T){
    int i=1,j=1;
    int next[T.length+1];
    Get_Next(S,next);   // ��ģʽ����next����
    while(i<=S.length && j<=T.length){
        if(j==0 || S.arr[i]==T.arr[j]){
            ++i;
            ++j;    // �����ȽϺ���ַ�
        }else{
            j = next[j];    // ģʽ�������ƶ�
        }
    }
    if(j>T.length)
        return i-T.length;  // ƥ��ɹ�
    else
        return 0;
}

// ��ģʽ��T��next����
void Get_Next(MySString T, int next[]){
    int i=1, j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0 || T.arr[i]==T.arr[j]){
            ++i;
            ++j;
            // ��pi=pj����next[j+1]=next[j]+1
            next[i]=j;
        }else{
            // ������j=next[j],ѭ������
            j=next[j];
        }
    }
    // nextval�������
    /*
    int nextval[(sizeof(next)/sizeof(int))];
    for(int k=2;k<T.length;k++){
        if(T.arr[next[k] == T.arr[k])
            nextval[k] = nextval[next[j]];
        else
            nextval[k] = next[k];
    }
    */
}



