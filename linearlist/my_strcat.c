/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Oct 2015 12:21:22 CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

void join(char *strs[],int strNum,char *dest)
{
    int i,j,k = 0,s = 0;
    int length[strNum+1];
    for(i = 0;i < strNum;i++)
    {
        length[i] = strlen(strs[i]);
        s += length[i];
    }
    for(i = 0;i < strNum;i++)
    {
        for(j = 0;j < length[i];j++)
        {
            dest[k++] = strs[i][j];
        }
    }
    dest[s] = '\0';
    
}

void main(void)
{
    char * strs[] = {"hello, ","welcome to ","C content!"};
    char dest[1000];
    join(strs,3,dest);
    printf("%s\n",dest);


}
