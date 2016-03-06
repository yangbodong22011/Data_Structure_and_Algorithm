/*************************************************************************
	> File Name: myeightqueen.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 26 Feb 2016 17:39:34 CST
 ************************************************************************/

#include<iostream>
#include<cmath>

#define INIT -10000

using std::cout;
using std::cin;
using std::endl;

int array[8] = {INIT,INIT,INIT,INIT,INIT,INIT,INIT,INIT};

int valid(int row,int col) {
    for(int i = 0;i < 8;++i) {
        //判断两个皇后是否在同一列或者同一斜线上，这个方法借鉴大神的！
        if((array[i] == col) || (abs(i-row) == abs(array[i]-col))) {
            return 0;
        }
    }
    return 1;
}
void queen()
{
    int i = 0,j = 0,n = 0;
    while(i < 8) {
        while(j < 8) {
            if(valid(i,j)) {  //如果可以放置
                array[i] = j; //表示将第i行，j列放置皇后
                j = 0;        //放置后对于下一行从头开始
                break;
            } else {
                ++j;
            }
        }
        if(array[i] == INIT) {
            if(i == 0) {         //如果回溯到最初
                break;
            } else {
                --i;              //如果j从1到7都不满足，回溯
                j = array[i] + 1; //给列加一
                array[i] = INIT;  //将array[i]置为未放置
                continue;
            }
        }
        if(i == 7) {
            printf("%d : ",++n);
            for(auto u:array) cout << u << " ";cout << endl;
            j = array[i] + 1;
            array[i] = INIT;
            continue;
        }
        ++i;
    }
}
int main(int argc,char *argv[])
{
    queen();
    return 0;
}
