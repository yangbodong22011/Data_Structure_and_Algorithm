/*************************************************************************
	> File Name: test2.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 14:40:25 CST
 ************************************************************************/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char *argv[])
{
    cout << (1&0) << endl;
    cout << (1|0) << endl;
    cout << (!0) << endl;
    printf("%d\n",0xffffffff);
    return 0;
}
