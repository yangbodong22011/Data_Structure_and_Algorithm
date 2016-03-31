/*************************************************************************
	> File Name: median.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 20 Mar 2016 06:40:02 PM CST
 ************************************************************************/

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int middle = 0;

void median(int a[],int a_begin,int a_end,int b[],int b_begin,int b_end)
{
    int a_mid = (a_begin+a_end)/2;
    int b_mid = (b_begin+b_end)/2;
    if(a_begin == a_mid) {
        int a_max = a[a_mid] > b[b_mid] ? a[a_mid]:b[b_mid];
        int b_min = a[a_end] < b[b_end] ? a[a_end]:b[b_end];
        middle = (a_max+b_min)/2;
        return;
    }
    if(a[a_mid] == b[b_mid]) {
        middle = a[a_mid];
        return;
    }
    else if(a[a_mid] < b[b_mid]) {
        median(a,a_mid,a_end,b,b_begin,b_mid);
    }
    else if(a[a_mid] > b[b_mid]) {
        median(a,a_begin,a_mid,b,b_mid,b_end);
    }
}

int main(int argc,char *argv[])
{
    int a[] = {1,2,3,4,5};
    int a_end = sizeof(a)/sizeof(*a)-1;
    int b[] = {1,2,4,5,6};
    int b_end = sizeof(b)/sizeof(*b)-1;
    median(a,0,a_end,b,0,b_end);
    cout << "middle is : " << middle << endl;
    
    return 0;
}
