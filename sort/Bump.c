/*************************************************************************
	> File Name: Insert.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 13 Dec 2015 09:40:59 CST
 ************************************************************************/

#include<stdio.h>

void Bump(int a[],int n)
{
    int i;
    int bump[100] = {0};             //初始化桶的值全为0
    for(i = 0;i < n;i++) {           //让数组中的元素依次找到对应的桶,并将桶的值+1
        bump[a[i]]++;
    }
    for(i = 0;i < 100;i++) {
        if(bump[i] >= 1) {           //只要桶里面的值不为0,就表示次桶对应有值,值就是桶的序号
            printf("%d ",i);         //这种输出剔除了重复，若不剔除重复，就循环输出
        }
        /*for(j = bump[i];j >= 1;j--) {//这是不剔除重复输出
            printf("%d ",i);         
        }*/
    }
    printf("\n");
}

int main(int argc,char *argv[])
{
    int i;
    int a[6] = {34,8,64,51,32,21};
    Bump(a,6);

    for(i = 0;i < 6;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
