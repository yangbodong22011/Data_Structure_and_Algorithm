/*************************************************************************
	> File Name: TestGetTimeOfDay.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 20 Mar 2016 10:42:52 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>


int main(int argc,char *argv[])
{
    struct timeval start,end;
    gettimeofday(&start,NULL);
    
    sleep(2);

    gettimeofday(&end,NULL);
    int timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("UseTime : MicroSeconds:%dus \n          Seconds:%ds\n",timeuse,end.tv_sec-start.tv_sec);
    return 0;
}
