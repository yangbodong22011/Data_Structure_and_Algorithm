/*************************************************************************
	> File Name: my_queue.h
	> Author: YangBodong
	> Mail: ybd@xiyoulinux.org
	> Created Time: Fri 27 Nov 2015 16:04:31 CST
 ************************************************************************/

#ifndef _MY_QUEUE_H
#define _MY_QUEUE_H
#define MAXSIZE 30

typedef struct ArcNode
{
    int adjvex;               //节点的下标位置
    int weight;               //节点的权值
    struct ArcNode *next;
}ArcNode;
typedef struct VertexNode
{
    char vexdata;             //头数据
    ArcNode * head;           //指针
}VertexNode;
typedef struct
{
    VertexNode vertex[MAXSIZE];//20个链表 
    int vexnum;                //节点数
    int arcnum;                //弧数，也就是关系数
}AdjList;

typedef struct queue
{
    int data[MAXSIZE];
    int front;
    int rear;
}queue,*Queue;

Queue init()
{
    Queue Qhead;
    Qhead = (Queue)malloc(sizeof(queue));
    Qhead->front = -1;
    Qhead->rear = -1;
}
void push(Queue Qhead,int v1) 
{
    Qhead->front++;
    Qhead->data[Qhead->front] = v1;
}
int pop(Queue Qhead)
{
    Qhead->rear++;
    return Qhead->data[Qhead->rear];
}



#endif
