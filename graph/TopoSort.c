#include<stdio.h>
#include<stdlib.h>
#include"my_queue.h"
#define MAXVEX 20
#define INFINITY 65535

typedef struct{                   
    int num;                      
	int indegree;
    int outdegree;       
    char name;                  
}Vextype;

typedef struct{  
    int arcs[MAXVEX][MAXVEX];     
    Vextype vex[MAXVEX];          
    int vexnum;                   
    int arcnum;                   
}AdjMatrix;                       

int visited[MAXVEX] = {0};
int indegree[MAXVEX] = {0};

void TopoSort(AdjMatrix *G)
{
    int i,j,k;
    Queue head = init(head);
    for(i = 1;i <= G->vexnum;i++) {
        if(indegree[i] == 0) {
            push(head,i);
        }
    }
    while(head->front != head->rear) {
        j = pop(head);
        printf("%c ",G->vex[j].name);
        for(k = 1;k <= G->vexnum;k++) {
            if(G->arcs[j][k] != INFINITY) {
                indegree[k]--;
                if(indegree[k] == 0) {
                    push(head,k);
                }
            }
        }
    }
    printf("\n");
}
void FindID(AdjMatrix *G)
{
    int i,j;
    for(i = 1;i <= G->vexnum;i++) {
        for(j = 1;j <= G->vexnum;j++) {
            if(G->arcs[j][i] != INFINITY) {
                indegree[i]++;
            }
        }
    }
}
void ShowMatrix(AdjMatrix *G)
{
    int i,j;
    for(i = 1;i <= G->vexnum;i++) {
        for(j = 0;j <= G->vexnum;j++) {
            printf("%5d ",G->arcs[i][j]);
        }
        printf("\n");
    }
}
void CleanVisited()
{
    int i,j;
    for(i = 1;i <= MAXVEX;i++) {
        visited[i] = 0;
    }
}
AdjMatrix * Create()
{
	int i,j,k,weight,vex1,vex2;
    AdjMatrix *G;
	G=(AdjMatrix *)malloc(sizeof(AdjMatrix));
    scanf("%d %d",&G->vexnum,&G->arcnum);
    for(i=1;i<=G->vexnum;i++) {
        for(j=1;j<=G->vexnum;j++) {
            G->arcs[i][j]=INFINITY;        
        }
    }
    for(i=1;i<=G->vexnum;i++) {
        scanf(" %c",&G->vex[i].name);
        G->vex[i].num=i;
    }
    for(k=1;k<=G->arcnum;k++)
    {
        scanf("%d %d",&vex1,&vex2);
        scanf("%d",&weight);
        G->arcs[vex1][vex2]=weight;
    }
    return G;
}

int main(int argc,char *argv[])
{
    int i,j;
    AdjMatrix *G;
    G = Create();
    FindID(G);
    TopoSort(G);
}
