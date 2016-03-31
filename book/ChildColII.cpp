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

int size;
int a[100];
int dp[100];
int len = 0;
int flag = 0;

int main(int argc,char *argv[])
{
    cin >> size;
    for(int i = 0;i < size;i++) {
        cin >> a[i];
    }
    dp[0] = a[0];
    len++;
    for(int i = 0;i < size;i++) {
        flag = 0;
        for(int j = 0;j < len;j++) {
            if(a[i] <= dp[j]) {
                dp[j] = a[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            dp[len] = a[i];
            len++;
        }
    }
    cout << len << endl;
    return 0;
}
