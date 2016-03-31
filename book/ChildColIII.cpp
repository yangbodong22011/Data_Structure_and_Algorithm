/*************************************************************************
	> File Name: ChildColII.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Wed 30 Mar 2016 08:41:43 AM CST
 ************************************************************************/

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int size;      //a数组长度
int a[100];
int dp[100];
int len = 0;
int max = 0;   //dp数组长度,也就是最大字串的长度。

void findFirstBig(int begin,int end,int find)  //二分查找dp数组中第一个比find大的元素
{
    while(begin <= end) {
        int mid = (begin+end)/2;
        if(dp[mid] == find) {
            return;
        }
        if(dp[mid] < find) begin = mid+1;
        if(dp[mid] > find) end = mid-1;
    }
    len = begin;
}

int main(int argc,char *argv[])
{
    cin >> size;
    for(int i = 0;i < size;i++) {
        cin >> a[i];
    }
    dp[0] = a[0];
    for(int i = 0;i < size;i++) {
        if(a[i] > dp[max]) {   //如果下一个元素比dp数组中最大的还大
            max++;
            dp[max] = a[i];
        }
        else { 
            findFirstBig(0,max,a[i]);
            dp[len] = a[i];
        }
    }
    cout << max+1 << endl;
    return 0;
}
