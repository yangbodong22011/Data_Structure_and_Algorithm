/*************************************************************************
	> File Name: MergeSort.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Mon 14 Dec 2015 16:12:11 CST
 ************************************************************************/

#include<stdio.h>

void MergeArray(int a[],int first,int mid,int last,int temp[])
{
    int i = first,j = mid+1;
    int m = mid,n = last;
    int k = 0;
    int p;
    while(i <= m && j <= n) {               //从给定区间一半开始比较合并两个区间
        if(a[i] <= a[j]) {                  
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while(i <= m) {
        temp[k++] = a[i++];
    }
    while(j <= n) {
        temp[k++] = a[j++];
    }
    for(i = 0;i < k;i++) {                  //将temp[]的值更新到a[]中,temp数组是临时数组
        a[first+i] = temp[i];
    }
}

void MergeSort(int a[],int first,int last,int temp[])
{
    if(first < last) {                      //将问题分解到最小直到first>=last,即每一个元素本身
        int mid = (first+last)/2;           //就是一个区间
        MergeSort(a,first,mid,temp);        //每次都是先处理左边
        MergeSort(a,mid+1,last,temp);       //再处理右边
        MergeArray(a,first,mid,last,temp);  //在将数组合并
    }
}

int main(int argc,char *argv[])
{
    int i;
    int a[] = {1,8,7,4,3,21,12};
    int temp[20] = {0};
    MergeSort(a,0,6,temp);
    for(i = 0;i < 7;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
