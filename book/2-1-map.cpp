/*************************************************************************
	> File Name: 2-1-map.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Mon 21 Mar 2016 07:42:49 AM CST
 ************************************************************************/

#include<iostream>
#include<map>

using std::cin;
using std::cout;
using std::endl;

int main(int argc,char *argv[])
{
    std::map<int,int> map;
    int i;
    int maxIndex = 1;
    while(cin >> i) {
        ++map[i];
    }
    for(auto u:map) {
        if(u.second > maxIndex) {
            maxIndex = u.first;
        }
    } 
    cout << maxIndex << " " << map[maxIndex] << " "<< endl;
    return 0;
}
