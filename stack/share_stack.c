/*************************************************************************
	> File Name: share_stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Oct 2015 11:32:58 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define LEN sizeof(struct stack)
#define MAXSIZE 100

struct stack
{
    int data[100];
    int lefttop;
    int righttop;
};

void init(struct stack *);
void push(struct stack *);
int  pop_left(struct stack *);
int  pop_right(struct stack *);

int  pop_right(struct stack *head)
{
    int ret;
    ret = head->data[head->righttop];
    head->righttop++;
    return ret;
}
int  pop_left(struct stack *head)
{
    int ret;
    ret = head->data[head->lefttop];
    head->lefttop--;
    return ret;
}
void push(struct stack *head)
{
    char status;
    int  num;
    printf("请输入数据:");
    scanf("%d",&num);
    while(num != 0)
    {
        printf("左入栈:l 右入栈:r 请选择:");
        getchar();
        scanf("%c",&status);
        if(status == 'l')
        {
            head->lefttop++;
            head->data[head->lefttop] = num;
        }
        if(status == 'r')
        {
            head->righttop--;
            head->data[head->righttop] = num;
        }
        printf("请输入数据:");
        scanf("%d",&num);
    }
    
}
void init(struct stack *head)
{
    head->lefttop = -1;
    head->righttop = MAXSIZE;
}

int main(int argc,char *argv[])
{
    struct stack *head;
    int  ret1,ret2;
    head = (struct stack *)malloc(LEN);
    printf("--初始化\n");
    init(head);
    printf("--入栈\n");
    push(head);
    printf("--出栈\n");
    while(head->lefttop != -1 || head->righttop != MAXSIZE)
    {
        ret1 = pop_left(head);
        printf("左:%d\n",ret1);
        ret2 = pop_right(head);
        printf("右:%d\n",ret2);
    }
}
