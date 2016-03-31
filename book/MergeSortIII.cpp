/*************************************************************************
	> File Name: MergeSortIII.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 20 Mar 2016 02:55:43 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<unistd.h>
#include"my_time.h"

#define max 200000
using std::cin;
using std::cout;
using std::endl;

int c[max] = {0};
int temp[max];

void merge(std::pair<int,int> &a,std::pair<int,int> &b) 
{
    int i = 0;
    for(int sa = a.first,sb = b.first;sa <= a.second || sb <= b.second; ) {
        if(sa <= a.second && sb <= b.second) {
            if(c[sa] <= c[sb]) {
                temp[i++] = c[sa++];
            }else {
                temp[i++] = c[sb++];
            }
        }else if(sa <= a.second) {
            temp[i++] = c[sa++];
        }else {
            temp[i++] = c[sb++];
        }
    }
    for(int j = 0;j < i;++j) {
        c[j+a.first] = temp[j];
    }
}

void MergeSortIII(int begin,int end,std::vector<std::pair<int,int>> &v)
{
    while(1) {
        int length = begin;
        for(int i = begin+1;i <= end;++i) {
            if(c[i] < c[i-1]) {
                v.push_back(std::pair<int,int>(length,i-1));
                length = i;
            }
        }
        if(length == begin) {
            break;
        }
        v.push_back(std::pair<int,int>(length,end));
        for(int i = 1;i < v.size();i+=2) {
            merge(v[i-1],v[i]);
        }
    }
}
int main(int argc,char *argv[])
{
    struct timeval tbegin,tend;
    int timeuse;
    srand((unsigned)time(NULL));
    for(int i = 0;i < max;++i) {
        c[i] = rand()%300000;
    }
    tbegin = printtime();
    std::vector<std::pair<int,int>> v;
    MergeSortIII(0,max-1,v);
    tend = printtime();
    timeuse = 1000000*(tend.tv_sec-tbegin.tv_sec) + tend.tv_usec-tbegin.tv_usec;
    cout << "UseTime: " << timeuse << endl;
    return 0;
}
