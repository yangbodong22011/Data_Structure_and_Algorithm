/*************************************************************************
	> File Name: permutation_realization.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 16:05:15 CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char *argv[])
{
    for(std::string str;cin >> str ;) {
        if(str.empty()) {
            continue;
        }
        if(str.length() <= 1) {
            cout << "No " << endl;
        }
        std::string::iterator iPivot = str.end(),iNewHead;
        for(--iPivot;iPivot != str.begin();--iPivot) {
            if(*(iPivot-1) <= *iPivot) {
                break;
            }
        }
        if(iPivot == str.begin()) {
            cout << "No" << endl;
        }
        iPivot--;
        for(iNewHead = iPivot+1;iNewHead != str.end();++iNewHead) {
            if(*iNewHead < *iPivot) {
                break;
            }
        }
        std::iter_swap(iPivot,--iNewHead);
        std::reverse(iPivot+1,str.end());
        cout << str << endl;
    }
    return 0;
}
