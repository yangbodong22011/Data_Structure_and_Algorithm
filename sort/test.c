/*************************************************************************
	> File Name: test.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Mon 14 Dec 2015 16:28:37 CST
 ************************************************************************/

#include<stdio.h>
void change2(int a[])
{
    int i;
    a[3]++;
    for(i = 0;i < 5;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void change1(int a[])
{
    int i;
    a[3]++;
    for(i = 0;i < 5;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    change2(a);
    
}

int main(int argc,char *argv[])
{
    int i;
    int a[] = {1,2,3,4,5};
    change1(a);
    a[3]++;
    for(i = 0;i < 5;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
