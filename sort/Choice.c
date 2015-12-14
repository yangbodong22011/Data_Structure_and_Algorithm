/*************************************************************************
	> File Name: Insert.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 13 Dec 2015 09:40:59 CST
 ************************************************************************/

#include<stdio.h>

void Choice(int a[],int n)
{
    int i,j;
    for(i = 0;i < n;i++) {          //外层循环轮询每一个位置
        for(j = i+1;j < n;j++) {    //通过与后面的比较找出最大或者最小放到此位置.
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}



int main(int argc,char *argv[])
{
    int a[] = {34,8,64,51,32,21};
    Choice(a,6);
    return 0;

}
