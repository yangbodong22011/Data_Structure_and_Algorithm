/*************************************************************************
	> File Name: graph_matrix.c
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 27 Nov 2015 08:46:17 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"my_queue.h"

int visit[MAXSIZE] = {0};              //作为输出判断数组

AdjList *build_Graph();
void find_insert(AdjList *,char,char);
void findHead(AdjList *,char,int *);
void insert(ArcNode **,int);
void ShowAdjList(AdjList *);
void DFS(AdjList *,int);
void DFS_traverse(AdjList *);
void CleanVisit();
void BFS(AdjList *,int);

void BFS(AdjList *G,int v1)
{ 
    ArcNode *p;
    Queue Qhead = init();
    printf("%c ",G->vertex[v1].vexdata);                    //先访问
    p = G->vertex[v1].head;
    visit[v1] = 1;
    push(Qhead,v1);                                         //入队列
    while(Qhead->rear != Qhead->front) {                    //只要队列不为空
        v1 = pop(Qhead);                                    //出队列一个元素
        p = G->vertex[v1].head;                             //记录节点
        while(p) {                                          //依次将次节点后面的节点入队列
            if(p && (visit[p->adjvex] == 0)) {
                printf("%c ",G->vertex[p->adjvex].vexdata);
                visit[p->adjvex] = 1;
                push(Qhead,p->adjvex);
            }
            p = p->next;
        }
    }
}
void CleanVisit() 
{
    int i = 0;
    for(i = 0;i < MAXSIZE;i++) {
        visit[i] = 0;
    }
}
void DFS_traverse(AdjList *G)                       //当图不连通的时候
{
    int i;
    for(i = 1;i <= G->vexnum;i++) {
        if(!visit[i]) {
            DFS(G,i);
        }
    }
}
void DFS(AdjList *G,int v1)                         //深度优先搜索连通子图
{
    ArcNode *p;
    printf("%c ",G->vertex[v1].vexdata);
    visit[v1] = 1;
    p = G->vertex[v1].head;
    while(p) {
        if(visit[p->adjvex] == 0) {
            DFS(G,p->adjvex);
        }
        p = p->next;
    }
}
void ShowAdjList(AdjList *G)                        //将邻接矩阵输出
{
    int i;
    ArcNode *p;
    printf("\n");
    for(i = 1;i <= G->vexnum;i++) {
        printf("%c ",G->vertex[i].vexdata);
        for(p = G->vertex[i].head;p;p = p->next) {
            printf("%d ",p->adjvex);
        }
        printf("\n");
    }

}
void insert(ArcNode **head,int index)
{
    ArcNode *p,*q = NULL,*node;
    node = (ArcNode *)malloc(sizeof(ArcNode));              //创建一个节点
    node->adjvex = index;
    node->next = NULL;
    int flag = 0;
    for(q = *head;q != NULL;q = q->next) {
        if((node->adjvex < q->adjvex) && (q == *head)) {    //当只有一个节点的时候，直接插到头
            node->next = q;
            *head = node;
            return ;
        }
        if((node->adjvex < q->adjvex) && (q != *head)) {
            node->next = q;
            p->next = node;
            return ;
        }
        p = q;
        flag = 1;
    }
    if(flag == 0) {                                         //一个节点都没有的时候
        *head = node;
        return ;
    }
    if(q == NULL) {                                         //目前最大的节点
        p->next = node;
    }

}
void findHead(AdjList *G,char x,int *index)
{
    int i;
    for(i = 1;i <= G->vexnum;i++) {
        if(G->vertex[i].vexdata == x) {
            *index = i;
        }
    }
}
void find_insert(AdjList *G,char x1,char x2)
{
    ArcNode *head1,*head2,*p;
    int index1,index2;
    findHead(G,x1,&index1);                              //找到x1对应的在vertex中的下标
    findHead(G,x2,&index2);
    insert(&G->vertex[index1].head,index2);              //通过比较大小插入相应的位置
    insert(&G->vertex[index2].head,index1);
}
AdjList *build_Graph()
{
    int i,j,k;
    char x1,x2;
    AdjList *G;
    G = (AdjList *)malloc(sizeof(AdjList));
    printf("请输入节点个数和弧数:");
    scanf("%d",&G->vexnum);
    scanf("%d",&G->arcnum);
    printf("请依次输入各节点:");
    for(i = 1;i <= G->vexnum;i++) {
        scanf(" %c",&G->vertex[i].vexdata);
    }
    printf("请输入各节点间关系:");
    for(i = 0;i < G->arcnum; i++) {
        scanf(" %c%c",&x1,&x2);
        find_insert(G,x1,x2);
    }
    return G;
}

int main(int argc,char *argv[])
{
    AdjList *G;
    G = build_Graph();                   //建立邻接表
    ShowAdjList(G);                      //显示邻接表
    DFS(G,1);                            //深度优先遍历连通子图
    printf("\n");
    CleanVisit();                        //清空visit数组
    DFS_traverse(G);                     //深度优先遍历图
    printf("\n");
    CleanVisit();                        //清空visit数组
    BFS(G,1);                            //广度优先遍历
    printf("\n");
    return 0;
}
