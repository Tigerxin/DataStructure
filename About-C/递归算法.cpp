#include <stdio.h>
#include <stdlib.h>

// ����׳�
int factorial(int num);

int main(){
    int num = 4;
    int result = factorial(num);
    printf("%d�Ľ׳�Ϊ:%d\n",num,result);
    system("pause");
    return 0;
}

// ����׳�
int factorial(int num){
    if(num==1 || num==0)
        return 1;
    else
        return num*factorial(num-1);
}

