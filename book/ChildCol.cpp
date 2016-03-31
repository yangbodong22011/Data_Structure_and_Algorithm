/*************************************************************************
	> File Name: ChildCol.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Wed 30 Mar 2016 12:16:52 AM CST
 ************************************************************************/

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

//#define size 5

//int a[size] = {9,3,6,2,7};
//int dp[size] = {1,1,1,1,1};

int size;
int a[5001];  //原数组
int dp[5001]; //序列长度数组


int main(int argc,char *argv[])
{
    cin >> size;
    for(int i = 0;i < size;i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for(int i = 0;i < size;i++) {
        for(int j = 0;j < i+1;j++) {
            if((a[i] > a[j]) && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
    }
    int max = 1;
    for(int i = 0;i < size;i++) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << endl;
    return 0;
}
