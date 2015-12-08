/*将Kruskal算法的标志数组初始化1到n,用父节点判断两个节点是否在一起*/

#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 20
#define INFINITY 65535

typedef struct{                   
    int num;                      
	int indegree,outdegree;       
    char name;                  
}Vextype;

typedef struct{  
    int arcs[MAXVEX][MAXVEX];     
    Vextype vex[MAXVEX];          
    int vexnum;                   
    int arcnum;                   
}AdjMatrix;                       

int visited[MAXVEX] = {0};

void Kruskal(AdjMatrix *G)
{
    struct KNode{                              
        int weight;    //权值
        int row;       //行坐标
        int col;       //列坐标
    }Kru[MAXVEX],KNode;
    int i,j,k,m,row,col,n = 1;
    for(i = 1;i <= G->vexnum;i++) {    //为了便于寻找之后剔除重复，将矩阵左下角置为0
        for(j = 1;j <= i;j++) {
            G->arcs[i][j] = INFINITY;
        }
    }
    for(i = 1;i <= G->vexnum;i++) {    //将矩阵中的信息一次存到结构体数组中
        for(j = 1;j <= G->vexnum;j++) {
            if(G->arcs[i][j] != INFINITY) {
                Kru[n].weight = G->arcs[i][j];
                Kru[n].row = i;
                Kru[n].col = j;
                n++;                   //n的数量为结构体总数量加1
            }
        }
    }
    for(i = 1;i < n;i++) {             //对结构体进行排序
        for(j = 1;j < n-i;j++) {
            if(Kru[j].weight > Kru[j+1].weight) {
                struct KNode temp;
                temp = Kru[j];
                Kru[j] = Kru[j+1];
                Kru[j+1] = temp;
            }
        }
    }
    int change[G->vexnum];               //change是一个标志数组，
    for(i = 1;i <= G->vexnum;i++) {
        change[i] = i;  
    }
    for(i = 1;i < n;i++){
        int row = Kru[i].row;            
        int col = Kru[i].col;
        int a = row,b = col;
        while(change[row] != row) {      //每次循环去找父亲节点
            row = change[row];
        }
        while(change[col] != col) {
            col = change[col];
        }
        if(row != col) {                 //如果它们两个的父亲不相等
            printf("(%c %c) ",G->vex[a].name,G->vex[b].name);
            change[row] = col;
        }
    }
    printf("\n");
    
}

