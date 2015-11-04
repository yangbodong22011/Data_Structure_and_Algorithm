/*我知道错在那里了，这个问题被我当时想的有点复杂，我们的目的是使用Top_SeqStack每次弹出栈顶的元素，但是我忽略了指针S随着我们在Pop_SeqStack中s->top--的过程中是会不断更新的，所以我们没有必要再申请x去传，就把s->top--之后，传进去的s实际上就是被更新的，懂了没有？*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node
{
	int data[MAXSIZE];
	int top;
}SeqStack;

SeqStack *Init_SeqStack()
{
	SeqStack *s;
	s = malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
}

int Empty_SeqStack(SeqStack *s)
{
	if(s->top==-1) 
        return 1;
	else
        return 0;
}

int Push_SeqStack(SeqStack *s,int x)
{
	if(s->top == MAXSIZE-1)
		return 0; 
	else
    {
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

int  Pop_SeqStack(SeqStack *s)
{
	if( Empty_SeqStack(s))
		return 0;
	else
    {
		(s->top)--;
	}
}

int Top_SeqStack(SeqStack *s)
{
	if(Empty_SeqStack(s))
		return 0;
	else 
        return (s->data[s->top]);
}

int main(void)
{
	SeqStack *s;
	SeqStack *x;
	int a[5]={10,20,30,40,50};
	int i,j;
    s = Init_SeqStack();
	/*if(Empty_SeqStack(s) == 1)
		printf("empty\n");*/
	for(i=0;i<5;i++)
	{
		Push_SeqStack(s,a[i]);
	}
	/*for(i  = 4 ;i >= 0 ;i--)
	{
		j = Pop_SeqStack(s);
		printf("a[%d] : %d\n",i,j);
	}*/
	for(i=0;i<5;i++)
	{
		j = Top_SeqStack(s);
        if(j)
		    Pop_SeqStack(s);
		printf("%d\n",j);
	}
	return 0;
}
