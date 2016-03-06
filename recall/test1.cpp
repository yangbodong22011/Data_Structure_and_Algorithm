/*************************************************************************
	> File Name: test1.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 13:13:39 CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
 
int multiply(int x, int y)
{
    return x*y;
}
 
std::string magic_function(std::string res, int x)
{
    return res += (x > 5) ? "b" : "s";
}
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int sum = std::accumulate(v.begin(), v.end(), 0);
    int product = std::accumulate(v.begin(), v.end(), 0, multiply);
    std::string magic = std::accumulate(v.begin(), v.end(), std::string(), 
                                        magic_function);
 
    std::cout << sum << '\n'
              << product << '\n'
              << magic << '\n';
}
