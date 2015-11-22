/*************************************************************************
	> File Name: my_stack.h
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Nov 2015 10:47:04 CST
 ************************************************************************/

#ifndef _MY_STACK_H
#define _MY_STACK_H

typedef struct tree 
{
    char data;
    struct tree *lchild;
    struct tree *rchild;
}tree,*Tree;

typedef struct stack
{
    struct tree *node[30];
    int top;
}*Head;

Head initstack(Head head)
{
    head = (Head)malloc(sizeof(struct stack));
    head->top = -1;
    return head;
}
int isempty(Head head)
{
    if(head->top == -1){
        return 0;
    }
    else{
        return 1;
    }
}
void push(Head head,Tree root)
{
    head->top++;
    head->node[head->top] = root;
}
Tree pop(Head head) 
{
    Tree root;
    root = head->node[head->top];
    head->top--;
    return root;
}
Tree gettop(Head head) 
{
    return head->node[head->top];
}


#endif
