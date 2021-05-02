#include <stdio.h>
#include <stdlib.h>

// 數呾論傚
int factorial(int num);

int main(){
    int num = 4;
    int result = factorial(num);
    printf("%d腔論傚峈:%d\n",num,result);
    system("pause");
    return 0;
}

// 數呾論傚
int factorial(int num){
    if(num==1 || num==0)
        return 1;
    else
        return num*factorial(num-1);
}

