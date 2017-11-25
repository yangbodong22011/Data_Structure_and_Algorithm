/*************************************************************************
	> File Name: huffmantree1.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Nov 2015 08:42:01 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
#define M 2*N
#define MAX 65535

typedef struct 
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}Node,huffmanTree[M];

void crthuffmanTree(huffmanTree,int [],char [],int);
void select1(huffmanTree,int,int *,int *);
char *getcode(huffmanTree,char,int,int [],char []);

char *getcode(huffmanTree ht,char x,int n,int w[],char s[]) 
{
    char str[20],str2[20];
    int i,j,k,t = 0;
    int m = 2*n-1;
    for(i = 1;i <= n;i++) {
        if(x == s[i]) {
            for(j = 1;j <= m;j++) {
                if(w[i] == ht[j].weight) {
                    while(ht[j].parent != 0) {
                        k = j;
                        j = ht[j].parent;
                        if(ht[ht[j].lchild].weight == ht[k].weight) {
                            str[t++] = '0';         
                        }
                        if(ht[ht[j].rchild].weight == ht[k].weight) {
                            str[t++] = '1';
                        }         
                    }
                }
            }
        }
    }
    for(i = t-1,j = 0;i != -1;i--,j++) {
        str2[j] = str[i];
    }
    return str2;
}
void select1(huffmanTree ht,int n,int *s1,int *s2)
{
    int i;
    int s3,s4; //s3表示第一小,s4表示第二小
    s3 = s4 = MAX;
    for(i = 1;i <= n;i++) {
        if(ht[i].parent == 0) {
            if(ht[i].weight < s3) {
                s4 = s3;
                *s1 = *s2;
                s3 = ht[i].weight;
                *s2 = i;
            }
            if((ht[i].weight > s3) && (ht[i].weight < s4)) {
                s4 = ht[i].weight;
                *s1 = i;
            }
        }
    }
}
void crthuffmanTree(huffmanTree ht,int w[],char s[],int n)
{
    char ch;
    int s1,s2;   
    int m,i,j;
    m = 2*n - 1;
    char *code[n];
    for(i = 1;i <= n;i++) {
        ht[i].weight = w[i];
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
    }
    for(i = n+1;i <= m;i++) {
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
    }
    for(i = n+1;i <= m;i++) {
        select1(ht,i-1,&s1,&s2);
        ht[i].weight = ht[s1].weight+ht[s2].weight;
        ht[i].lchild = s2;
        ht[i].rchild = s1;
        ht[s1].parent = i;
        ht[s2].parent = i;
    }
    printf("根据建立的哈夫曼树得到字符对应编码如下:\n");
    for(i = 1;i <= n; i++) {
        code[i] = getcode(ht,s[i],n,w,s);
        printf("%c:%s\n",s[i],code[i]);
    }
    setbuf(stdin,0);
    printf("请输入要编码的字符串:");
    while((ch = getchar()) != '\n') {
        for(i = 1;i <= n;i++) {
            if(ch == s[i]) {
                printf("%s",code[i]);
            }
        }
    }
    printf("\n");

    
}

int main(int argc,char *argv[])
{
    int i,n;
    huffmanTree ht;
    int w[20];
    char s[20];
    printf("请输入编码个数：");
    scanf("%d",&n);
    printf("请依次输入字符和相应的权值:");
    for(i = 1;i <= n;i++) {
        scanf(" %c",&s[i]);
        scanf("%d",&w[i]);
    }
    crthuffmanTree(ht,w,s,n);
    /*for(i = 1;i <= 7;i++) {
        printf("%-2d %-2d %-2d %-2d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
    }*/
}
