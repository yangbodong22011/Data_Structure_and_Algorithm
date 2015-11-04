/*************************************************************************
	> File Name: head_insert.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Oct 2015 02:02:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)

struct student 
{
    int  data;
    struct student *next;
};

int main(int argc,char *argv[])
{
    struct student *head,*p1,*p2,*p3;
    head = (struct student*)malloc(LEN);
    p1 = (struct student*)malloc(LEN);
    p2 = (struct student*)malloc(LEN);
    printf("请输入数据：");
    scanf("%d",&p1->data);
    if(p1->data == -1)
        head->next = NULL;
    else
    {
        p1->next = NULL;
        printf("请输入数据：");
        scanf("%d",&p2->data);
        while(p2->data != -1)
        {
            p2->next = p1;
            head->next = p2;
            p1 = p2;
            //p2->next = head->next;
            p2 = (struct student *)malloc(LEN);
            printf("请输入数据：");
            scanf("%d",&p2->data);
        }
    }

    p3 = head->next;
    for(p3;p3;p3 = p3->next)
        printf("%d ",p3->data);
    printf("\n");


}
