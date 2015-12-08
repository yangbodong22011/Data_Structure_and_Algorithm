/*程序主要是利用矩阵实现了DFS,BFS,Prim以及Kruskal算法，
程序中栈和队列的特殊用法不必纠结,虽然这样不好,甚至会出错,
但是这样的用法来源于"一位高人"!  */

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

int diff(int change[],int n)                       //比较标志数组中元素是不是完全一样了
{
    int i;
    for(i = 1;i < n;i++) {
        if(change[i] != change[i+1]) {
            return 1;
        }
    }
    return 0;

}
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
    int max = 0;                   //因为将矩阵的左下角置为0了，所以列的最大值就是行和列中的最大值
    for(i = 1;i < n;i++) {         //也就是我标志数组的大小
        if(Kru[i].col > max) {
            max = Kru[i].col;
        }
    }
    int change[max];               //change是一个标志数组，
    for(i = max+1;i <= max+max;i++) {
        change[i-max] = i;         //将标志数组初始化成每个相应元素的值加上max的大小，为了避免与max重复
    }
    for(i = 1;i < n;i++){
        if(!diff(change,max)) {     //数组中元素已经全部一样
            break; 
        } 
        else {
            int row = Kru[i].row;   //从结构体中取得数据
            int col = Kru[i].col;
            if(change[row] == change[col]) { //如果标志数组中取出的两个标志相等，那么剔除
                continue;
            }
            printf("(%c %c) ",G->vex[row].name,G->vex[col].name); //选择出合格的边
            int a = change[row];
            int b = change[col];
            for(j = 1;j <= max; j++) {
                if((change[j] == a) || (change[j] == b)) {        //更新标志数组中的值
                    change[j] = i;
                }
            }
        }
        
    }
    printf("\n");
    
}
void Prim(AdjMatrix *G,int start)
{
    struct {
       int adjvex;
       int lowcost;
    }closedge[MAXVEX];
    int i,j,k,m,min;
    closedge[start].lowcost = 0;
    for(i = 1;i <= G->vexnum;i++) {                    //初始化的过程
        if(i != start) {
            closedge[i].adjvex = start;                
            closedge[i].lowcost = G->arcs[start][i];
        }
    }
    for(j = 1;j <= G->vexnum-1;j++) {                  //每次循环找出一个最小值，注意是G->vexnum-1
        min = INFINITY;
        for(k = 1;k <= G->vexnum;k++) {
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min) {
                m = k;
                min = closedge[k].lowcost;
            }
        }
        closedge[m].lowcost = 0;                       //将最小置为0
        printf("(%c %c) ",G->vex[closedge[m].adjvex].name,G->vex[m].name);
        for(i = 1;i <= G->vexnum;i++) {                //将所有值以m的行更新
            if(i != m && G->arcs[m][i] < closedge[i].lowcost) {
                closedge[i].lowcost = G->arcs[m][i];
                closedge[i].adjvex = m;
            }
        }
    }
    printf("\n");
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
        G->arcs[vex2][vex1]=weight;
    }
    return G;
}
void DFS(AdjMatrix *G,int v0)
{
	int *S;
	int j,v,top = -1;
    S=(int *)malloc(sizeof(int));
    S[++top]=v0;
	while(top!=-1) {
		v = S[top--];
		if(!visited[v]) {
			printf("%c ",G->vex[v].name);
			visited[v]=1;
		}
		for(j=1;j<=G->vexnum;j++) {
			if(G->arcs[v][j]!=INFINITY && (!visited[j])) {
				S[++top]=j;
			}
		}
	}
    printf("\n");
}

void BFS(AdjMatrix *G,int v0)
{
	int *Q;
	int rear = 0,front = 0;
	int j,v;
	Q=(int *)malloc(sizeof(int));
	printf("%c ",G->vex[v0].name);
	visited[v0] = 1;
	Q[++rear] = v0;
	while(rear != front) {
		v = Q[++front];
		for(j=1;j<=G->vexnum;j++) {
			if(G->arcs[v][j]!=INFINITY && (!visited[j])) {
	            printf("%c ",G->vex[j].name);
            	visited[j] = 1;
				Q[++rear]=j;
            }
		}
	}
    printf("\n");
}

int main(int argc,char *argv[])
{
    int i,j;
    AdjMatrix *G;
    G=Create();
	//DFS(G,1);
    //CleanVisited();
	//BFS(G,1);
    Prim(G,10);
    Kruskal(G);
}
