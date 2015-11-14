/*************************************************************************
	> File Name: mowangyuyan.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 2015 20:38:29 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    char data[50];
    int top;
}Stack,*TypeStack;

typedef struct queue
{
    char data[50];
    int front;
    int rear;
}Queue,*TypeQueue;

char A[] = {'s','a','e'};                                //A对应的小写字母
char B[] = {'t','s','a','e','d','s','a','e'};            //B对应的小写字母

TypeStack initstack();                                   //栈的初始化
TypeQueue initqueue();                                   //队列的初始化
void pushstack(TypeStack,char);                          //入栈
char popstack(TypeStack);                                //出栈
void analyse(TypeStack,TypeStack,TypeStack,TypeQueue);   //分解魔王语言
void pushqueue(TypeQueue,char);                          //入队列
void explanstack(TypeStack,TypeQueue);                   //栈的解释
char popqueue(TypeQueue);                                //出队列
void explanqueue(TypeQueue,TypeQueue);                   //队列的解释

void explanqueue(TypeQueue queue1,TypeQueue queue2)
{
    char x,y;
    while(queue1->rear != queue1->front) {
        queue1->rear++;
        x = queue1->data[queue1->rear];                  //出一个队列
        y = queue1->data[queue1->front];                 //获得队列front处元素
        pushqueue(queue2,y);
        pushqueue(queue2,x);
    } 
    queue2->front--;                                     //会将front处元素重复入队列两次
}
char popqueue(TypeQueue queue2)
{
    queue2->rear++;
    return queue2->data[queue2->rear];
}
void explanstack(TypeStack stack,TypeQueue queue2)
{
    char x;
    int i;
    while(stack->top != -1) {
        x = popstack(stack);
        if(x == 'A') {
            for(i = 0;i < 3;i++) {                       //栈遇到A就将其对应元素入栈
                pushqueue(queue2,A[i]);                  
            }
        }
        if(x == 'B') {                                   //遇到B就将对应元素入栈
            for(i = 0;i < 8;i++) {
                pushqueue(queue2,B[i]);
            }
        }
    }
}
void pushqueue(TypeQueue queue1,char x)
{
    queue1->front++;
    queue1->data[queue1->front] = x;    
}
void analyse(TypeStack head,TypeStack head1,TypeStack head2,TypeQueue queue1)
{
    char x;
    while(head->top != -1)
    {
        x = popstack(head);
        if(x == ')' || x == '(') {
            if(x == ')') {
                while((x = popstack(head)) != '(') {
                    pushqueue(queue1,x);
                }
                while(head->top != -1) {
                    x = popstack(head);
                    pushstack(head2,x);
                }
                return ;
            }
        }
        pushstack(head1,x);        //没有遇到()的情况
    }
}
char popstack(TypeStack head)
{
    char x = head->data[head->top];
    head->top--;
    return x;
}
void pushstack(TypeStack head,char x)
{
    head->top++;
    head->data[head->top] = x;
}
TypeQueue initqueue()
{
    TypeQueue head = (TypeQueue)malloc(sizeof(Queue));
    head->front = head->rear = -1;
    return head;

}
TypeStack initstack()
{
    TypeStack head = (TypeStack)malloc(sizeof(Stack));
    head->top = -1;
    return head;
}


int main(int argc,char *argv[])
{
    char ch;
    TypeStack head,stack1,stack2;   //head用来保存最初读进来的语言，stack1保存语言中')'后的部分，stack2保存'('前的部分。
    TypeQueue queue1,queue2;        //queue1保存括号中的部分，queue2是解释后的语言。
    head = initstack();
    stack1 = initstack();
    stack2 = initstack();
    queue1 = initqueue();
    queue2 = initqueue();
    printf("请输入魔王语言：");
    while((ch = getchar()) != '\n') {
        pushstack(head,ch);
    }
    analyse(head,stack1,stack2,queue1); //将head中魔王语言分解到一个栈和两个队列中
    explanstack(stack2,queue2);         //栈的解释器
    explanqueue(queue1,queue2);         //队列的解释器
    explanstack(stack1,queue2);
    while(queue2->rear != queue2->front) {
        printf("%c",queue2->data[queue2->rear++]);
    }
    printf("%c\n",queue2->data[queue2->rear]);

    
}
