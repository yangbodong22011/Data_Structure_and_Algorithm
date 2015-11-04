/*************************************************************************
	> File Name: fibonacci.c
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Oct 2015 10:02:57 CST
 ************************************************************************/

#include<stdio.h>

int i = 3;

void fibonacci(int,int,int c[]);

void fibonacci(int a,int b,int c[])
{
    int d = a+b;
    c[i++] = d;
    if(i <= 40)
        fibonacci(b,d,c);
}

int main(int argc,char *argv[])
{
    int c[50] = {0};
    int a = 1;
    int b = 1;
    int n;
    scanf("%d",&n);
    c[1] = c[2] = 1;
    fibonacci(a,b,c);
    if(n == 1)
        printf("1\n");
    else
        printf("%d\n",c[n-1]+c[n-2]);

    return 0;
}
