/*************************************************************************
	> File Name: binSearch.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Wed 02 Mar 2016 20:52:45 CST
 ************************************************************************/

#include<stdio.h>

int i = 0;

void binarySearch(int a[],int length,int find)
{
    int begin = 0;
    int end = length;
    while(begin <= end) {
        ++i;
        int middle = (begin+end+1)/2;
        if(find > a[middle]) {
            begin = middle+1;
        } else if (find == a[middle]) {
            printf("find:%d\n",i);
            return;
        } else {
            end = middle-1;
        }
    }
    /*while(begin < end) {
        int middle = (begin+end)/2;
        ++i;
        if(a[middle] == find) {
            printf("find:%d\n",i);
            return;
        } else {
            if(a[middle] > find) {
               binarySearch(a,begin,middle-1,find); 
            } 
            if(a[middle] < find) {
                binarySearch(a,middle+1,end,find);
            }
        }
    }*/
}

int main(int argc,char *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(a)/sizeof(*a)-1;
    //printf("%d\n",length);
    binarySearch(a,length,7);
    return 0;
}

