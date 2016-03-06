/*************************************************************************
	> File Name: test.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 14:50:28 CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,char *argv[])
{
    printf("%d\n",1&0);
    printf("%d\n",1|0);
    printf("%d\n",!0);
    printf("%d\n",0x1);
    return 0;
}
