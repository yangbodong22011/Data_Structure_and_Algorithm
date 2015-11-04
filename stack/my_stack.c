/*************************************************************************
	> File Name: my_stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Oct 2015 10:35:00 CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 100
#define LEN sizeof(struct stack)

struct stack
{
    int data[MAXSIZE];
    int top;
};

void init(struct stack *);
void is_empty(struct stack *);
void push(struct stack *);
int  top(struct stack *);
int  pop(struct stack *);

int  pop(struct stack *head)
{
    int ret;
    ret  = head->data[head->top];
    head->top--;
    return ret;
}
int  top(struct stack *head)
{
    return  head->data[head->top];
}
void push(struct stack *head)
{
    int x,times = 1,i = 0;
    printf("请输入第%d个入栈元素(输入-1表示结束):",times++);
    scanf("%d",&x);
    while(x != -1)
    {
        head->top++;
        head->data[head->top] = x;
        printf("请输入第%d个入栈元素(输入-1表示结束):",times++);
        scanf("%d",&x);
    }
}
void is_empty(struct stack *head)
{
    if(head->top == -1)
        printf("空栈\n");
    else
        printf("栈非空\n");
}
void init(struct stack *head)
{
    head->top = -1;
}
int main(int argc,char *argv[])
{
    int  ret;
    struct stack *head;
    head = (struct stack *)malloc(LEN);
    
    printf("\t\t-----栈的初始化-----\n");
    init(head);
    printf("\t\t-----栈的判空-----\n");
    is_empty(head);
    printf("\t\t-----入栈-----\n");
    push(head);
    printf("\t\t-----栈的判空-----\n");
    is_empty(head);
    printf("\t\t-----取栈顶元素-----\n");
    ret = top(head);
    printf("栈顶元素 : %d\n",ret);
    printf("\t\t-----出栈-----\n");
    while(head->top != -1)
    {
        ret = pop(head);
        printf("%d\n",ret);
    }
}
