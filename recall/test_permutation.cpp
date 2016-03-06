/*************************************************************************
	> File Name: test_permutation.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 10:28:18 CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char *argv[])
{
    int chs[] = {3,6,4,2};
    int count = sizeof(chs)/sizeof(*chs);
    std::vector<int> vchs(chs,chs+count);

    std::next_permutation(vchs.begin(),vchs.end());
    for(auto u:vchs) cout << u << " ";cout << endl;
    return 0;
}
