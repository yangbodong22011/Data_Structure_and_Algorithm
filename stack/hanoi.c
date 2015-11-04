/*************************************************************************
	> File Name: hanoi.c
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Oct 2015 10:50:55 CST
 ************************************************************************/
//什么叫做递归的思想,就是你首先得发现一个问题可以分解为好多相似的小问题去解决,然后找出最小的问题,模拟这个步骤,宏观把握,要干什么,想要把什么干了,就这样一步步总结出来.
#include<stdio.h>

int times = 1;

void move(char x,int floor,char z)
{
    times++;
    printf("将第%d层从 %c 移动到 %c\n",floor,x,z);
}

void hanoi(int floor,char x,char y,char z)      //将x上以y为辅助塔移动到z上.
{
    if(floor == 1)
    {
        move(x,1,z);
    }
    else
    {
        hanoi(floor-1,x,z,y);                   //将x上以z为辅助塔移动到y上
        move(x,floor,z);
        hanoi(floor-1,y,x,z);                   //将y上以x为辅助塔移动到z上 这三步基本上是从宏观上把握,实际上移动的只有move函数
    }
}


int main(int argc,char *argv[])
{
    int  floor;
    printf("请输入塔的层数:");
    scanf("%d",&floor);
    hanoi(floor,'x','y','z');
    printf("总的移动次数:%d\n",times);
}
