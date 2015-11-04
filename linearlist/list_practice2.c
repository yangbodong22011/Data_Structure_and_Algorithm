/*************************************************************************
	> File Name: link.c
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Aug 2015 02:40:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define LEN sizeof(struct student)
struct student
{
    int  id;
    char name[20];
    struct student *next;
};

struct student*  head = NULL;

void save();
struct student* read();
void print();
void record();

struct student* read()
{
    FILE *fp;
    struct student *p1,*p2;
    p1 = (struct student *)malloc(LEN);
    p2 = (struct student *)malloc(LEN);
    head = p1;
    if((fp = fopen("studentinfo","a+")) == NULL)
    {
        perror("fopen");
    }
    while((fread(p2,LEN,1,fp) != 0) && (!feof(fp)))
    {
        p1->next = p2;
        p1 = p2;
        p2 = (struct student *)malloc(LEN);
    }
    p1->next = NULL;
    free(p2);
    fclose(fp);
    return (head);
}
void record()
{
    struct student *p1,*p2;
    p1 = head;
    p2 = (struct student*)malloc(LEN);
    printf("请输入学号(学号为“-1”表示结束)：");
    scanf("%d",&p2->id);
    while((p2->id) != -1)
    {
        printf("请输入姓名：");
        scanf("%s",p2->name);
        p1->next = p2;
        p1 = p2;
        p2 = (struct student*)malloc(LEN);
        printf("请输入学号(学号为“-1”表示结束)：");
        scanf("%d",&p2->id);
    }
    p1->next = NULL;
    save();
}
void save()
{
    FILE *fp;
    struct student *p1;
    p1 = head->next;
    if((fp = fopen("studentinfo","w+")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    while(p1 != NULL)
    {
        fwrite(p1,LEN,1,fp);
        p1 = p1->next;
    }
    fclose(fp);
}
void print()
{
    FILE *fp;
    struct student stu;
    if((fp = fopen("studentinfo","r")) == NULL)
    {
        perror("fopen");
        exit(0);
    }
    printf("学号\t姓名\n");
    while((fread(&stu,LEN,1,fp) != 0) && (!feof(fp)))
    {
        printf("%d\t%s\n",stu.id,stu.name);
    }
}
void add()
{
    struct student *p1,*p2;
    p1 = head->next;
    for(;p1->next;p1=p1->next);
    p2 = (struct student*)malloc(LEN);
    printf("请输入学号(学号为“-1”表示结束)：");
    scanf("%d",&p2->id);
    while((p2->id) != -1)
    {
        printf("请输入姓名：");
        scanf("%s",p2->name);
        p1->next = p2;
        p1 = p2;
        p2 = (struct student*)malloc(LEN);
        printf("请输入学号(学号为“-1”表示结束)：");
        scanf("%d",&p2->id);
    }
    p1->next = NULL;
    save();
}
int main(int argc,char *argv[])
{
    int choice;
    head = read();
    do
    {
        printf("1:输入信息\n");
        printf("2:显示信息\n");
        printf("3:追加信息\n");
        printf("0:退出\n");
        printf("请选择:(0~3):");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                record();
                break;
            }
            case 2:
            {
                print();
                break;
            }
            case 3:
            {
                add();
                break;
            }
        }
    }while(choice != 0);
}
