/*************************************************************************
	> File Name: josepf.c
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Oct 2015 14:53:21 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct josepf)

struct josepf
{
    int  id;
    char passwd[20];
    struct josepf * next;
};

int joseph(struct josepf *,struct josepf *,int);

int joseph(struct josepf *trans,struct josepf *tail,int passwd1)
{
    char passwd[20];
    int i;
    struct josepf *q,*p,*next,*s;
    if(passwd1 == 1)
    {
        s = trans->next;
        tail->next = s;
        strcpy(passwd,trans->passwd);
        printf("第%d个人出列(密码:%s)\n",trans->id,trans->passwd);
        free(trans);
        if(s->next != s)
        {
            joseph(s,tail,atoi(passwd));
        }
        else
            printf("第%d个人出列(密码:%s)\n",s->id,s->passwd);
    }
    else
    {
        for(i = 1,p = trans;i != passwd1;i++,p = p->next)
            q = p;
        next = p->next;
        strcpy(passwd,p->passwd);
        q->next = next;
        printf("第%d个人出列(密码:%s)\n",p->id,p->passwd);
        free(p);
        if(next->next != next)
        {
                joseph(next,q,atoi(passwd));
        }
        else
            printf("第%d个人出列(密码:%s)\n",next->id,next->passwd);
    }
}
int main(int argc,char *argv[])
{
    struct josepf *p1,*p2,*head,*tail;
    int  num,firstpasswd;
    int  i,id = 1;
    printf("请输入人数:");
    scanf("%d",&num);
    printf("请输入初始密码:");
    scanf("%d",&firstpasswd);
    p1 = (struct josepf *)malloc(LEN);
    head = p1;
    printf("请输入第1个人的密码:");
    scanf("%s",p1->passwd);
    p1->id = 1;
    for(i = 1;i < num;i++)
    {
        p2 = (struct josepf *)malloc(LEN);
        printf("请输入第%d个人的密码:",i+1);
        scanf("%s",p2->passwd);
        p2->id = i+1;
        p1->next = p2;
        p1 = p2;
    }
    p1->next = head;
    tail = p1;
    joseph(head,tail,firstpasswd);  
    return 0;
}
