/*************************************************************************
	> File Name: Insert.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 13 Dec 2015 09:40:59 CST
 ************************************************************************/

#include<stdio.h>

void Insert(int a[],int n)           //a是待排序数组,n是数组大小
{
    int i,j;
    int tmp;
    for(i = 0;i < n;i++) {           //循环处理每一个元素
        tmp = a[i];                  //先将a[i]保存
        for(j = i;j>0 && a[j-1]>tmp; j--) {  //为a[i]在0-i的区间找合适的位置
            a[j] = a[j-1];                   
        }
        a[j] = tmp;                          //将a[i]放到合适的位置上
    }
}



int main(int argc,char *argv[])
{
    int a[] = {34,8,64,51,32,21};
    Insert(a,6);
    return 0;
}
