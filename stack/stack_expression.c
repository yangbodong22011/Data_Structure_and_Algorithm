/*************************************************************************
	> File Name: stack_expression.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2015 16:55:14 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    char data[20];
    int top;
};

char answer(); 
void push(struct stack *,char);                      //入栈函数
struct stack *initstack();                           //栈的初始化
char gettop(struct stack *);                         //取得栈顶
char pop(struct stack *);                            //弹出元素
int opest(char);                                     //判断符号性质，是元素还是数字
char compare(char,char);                             //比较运算符的优先级
char cal(char,char,char);                            //计算函数

char cal(char data1,char ch,char data2)
{
    char data;
    switch(ch) {
        case '+':data = data1 + data2;break;
        case '-':data = data1 - data2;break;
        case '*':data = data1 * data2;break;
        case '/':data = data1 / data2;break;
    }
    return data;
}
char compare(char a,char b)
{
    int i, j;
    char pre[7][7] ={                                //定义运算符之间的优先级
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='},
    };
    switch(a){
        case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '#': i = 6; break;
    }
    switch(b){
        case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '#': j = 6; break;
    }
    return pre[i][j];
    
}
int opest(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' ||ch == '/'
      || ch == '(' || ch == ')' || ch == '#') {
          return 1;
      }
    else {
        return 0;
    }
}
char pop(struct stack *head)
{
    char x = head->data[head->top];
    head->top--;
    return x;
}
char gettop(struct stack *head)
{
    return head->data[head->top];
}
struct stack *initstack()
{
    struct stack * head;
    head = (struct stack *)malloc(sizeof(struct stack));
    head->top = -1;
    return head;
}
void push(struct stack *head,char x)
{
    head->top++;
    head->data[head->top] = x;
}

char  answer()
{
    char ch,x;
    int data;
    struct stack  *head1,*head2;                     
    head1 = initstack();                              //head1为运算符栈
    head2 = initstack();                              //head2为操作数栈
    push(head2,'#');
    printf("请输入表达式:");
    ch = getchar();
    while(ch != '#' || gettop(head2) != '#') {
        if(!opest(ch)) {
            data = ch - '0';
            ch = getchar();
            while(!opest(ch)) {
                data = data*10 + ch-'0';
                ch = getchar();
            }
            push(head1,data);                        //将数字压入操作数栈。
        }
        else {
                printf("%c\n",compare(gettop(head2),ch));
            switch(compare(gettop(head2),ch)) {
                case '<': {
                    //将运算符入栈
                    printf("222222\n");
                    push(head2,ch);
                    ch = getchar();
                    break;
                }
                case '=': {
                    pop(head2);
                    ch = getchar();
                    break;
                }
                case '>': {
                    data = cal(pop(head1),pop(head2),pop(head1));
                    printf("data:%d\n",data);
                    push(head1,data);
                    if(ch != '#' && ch != ')') {
                        push(head2,ch);
                        ch = getchar();
                    }
                    if(ch == ')') {
                        break;
                    }
                    break;
                }
            }
        }
    }
    data = gettop(head1);
    return data;
}

int main(int argc,char *argv[])
{
    char ret;
    ret = answer();
    printf("答案：%d\n",ret);
}
