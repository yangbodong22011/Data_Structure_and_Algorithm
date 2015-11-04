/*************************************************************************
	> File Name: a循环链表的合并.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Oct 2015 11:04:17 CST
 ************************************************************************/
//创建两个循环链表,并且完成合并
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
    struct student *head,*head2,*p1,*p2,*p3,*p4,*tail,*tail2;
    head = (struct student *)malloc(LEN);
    head2 = (struct student *)malloc(LEN);
    //创建链表1
    p2 = (struct student *)malloc(LEN);
    p3 = (struct student *)malloc(LEN);
    p1 = head;
    p1->next = p2;
    p1 = p2;
    printf("请输入链表1的数据:");
    scanf("%d",&p2->data);
    while(p2->data != 0)
    {
        p2 = (struct student *)malloc(LEN);
        p1->next = p2;
        p1 = p2;
        printf("请输入链表1的数据:");
        scanf("%d",&p2->data);
    }
    tail = p1;
    tail->next = head;
    
    printf("this is link 1:\n");
    for(p1 = head;p1->next != head;p1 = p1->next)
        printf("%d ",p1->next->data);
    printf("\n");

    //创建链表2
    p4 = head2;
    p4->next = p3;
    p4 = p3;
    printf("请输入链表2的数据:");
    scanf("%d",&p3->data);
    while(p3->data != 0)
    {
        p3 = (struct student *)malloc(LEN);
        p4->next = p3;
        p4 = p3;
        printf("请输入链表2的数据:");
        scanf("%d",&p3->data);
    }
    tail2 = p4;
    tail2->next = head2;
    
    printf("this is link 2:\n");
    for(p4 = head2;p4->next != head2;p4 = p4->next)
        printf("%d ",p4->next->data);
    printf("\n");

    //链表的合并
    printf("the result of after merge:\n");
    tail->next = head2->next;
    free(head2);
    tail2->next = head;


    for(p1 = head;p1->next != head;p1 = p1->next)
        printf("%d ",p1->next->data);

        printf("\n");

        return 0;
    
}
