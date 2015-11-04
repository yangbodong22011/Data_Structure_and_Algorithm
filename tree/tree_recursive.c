/*************************************************************************
	> File Name: tree_recursive.c
	> Author: 
	> Mail: 
	> Created Time: Fri 30 Oct 2015 08:28:16 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN sizeof(struct tree)

struct tree
{
    char   data;
    struct tree *lchild;
    struct tree *rchild;
};
int  leafnumber = 0;                                            //统计叶子节点的数量
struct tree *creat();                                           //二叉数的创建
void preorder(struct tree *);                                   //二叉树的先序遍历
void inorder(struct tree *);                                    //中序遍历
void lastorder(struct tree *);                                  //后序遍历
void inputleaf(struct tree *);                                  //输出叶子节点并且统计个数
struct tree *current(struct tree *,char,struct tree **);        //获得当前节点
void parent(struct tree *,struct tree *);                       //获得双亲节点
int  depth(struct tree *);

int  depth(struct tree* root)
{
    int hl,hr,h;
    if(!root)
    {
        return 0;
    }
    hl = depth(root->lchild);
    hr = depth(root->rchild);
    return hl>hr?hl+1:hr+1;
    
}
void parent(struct tree *root,struct tree *current)
{
    if(root)
    {
        parent(root->lchild,current);
        parent(root->rchild,current);
        if((root->lchild == current) || (root->rchild == current))
        {
            printf("双亲节点为:%c\n",root->data);
        }
    }
}

struct tree * current(struct tree *root,char ch,struct tree **root1)
{
    if(root)
    {
        current(root->lchild,ch,root1);
        if(root->data == ch)
        {
            *root1 = root;
        }
        current(root->rchild,ch,root1);
    }
}
void inputleaf(struct tree *root)
{
    if(root)
    {
        if(!root->lchild && !root->rchild)
        {
            printf("%c ",root->data);
            leafnumber++;
        }
        inputleaf(root->lchild);
        inputleaf(root->rchild);
    }
}
void lastorder(struct tree *root)
{
    if(root)
    {
        lastorder(root->lchild);
        lastorder(root->rchild);
        printf("%c ",root->data);
    }
}
void inorder(struct tree *root)
{
    if(root)
    {
        inorder(root->lchild);
        printf("%c ",root->data);
        inorder(root->rchild);
    }
}
void preorder(struct tree *root)
{
    if(root)
    {
        printf("%c ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
struct tree *creat()
{
    struct tree *root;
    char ch = getchar();
    if(ch == '#')
    {
        root = NULL;
    }
    else
    {
        root = (struct tree*)malloc(LEN);
        root->data = ch;
        root->lchild = creat();
        root->rchild = creat();
    }
    return root;
}

int main(int argc,char *argv[])
{
    struct tree *root = NULL;
    struct tree *currentnode = NULL;
    char   ch;
    int depthoftree;

    printf("--------二叉树的创建\n");
    root = creat();
    printf("--------先序遍历\n");
    preorder(root);
    printf("\n");
    printf("--------中序遍历\n");
    inorder(root);
    printf("\n");
    printf("--------后序遍历\n");
    lastorder(root);
    printf("\n");
    printf("--------输出所有的叶子节点并统计个数\n");
    inputleaf(root);
    printf("\n");
    printf("叶子节点个数为:%d\n",leafnumber);
    printf("--------求双亲节点\n");
    printf("请输入要求双亲节点的节点：");
    memset(stdin,0,100);
    ch = getchar();
    current(root,ch,&currentnode);
    parent(root,currentnode);
    printf("--------求二叉树的深度\n");
    depthoftree = depth(root);
    printf("二叉树的深度为 %d \n",depthoftree);



    


 
    return 0;
}
