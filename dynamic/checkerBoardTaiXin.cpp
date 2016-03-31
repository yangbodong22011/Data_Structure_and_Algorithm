/*************************************************************************
	> File Name: checkerBoardTaiXin.cpp
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 27 Mar 2016 11:54:21 AM CST
 ************************************************************************/

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define size 4

int map[size][size] = {0};

bool ISFinsh(int row,int col)
{
    if(row == size-1 && col == size-1) {
        return 0;
    }
    return 1;
}

void TanXin()
{
    int row = 0,col = 0;
    cout << "(" << row << "," << col << ")" << endl;
    while( ISFinsh(row,col)  && (row < size && col < size)) {
        if((row+1 < size && col+1 < size) && (map[row][col+1] > map[row+1][col])) {
            col++;
            cout << "(" << row << "," << col << ")" << endl;
            continue; 
        }
        if((row+1 < size && col+1 < size) && (map[row][col+1] <= map[row+1][col])) {
            row++;
            cout << "(" << row << "," << col << ")" << endl;
            continue;
        }
        if(row+1 < size && col+1 == size) {
            row++;
            cout << "(" << row << "," << col << ")" << endl;
            continue;
        }
        if(row+1 == size && col+1 < size) {
            col++;
            cout << "(" << row << "," << col << ")" << endl;
            continue;
        }
    }
}


int main(int argc,char *argv[])
{
    for(int i = 0;i < size;++i) {
        for(int j = 0;j < size;++j) {
            cin >> map[i][j];
        }
    }
    
    TanXin();
    return 0;
}
