/*************************************************************************
	> File Name: factorial.c
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Oct 2015 10:13:20 CST
 ************************************************************************/

#include<stdio.h>

int factorial(int);

int factorial(int num)
{
    if(num == 1)
        return 1;
    else
        return num*factorial(num-1);
}

int main(int argc,char *argv[])
{
    int num,ret;
    printf("请输入一个数:");
    scanf("%d",&num);
    ret = factorial(num);
    printf("%d\n",ret);
}
