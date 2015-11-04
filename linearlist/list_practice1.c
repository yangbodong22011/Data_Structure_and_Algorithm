/*************************************************************************
	> File Name: link1.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Oct 2015 09:41:27 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)

struct student
{
    char  id[20];
    char  name[30];
    struct student *next;
};

struct student * head = NULL;               //作为链表的头指针，作为全局变量，每次读出来

void my_err(char *,int);                    //自定义的错误处理函数
struct student *read();                     //每次程序开始执行就读数据
void save();
void add_message();
void show_message();
struct student *find_message(char id[]);
void insert(struct student *);
void del_message(struct student *);
void reset_message();
//void del_repeat();

/*void del_repeat()
{
    struct student *p;
    int    a[100];
    int    i;
    p = head;
    for(i = 0; i < 100;i++)
        a[i] = 0;
    for(p;p->next;p = p->next)
        a[atoi(p->next->id)]++;
    for(i = 0;i < 100;i++)
    {
        if(a[i] >= 2)
        {

        }
    }



}*/
void reset_message()
{
    struct student *p1,*p2,*p3;
    p3 = head;
    p1 = p3->next;
    p3->next = NULL;
    while(p1)
    {
        p2 = p1;
        p1 = p1->next;
        p2->next = head->next;
        head->next = p2;
    }
}
void del_message(struct student *find)
{
    struct student *p;
    p = find->next;
    find->next = p->next;
    free(p);
    save();
}
void insert(struct student *find)
{
    struct student *p;
    p = (struct student *)malloc(LEN);
    printf("请输入插入的ID:");
    scanf("%s",p->id);
    printf("请输入插入的姓名:");
    scanf("%s",p->name);
    p->next = find->next;
    find->next = p;
    save();
}
struct student *find_message(char id[])
{
    struct student *p1;
    p1 = head;
    /*char id[20];
    printf("请输入ID:");
    scanf("%s",id);*/
    for(p1;p1->next;p1=p1->next)
    {
        if(!strcmp(p1->next->id,id))
        {
            return p1;
        }
    }
    if(p1->next == NULL)
    {
        printf("未找到\n");
        return p1;
    }
}
void show_message()
{
    struct student *p1;
    p1 = head->next;
    printf("ID\t\t姓名\n");
    printf("-----------------------------\n");
    while(p1)
    {
        printf("%s\t\t%s\n",p1->id,p1->name);
        p1 = p1->next;
    }
    
}
void add_message()
{
    struct student *p1,*p2;
    p1 = head;
    p2 = (struct student*)malloc(LEN);
    printf("请输入学号(学号为-1结束输入):");
    scanf("%s",&p2->id);
    while(strcmp(p2->id,"-1"))
    {
        printf("请输入姓名:");
        scanf("%s",&(p2->name));
        printf("%s\n",p2->name);
        p1->next = p2;
        p1 = p2;
        p2 = (struct student*)malloc(LEN);
        printf("请输入学号(学号为-1结束输入):");
        scanf("%s",p2->id);
    }
    p1->next = NULL;
    save();
}
void save()
{
    FILE *fp;
    struct student *p1,*p2;
    p1 = head->next;
    if((fp = fopen("studentinfo","w+")) == NULL)
    {
        my_err("fopen",__LINE__);
    }
    while(p1)
    {
        p2 = p1;
        p1 = p1->next;
        if(fwrite(p2,LEN,1,fp) == 0)
        {
            my_err("fwrite",__LINE__);
        }
    }
    fclose(fp);
}
struct student *read()
{
    FILE *fp;
    struct student *p1,*p2;
    p1 = (struct student *)malloc(LEN);
    p2 = (struct student *)malloc(LEN);
    head = p1;
    if((fp = fopen("studentinfo","a+")) == NULL)
    {
        my_err("fopen",__LINE__);
    }
    while(fread(p2,LEN,1,fp) && !feof(fp))
    {
        p1->next = p2;
        p1 = p2;
        p2 = (struct student *)malloc(LEN);
    }
    fclose(fp);
    return head;
}
void my_err(char * err_string,int line)
{
    fprintf(stderr,"line:%d,",line);
    perror(err_string);
    exit(0);
}



int main(int argc ,char *argv[])
{
    char  choice[20];
    char  id[20];
    struct student *find = NULL;
    head = read();
    do
    {
        printf("\t\t\t学生管理系统\n");
        printf("1:重新录入\n");
        printf("2:显示\n");
        printf("3:查找\n");
        printf("4:插入\n");
        printf("5:删除\n");
        printf("6:倒置\n");
        printf("7:剔重\n");
        printf("0:退出\n");
        printf("请选择(0-7):");
        scanf("%s",choice);
        /*while(strcmp(choice,"0") && strcmp(choice,"1") && strcmp(choice,"2"))
        {
            printf("无效输入，请重新选择\n");
            printf("请选择(0-2):");
            scanf("%s",choice);
        }*/
        switch(atoi(choice))
        {
            case 1:
            {
                add_message();
                break;
            }
            case 2:
            {
                show_message();
                break;
            }
            case 3:
            {
                printf("请输入ID:");
                scanf("%s",id);
                find = find_message(id);
                if(find->next)
                {
                    printf("\t\t查找结果如下\n");
                    printf("ID\t\t姓名\n");
                    printf("-----------------------------\n");
                    printf("%s\t\t%s\n",find->next->id,find->next->name);
                }
                break;
            }
            case 4:
            {
                printf("请输入原ID(注意：数据将被插入到此ID的左边):");
                scanf("%s",id);
                find = find_message(id);
                if(find->next)
                    insert(find);
                break;
            }
            case 5:
            {
                printf("请输入要删除的ID:");
                scanf("%s",id);
                find = find_message(id);
                if(find->next)
                    del_message(find);
                break;
            }
            case 6:
            {
                reset_message();
                break;
            }
            case 7:
            {
               // del_repeat();
                break;
            }
        }
    }while(strcmp(choice,"0"));
    

    
}

