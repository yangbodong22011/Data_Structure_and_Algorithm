/*************************************************************************
	> File Name: polynomial.c
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Nov 2015 16:42:39 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
    int coef;
    int expn;
    struct polynomial *next;
}pol,*poly;

poly creat();                   //多项式的创建
void print(poly);               //显示
poly add(poly,poly);            //加法
poly minus(poly,poly);          //减法实现的是第一个减去第二个
poly take(poly,poly);           //乘法

poly take(poly head1,poly head2)
{
    int coef,expn;
    poly s,t;
    poly head3,p,q;
    head3 = (poly)malloc(sizeof(poly));
    q = head3;
    head3->next = NULL;
    for(s = head1->next;s;s = s->next) {
        for(t = head2->next;t;t = t->next) {
            p = (poly)malloc(sizeof(poly));
            p->coef = s->coef * t->coef;
            p->expn = s->expn + t->expn;
            p->next = q->next;
            q->next = p;
            q = p;
        }
    }
    //要是有重复，剔除重复
    q = head3;
    for(q;q->next;q = q->next) {
        for(p = q->next;p->next;p = p->next) {
            if(q->next->expn == p->next->expn) {
                printf("%d\n",q->next->expn);
                q->next->coef = q->next->coef + p->next->coef;
                s = p->next;
                p->next = s->next;
                free(s);
            }
        }
    }
    return head3;

}
poly minus(poly head1,poly head2)
{
    poly head;
    poly p = head1;
   
    //先将一个链表全部乘-1
    while(p->next) {
        p->next->coef *= -1;
        p = p->next;
    }
    head = add(head1,head2);
    poly q = head->next;
    for(q;q;q = q->next) {
        q->coef *= -1;
    }
    return head;

}
poly add(poly head1,poly head2)
{
    poly head3,p,q;
    head3 = (poly)malloc(sizeof(pol));
    head3->next = NULL;
    head1 = head1->next;
    head2 = head2->next;
    p = head3;
    while(head1 && head2) {
        q = (poly)malloc(sizeof(pol));
        //针对三种不同的情况
        if(head1->expn < head2->expn) {
            q->expn = head1->expn;
            q->coef = head1->coef;
            head1 = head1->next;
        }
        else if(head1->expn == head2->expn) {
            q->expn = head1->expn;
            q->coef = head1->coef + head2->coef;
            head1 = head1->next;
            head2 = head2->next;
        }
        else {
            q->expn = head2->expn;
            q->coef = head2->coef;
            head2 = head2->next;
        }
        //如果系数不为0，就向后移动
        if(q->coef != 0) {
            q->next = p->next;
            p->next = q;
            p = q;
        }
        //如果系数相加之后抵消就free掉那个空间
        else {
            free(q);
        }
    }
    //某个跳出循环之后，检测另一个时候完。
    if(head1 == NULL){
        p->next = head2;
    }
    if(head2 == NULL){
        p->next = head1;
    }
    return head3;
}
void print(poly head)
{
    poly q;
    q = head->next;
    int flag = 1;
    //如果多项式为0
    if(!q) {
        putchar('0');
        printf("\n");
        return ;
    }
    //要是多项式不为0
    while(q) {
        //第一次不用打印加号，以后每次为正的话打印加号
        if(q->coef >0 && flag != 1) {
            putchar('+');
        }
        //要是系数为1
        if(q->coef == 1) {
            //指数为0
            if(!q->expn) {
                putchar('1');
            }
            //指数为1
            else if(q->expn == 1) {
                putchar('X');
            }
            //其它
            else {
                printf("X^%d",q->expn);
            }
        }
        //系数为-1
        else if(q->coef == -1) {
            //指数为0
            if(!q->expn) {
                printf("-1");
            }
            //指数为1
            else if(q->expn == 1) {
                printf("-X");
            }
            else {
                printf("-X^%d",q->expn);
            }
        }
        else {
            printf("%d",q->coef);
            if(q->expn == 1) {
                putchar('X');
            }
            else if(q->expn){
                printf("X^%d",q->expn);
            }
        }
        q = q->next;
        flag++;
    }
    printf("\n");
}
poly creat()
{
    int coef;
    int expn;
    poly head,tail,curr;
    head = (poly)malloc(sizeof(pol));
    tail = head;
    
    printf("请输入系数和指数，如\"2 3\"表示2X^3，输入\"0 0\"表示结束输入\n");
    scanf("%d %d",&coef,&expn);
    while(coef != 0) {
        curr = (poly)malloc(sizeof(pol));
        curr->coef = coef;
        curr->expn = expn;
        tail->next = curr;
        tail = curr;
        scanf("%d %d",&coef,&expn);
    }
    tail->next = NULL;
    return head;
}

int main(int argc,char *argv[])
{
    poly head1,head2,headadd;
    printf("第一个多项式的创建\n");
    head1 = creat();
    printf("第一个多项式: ");
    print(head1);
    printf("第二个多项式的创建\n");
    head2 = creat();
    printf("第二个多项式: ");
    print(head2);
    printf("多项式的加法\n");
    headadd = add(head1,head2);
    print(headadd);
    printf("多项式的减法\n");
    headadd = minus(head1,head2);
    print(headadd);
    printf("多项式的乘法\n");
    headadd = take(head1,head2);
    print(headadd);
}
