## 一：线性表　　
数据结构：　　
```
typedef struct node
{
    int data;
    struct node *next;
}LNode,*LinkList;
```
１：合并两个升序链表或者合并两个升序数组
>思路：依次比较两个链表中的元素，要是小的就放到第三个链表中，然后将此链表后移一个元素，再次于另一个链表比较，循环结束之后要是某个链表还没有结束，就把它整体连接到第三个链表后面。

```
void merge(LinkList head1,LinkList head2,LinkList head3)  
//head1,head2为两个原始链表,head3为合并之后的链表，均带头节点
{
    LinkList p,q,r,s;
    p = head1->next;
    q = head2->next;
    r = head3;
    while(p && q) {
        if(p->data <= q->data) {
            s = (LinkList )malloc(sizeof(LinkList));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
        } else {
            s = (LinkList )malloc(sizeof(LinkList));
            s->data = q->data;
            r->next = s;
            r = s;
            q = q->next;
        }
    }
    if(p == NULL) {　　//如果head1提结束，就把head2连接到head3后面
        r->next = q;
    }
    if(q == NULL) {    //如果head2提结束，就把head1连接到head3后面
        r->next = p;
    }
```  
2：从一个链表第i个位置截取len个元素连接到第二个链表第j个元素位置处，要求使用原始空间　
>思路：找到几个相应的位置，链表二的`j`位置和它的`j+1`位置，链表一的`i`位置和它的`i+len`位置。
然后用`j`连接`i`,用`i+len`连接`j+1`。

```
void cut(LinkList head1,int i,int len,LinkList head2,int j)
{
    int n = 1,k = 1;
    LinkList p,q,r,s;  //p:i+len位置　q:j位置　r:j+1位置　s:i位置
    p = head1->next;
    q = head2->next;
    while(q && n != j) {
        q = q->next;
        n++;
    }
    r = q->next;          //找到j+1位置
    while(p && k != i+len-1) {　 //i+len-1:因为从i位置开始包括i,所以减一
        if(k == i) {
            s = p;　　   //找到i位置
        }
        p = p->next;
        k++;
    }
    q->next = s;　　　 //用j位置连接i位置
    p->next = r;　　　 //用i+len位置连接j+1位置
}
```

## 二：树　　
１：求二叉树的所有节点值的平均值　　
>思路：遍历二叉树统计节点个数和累计的值，然后相除。　　

```
int sum = 0,num = 0,average;
void average(BiTree root)
{
    if(root) {
        sum += root->data;
        num++;
        average(root->lchild);
        average(root->rchild);
    }
}
average = sum/num;
``` 

2：求深度　　

```
int depth(BiTree root)
{
    int hl,hr;
    if(root == NULL) {
        return 0;
    }
    hl = depth(root->lchild);
    hr = depth(root->rchild);
    return hl>hr?hl+1:hr+1;
}
```

3：求叶子节点的路径

```
char way[10];     //保存路径

void printway(BiTree root,char way[],int len)
{
    int i;
    if(root == NULL) {
        return ;
    }
    if(!root->lchild && !root->rchild) {　//如果是叶子节点就输出
        printf("%c : ",root->data);
        for(i = 0;i < len;i++) {
            printf("%c ",way[i]);
        }
        printf("\n");
    }
    way[len++] = root->data;　　　//非叶子节点存路径
    printway(root->lchild,way,len);
    printway(root->rchild,way,len);
}
```

４：二叉树的非递归遍历　

```
/*先序和中序*/
void preorder(BiTree root)
{
    SeqStack *S;
    BiTree p;
    InitStack(S);
    p = root;
    while(p || !IsEmpty(S)) {
        while(p) {
            printf("%c ",p->data);
            Push(S,p);
            p = p->lchild;
        }
        if(!IsEmpty(S)) {
            Pop(S,&p);
            /*printf("%c ",p->data);　放到这里就是中序*/
            p = p->rchild;
        }
    }
}
/*后序*/

void LastOrder(BiTree root)
{
    SeqStack *S;
    BiTree q = NULL;
    InitStack(S);
    while(root || !IsEmpty(S) ) {
        if(root) {
            Push(head,root);
            root = root->lchild;
        }                                  //每次需要先走到最左边
        else {
            root = gettop(head);　　　　　　//取栈顶判断
            if((root->rchild == NULL )|| (root->rchild == q)) { 
        //如果右孩子为空或者右孩子刚被访问过，说明上一个元素的左右孩子都访问过了，那就访问根，
                root = pop(head);
                printf("%c ",root->data);
                q = root;      //这一步保存当前根的位置，以便下一次判断
                root = NULL;   //下一次直接进入else判断
            }
            else {
                root = root->rchild; //否则左边完毕就往右边走。
            }
        }
    }
}
／*层次遍历*
void LevelOrder(BiTree root)
{
    SeqQueue *Q;
    InitQueue(Q);
    BiTree p;
    EnterQueue(Q,root);
    while(!IsEmpty(Q)) {
        DeleteQueue(Q,&p);
        printf("%c ",p->data);
        if(p->lchild) {
             EnterQueue(Q,p->lchild);
        }
        if(p->rchild) {
             EnterQueue(Q,p->rchild);
        }
    }
}
``` 

5：遍历序列对应表　　

|名称　　　 |次序　　　  |次序　　　  |
|-----------|------------|------------|
|二叉树|先序|中序|
|树|先根|后根|
|森林|先序|后序|　　

## 三：图  
1：基本定义　　
- 连通图：无向图中各个顶之间均可以到达  
- 连通分量：无向图中各个极大连通子图　　
- 强连通图：有向图中各个顶点之间均可以到达　　
- 强连通分量：有向图中各个极大连通子图　　
- 生成树：包含连通图中各个顶点的极小连通子图(注意：概念中极小与连通分量相反)
```
数据结构:邻接表
#define MAX 30
typedef struct ArcNode    
{
    int adjvex;        //每个节点代表的数组下标
    int weight;　　　　//权值
    struct ArcNode *next;
}ArcNode;
typedef struct VertexNode
{
    char vexdata;　　　//表头的名称
    ArcNode *head;     //head指针指向其后的链表
}VertexNode;
typedef struct
{
    VertexNode vertex[MAXVEX];
    int vexnum;       //顶点数
    int arcnum;       //弧数
}
```
2：判断一个图是不是无向图？若不是，求连通分量的个数。　
>思路：由于无向图除了由`不同的部分`(好几块)组成的时候是不连通的，只有一部分的时候一定是连通的，
所以我们调用`travels`,看`travels`中`DFS`调用次数就知道多少个连通分量。


```
int num = 0;  //统计连通分量的个数
int visit[MAXSIZE] = {0};  //访问数组首先置为0,表示全部都没访问过
void DFS(AdjList *G,int v1)
{
    ArcNode *p;
    visit[v1] = 1;  //标记已经访问过
    p = G->vertex[v1].head;
    while(p) {
        if(visit[p->adjvex] == 0) {
            DFS(G,p->adjvex);
        }
        p = p->next;
    }
}
void DFS_travels(AdjList *G)
{
    int i;
    for(i = 1;i <= G->vexnum;i++) {
        if(!visit[i]) {
            num++;             //每调用一次让num++;
            DFS(G,i);
        }
    }
}
if(num == 1) 　//图是连通的，连通分量为1  
if(num > 1)    //图不连通，连通分量为num　
```

３：因为`Prim`算法选择的是点，每次选择一个到当前生成树中最短路径的点，所以它比较适合`稠密图`(顶点少，边多)，但是`Kruskal`算法每次选择一条边，所以它适合`稀疏图`(顶点多，边少)。　　　　

４：拓扑排序，Kruskal和Prim等具体实现代码：
[点这里](https://github.com/yangbodong22011/Data_Structure_and_Algorithm/tree/master/graph)　　


## 四：排序

|  名称   |平均   |最坏   |辅助   |稳定   |
|-----|-------|-------|-------|-------|
|冒泡排序|O(n^2)|O(n^2)|O(1)|稳定|
|插入排序|O(n^2)|O(n^2)|O(1)|稳定|
|交换排序|O(n^2)|O(n^2)|O(1)|不稳定|
|选择排序|O(n^2)|O(n^2)|O(1)|不稳定|
|希尔排序|O(nlogn)||O(1)|稳定|
|归并排序|O(nlogn)|O(nlogn)|O(1)|稳定|
|快速排序|O(nlogn)|O(n^2)|O(nlogn)|不稳定|
|堆排序|O(nlogn)|O(nlogn)|O(1)|不稳定|

