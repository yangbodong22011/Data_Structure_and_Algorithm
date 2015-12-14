/*************************************************************************
	> File Name: Quick.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 13 Dec 2015 18:27:04 CST
 ************************************************************************/

#include<stdio.h>

void QuickSort(int s[],int l,int r)
{
    if(l < r) { 
        int i = l,j = r,x = s[i];
        while(i < j) {
            while(i < j && s[j] >= x) {   //从后向前找最大
                j--;
            }
            if(i < j) {                   //找到符合条件的值
                s[i++] = s[j];
            }
            while(i < j && s[i] < x) {    //从前向后找最小
                i++;
            }
            if(i < j) {                   //找到符合条件的值
                s[j--] = s[i];
            }
        }
        s[i] = x;                         //将中枢元放到i的位置
        QuickSort(s,l,i-1);               //再将左边排序
        QuickSort(s,i+1,r);               //再将右边排序
    }
}


int main(int argc,char *argv[])
{
    int i;
    int a[] = {6,8,9,4,5};
    QuickSort(a,0,4);
    for(i = 0;i < 5;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
