#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������
// �������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

// Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;

typedef struct{
    int id;
    char *name;
    int age;
} Person;

typedef struct{
    Person *per;
    int length;
} PersonList;

int main(){
    return 0;
}
