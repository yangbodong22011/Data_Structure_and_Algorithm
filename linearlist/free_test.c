#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct linklist  
{  
    int data;  
    struct linklist *next;  
}LB;  
  
LB *creat(void)  
{  
    int i;  
    LB *head,*p,*q;  
    head = (LB *)malloc(sizeof(LB));  
    p = (LB *)malloc(sizeof(LB));  
    head->next = p;  
    scanf("%d",&p->data);  
    for(i = 0;i < 3;i++)  
    {     
        q = (LB *)malloc(sizeof(LB));  
        scanf("%d",&q->data);  
        p->next = q;  
        p = p->next;      
    }     
    p->next = NULL;  
    return head;  
}  
  
int main( int argc,char *argv[] )  
{  
    LB *p;   
    p = creat();  
    //p = p->next;  
    free(p);  
    printf("output:%d\n",p->next->data);                                                                                                                 
    return 0;  
}  
