/*************************************************************************
	> File Name: my_time.h
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Sun 20 Mar 2016 03:35:12 PM CST
 ************************************************************************/

#ifndef _MY_TIME_H
#define _MY_TIME_H
#include<sys/time.h>

timeval printtime(void)
{
    struct timeval time;
    gettimeofday(&time,NULL);
    return time;
}


#endif
