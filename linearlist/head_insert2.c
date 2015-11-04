/*************************************************************************
	> File Name: head_insert2.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Oct 2015 02:41:18 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)


struct student
{
    int data;
    struct student *next;
};

int main(int argc,char *argv[])
{
    struct student *head;
    struct student *s;
    int x;
    head = (struct student*)malloc(LEN);
    head->next = NULL;
    printf("请输入数据：");
    scanf("%d",&x);
    while(x != -1)
    {
        s = (struct student *)malloc(LEN);
        s->data = x;
        s->next = head->next;
        head->next = s;
        printf("请输入数据：");
        scanf("%d",&x);
    }
    for(x = 0;head->next;head->next = head->next->next)
    {
        printf("%d ",head->next->data);
        x++;
    }
    printf("\n");
    printf("length:%d\n",x);
}
