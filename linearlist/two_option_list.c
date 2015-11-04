/*************************************************************************
	> File Name: 双向链表.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Oct 2015 19:26:20 CST
 ************************************************************************/
//此程序完成了对于双向链表的创建,遍历,查找,以及删除节点.

#include<stdio.h>
#include<stdlib.h>
#define LEN  sizeof(struct student)

struct student
{
    struct student *prior;
    int data;
    struct student *next;
};

struct student *find_data(struct student *head,struct student *tail,int times);    
void insert_data(struct student *);
void del_data(struct student *);

void del_data(struct student *find)
{
    struct student *p;
    p = find->next;
    if(p->next)
    {
        find->next = p->next;
        find->next->prior = find;
        free(p);
    }
    else
    {
        find->next = p->next;
        free(p);
    }
}
void insert_data(struct student *find)
{
    int x;
    struct student *p;
    p = (struct student *)malloc(LEN);
    printf("请输入插入的data:");
    scanf("%d",&p->data);
    p->next = find->next;
    find->next->prior = p;
    find->next = p;
    p->prior = find;

}
struct student *find_data(struct student *head,struct student *tail,int middle)
{
    int  x;
    printf("请输入data值:");
    scanf("%d",&x);
    if(x <= middle)
    {
        for(head;head->next;head = head->next)
        {
            if(head->next->data == x)
                return head;
        }
    }
    else
    {
        for(tail;tail;tail = tail->prior)
        {
            if(tail->data == x)
                return tail->prior;
        }
    }
}



int main(int argc,char *argv[])
{
    struct student *head,*p1,*p2,*tail,*find;
    int x;
    int times = 1;                            //记录数据量
    
    //双向链表的建立
    head = (struct student *)malloc(LEN);
    p1 = head;
    p1->prior = NULL;
    printf("请输入数据:");
    scanf("%d",&x);
    while(x != 0)
    {
        p2 = (struct student *)malloc(LEN);
        times++;                                   
        p2->data = x;
        p1->next = p2;
        p2->prior = p1;
        p1 = p2;
        printf("请输入数据:");
        scanf("%d",&x);
    }
    p1->next = NULL;
    tail = p1;

    //正序和倒序遍历
    printf("正序遍历\n");
    for(p1 = head;p1->next;p1 = p1->next)
        printf("%d ",p1->next->data);
    printf("\n");

    printf("倒序遍历\n");
    for(p1 = tail;p1->prior;p1 = p1->prior)
        printf("%d ",p1->data);
    printf("\n");

    //查找节点
    //printf("%d\n",times);
    //find = find_data(head,tail,times/2);             
    //times的作用是这样的,在我的查找函数里,要是你的数据小于一半,那我就从头节点开始遍历,要是大于一半,那我就从尾开始遍历
    
    //插入节点
    printf("插入节点在此data值的左边,");
    find = find_data(head,tail,times/2);             
    insert_data(find);
    printf("正序遍历\n");
    for(p1 = head;p1->next;p1 = p1->next)
        printf("%d ",p1->next->data);
    printf("\n");

    //删除节点
    find = find_data(head,tail,times/2);             
    del_data(find);
    printf("正序遍历\n");
    for(p1 = head;p1->next;p1 = p1->next)
        printf("%d ",p1->next->data);
    printf("\n");
    


    


}
