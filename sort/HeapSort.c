/*************************************************************************
	> File Name: HeapSort.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Mon 14 Dec 2015 17:13:46 CST
 ************************************************************************/

#include<stdio.h>

void MinHeapFixdown(int a[],int i,int n)
{
    int j,temp;
    temp = a[i];         //根
    j = 2*i+1;           //左孩子
    while(j < n) {
        if(j+1<n && a[j+1]<a[j]) { //从左右孩子中找到最小的
            j++;
        }
        if(a[j] >= temp) {         //左右孩子都比根大直接break
            break;
        }
        a[i] = a[j];               //否则将最小的值给根
        i = j;                     //然后只要目前i还有孩子，就应该再次检测
        j = 2*i+1;                 //找到孩子，下次循环进来还是检测temp的关系。
    }
    a[i] = temp;                   //无论怎样,每次temp即使移动多次,最后还是放到i的位置。
}
void MakeMinHeap(int a[],int n)  //将普通数组堆化的过程
{
    int i;
    for(i = n/2-1;i >= 0;i--) {  //从n/2-1开始保证所有的根都会检测
        MinHeapFixdown(a,i,n);   //从底部开始调整，到顶部时候，底部已经被调整好
    }
}
void HeapSort(int a[],int n)
{
    int i;
    int p;
    for(i = n-1;i >= 0;i--) {
        printf("%d ",a[0]);      //输出目前堆顶的元素也就是数组首元素
        a[0] = a[i];             //每次将最后一个元素置为数组首元素
        MinHeapFixdown(a,0,i);   //每次都从0开始到n调整
    }
    printf("\n");
}


int main(int argc,char *argv[])
{
    int i;
    int a[] = {9,100,17,30,50,20,60,65,4,19};
    MakeMinHeap(a,10);
    HeapSort(a,10);
    return 0;
}
