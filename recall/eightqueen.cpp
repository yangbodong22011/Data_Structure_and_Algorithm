/*************************************************************************
	> File Name: eightqueen.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 09:55:08 CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<bitset>
#include<numeric>
#include<utility>
int main() {
    int i = 0;
    for (int queens[] = {0,1,2,3,4,5,6,7}; std::next_permutation(queens,queens+8);) {
    if ((std::bitset<15>(std::accumulate(queens,queens+8, std::make_pair(0, 0), [](std::pair<int, int> a, int b){return std::make_pair((1<<(b+a.second))|a.first,a.second+1);}).first).count() == 8) && (std::bitset<15>(std::accumulate(queens, queens+8, std::make_pair(0, 0), [](std::pair<int, int> a, int b){return std::make_pair((1<<(7+b-a.second))|a.first, a.second+1);}).first).count() == 8))
    std::cout << ++i << " : " << queens[0] << queens[1] << queens[2] << queens[3] << queens[4] << queens[5] << queens[6] << queens[7] << std::endl; }
    return 0;
}
