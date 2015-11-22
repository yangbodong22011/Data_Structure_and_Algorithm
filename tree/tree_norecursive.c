/*************************************************************************
	> File Name: tree_norecursive.c
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Nov 2015 10:53:05 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "my_stack.h"

Tree creat(Head);
void PreOrder(Tree,Head);
void InOrder(Tree,Head);
void LastOrder(Tree,Head);
void LevelOrder(Tree,Head);

void LevelOrder(Tree root,Head head) 
{
    int i = 0;
    if(root) {
        push(head,root);
    }
    while(root || head->top != 7) {   //实际上7是总元素个数
        root = head->node[i++];         //模拟下队列,虽然是假的
        printf("%c ",root->data);
        if(root->lchild) {
            push(head,root->lchild);
        }
        if(root->rchild) {
            push(head,root->rchild);
        }
    }
}
void LastOrder(Tree root,Head head)
{
    Tree q = NULL;
    while(root || head->top != -1 ) {
        if(root) {
            push(head,root);
            root = root->lchild;
        }                                  //每次需要先走到最左边
        else {
            root = gettop(head);
            if((root->rchild == NULL )|| (root->rchild == q)) { //取栈顶判断
                //如果邮孩子为空或者右孩子刚被访问过，说明上一个元素的公恩两个已经结束了，那就访问根，
                root = pop(head);
                printf("%c ",root->data);
                q = root;      //这一步保存当前根的位置，以便下一次判断
                root = NULL;   //下一次直接判断
            }
            else {
                root = root->rchild; //否则左边完毕就往右边走。
            }
            
        }
    }
}
void InOrder(Tree root,Head head)
{
    while(root || head->top != -1) {
        if(root) {
            push(head,root);
            root = root->lchild;
        }
        else {
            root = pop(head);
            printf("%c ",root->data);
            root = root->rchild;
        }
    }
}
void PreOrder(Tree root,Head head)
{
    while(root || head->top != -1) {
        if(root) {
            printf("%c ",root->data);
            push(head,root);
            root = root->lchild;
        }
        else {
            root = pop(head);
            root = root->rchild;
        }
    }
}
Tree creat(Head head)
{
    Tree p,q;
    Tree root = NULL;
    char ch;
    int flag = 0;
    ch = getchar();
    if(ch == '#') {
        return 0;
    }
    root = (Tree)malloc(sizeof(tree));   //为第一个节点申请空间并且入栈
    p = root;
    p->data = ch;
    push(head,p);
    while(head->top != -1 || ch != '#') {
        ch = getchar();
        if(ch == '#' && flag == 0) {     //如果给右孩子填过值，那下面就走左边
            flag = 1;
        }
        else if(ch == '#' && flag == 1) { //连续读到两个#,那就边判断边将右孩子和栈顶右孩子一样的出栈，
            //说明右边这些部分已经结束                                         
            p = pop(head);
            while(head->top != -1 && gettop(head)->rchild == p) {
                p = pop(head);
            }
        }
        else {
            q = (Tree)malloc(sizeof(tree));
            q->data = ch;
            if(flag == 0) {              //正常情况先访问左边
                p = gettop(head);
                push(head,q);
                p->lchild = q;
            }
            if(flag == 1) {              //要是读到'#'就来这一句。
                p = gettop(head);
                p->rchild = q;
                push(head,q);
                flag = 0;
            }
        }
    }
    return root;
}


int main(int argc,char *argv[])
{
    Tree root = NULL;
    Head head = initstack(head);
    printf("非递归建树:\n");
    root = creat(head);
    printf("非递归先序遍历:\n");
    PreOrder(root,head);
    printf("\n");
    printf("非递归中序遍历:\n");
    InOrder(root,head);
    printf("\n");
    printf("非递归后序遍历:\n");
    LastOrder(root,head);
    printf("\n");
    printf("层次遍历\n");
    LevelOrder(root,head);
    printf("\n");
}
