/*************************************************************************
	> File Name: 2-1.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 20 Mar 2016 10:15:26 AM CST
 ************************************************************************/

#include<iostream>
#include<array>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;

int main(int argc,char *argv[])
{
    std::array<int,1000> a = {0};
    int i;
    int max = 0;
    int index = 0;
    while(cin >> i) {
        a[i]++;
    }
    for(int i = 0;i < a.size();++i) {
        if(a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    cout << index << endl;
    cout << a[index] << endl;
    return 0;
}
