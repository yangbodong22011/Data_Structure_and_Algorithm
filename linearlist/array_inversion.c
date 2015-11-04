/*************************************************************************
	> File Name: array_version.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Oct 2015 09:38:52 CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

void change(int *a,int length)
{
    int times,i,t;
    times = length/2;
    for(i = 1;i <= times;i++)
    {
        t           = a[i-1];
        a[i-1]      = a[length-i];
        a[length-i] = t;
    }
}

int main(int argc,char *argv[])
{
    int i;
    int a[100];
    for(i = 0;i < 100;i++)
        a[i] = i;
    change(a,sizeof(a)/sizeof(int));
    
    for(i = 0;i < 100;i++)
        printf("%d ",a[i]);
    printf("\n");
}
