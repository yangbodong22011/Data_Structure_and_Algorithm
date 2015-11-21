/*************************************************************************
	> File Name: three_array.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Nov 2015 17:38:24 CST
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 100

typedef struct
{
    int row;    //相当于x 
    int col;    //相当于y
    int value;  //求值
}Triple;

typedef struct
{
    Triple data[MAXSIZE]; //定义大小为100,表示稀疏矩阵中最多存在100个有效元素
    int rows;             //稀疏矩阵的总行数
    int cols;             //稀疏矩阵的总列数
    int numbers;          //非零元素的总数
}TSMatrix;

void InitTSM(TSMatrix *);
void ShowMatrix(TSMatrix);
void Transpose_rowsadd(TSMatrix *);
void Transpose_coladd(TSMatrix *);
void Transpose_once(TSMatrix *);
void AddMatrix(TSMatrix *,TSMatrix *);
void MultiMatrix(TSMatrix,TSMatrix);
void ChangeToMatrix(TSMatrix TSM,int [TSM.rows+1][TSM.cols+1]);

void ChangeToMatrix(TSMatrix TSM,int matrix[TSM.rows+1][TSM.cols+1])
{
    int i,j; 
    for(i = 1;i <= TSM.rows;i++) {
        for(j = 1;j <= TSM.cols;j++) {
            matrix[i][j] = 0;
        }
    }
    for(i = 1;i <= TSM.numbers;i++) {
        matrix[TSM.data[i].row][TSM.data[i].col] = TSM.data[i].value;
    }
}
void MultiMatrix(TSMatrix TSM1,TSMatrix TSM2)
{
    if(TSM1.cols != TSM2.rows) {
        printf("矩阵格式不匹配\n");
        return ;
    }
    int i,j,x = 0,k = 1,numbers = 0,s;
    int matrix1[TSM1.rows+1][TSM1.cols+1];
    int matrix2[TSM2.rows+1][TSM2.cols+1];
    TSMatrix TSM3;
    TSM3.rows = TSM1.rows;
    TSM3.cols = TSM2.cols;
    TSM3.numbers = 0;
    ChangeToMatrix(TSM1,matrix1);                   //将三元组恢复成矩阵
    ChangeToMatrix(TSM2,matrix2);
    for(i = 1;i <= TSM1.rows;i++) {                 //第一个矩阵的行循环
        for(s = 1;s <= TSM2.cols;s++) {             //第二个矩阵的列循环
            for(j = 1;j <= TSM1.cols;j++) {         //分别相乘
                x += matrix1[i][j] * matrix2[j][s];
            }
            if(x != 0) {                            //若不为0就保存到三元组中
                TSM3.numbers++;
                TSM3.data[k].row = i;
                TSM3.data[k].col = s;
                TSM3.data[k].value = x;
                k++;
            }
            x = 0;                                  //注意要将x置0
        }
    }
    printf("---相乘之后的矩阵---");
    ShowMatrix(TSM3);
}
void AddMatrix(TSMatrix *T1,TSMatrix *T2)
{
    int i;
    if(T1->cols != T2->cols || T1->rows != T2->rows) {
        printf("矩阵格式不匹配\n");
        return ;
    }
    for(i = 1;i <= T1->rows+T2->rows;i++) {
        if(T1->data[i].row == T2->data[i].row && T1->data[i].col == T2->data[i].col) {  //行列匹配就相加
            //T1->data[i].value = T1->data[i].value + T2->data[i].value;
            T1->data[i].value = T1->data[i].value - T2->data[i].value;
        }
        else {
            T1->data[i+T1->rows].row = T2->data[i].row;            //如果不匹配就放到第一个三元组后面
            T1->data[i+T1->rows].col = T2->data[i].col;
            T1->data[i+T1->rows].value = T2->data[i].value;
            T1->numbers = i+T1->rows;
        }
    }
}
void Transpose_once(TSMatrix *T)
{
    int i,j,k;
    TSMatrix S;
    int num[MAXSIZE];
    int position[MAXSIZE];
    S.cols = T->cols;
    S.rows = T->rows;
    S.numbers = T->numbers;
    for(i = 1; i <= T->cols;i++) {      //num数组实际上相当于桶排的原理，反映了从小到大col为不同数值的个数
        num[i] = 0;
    }
    for(i = 1; i <= T->numbers;i++) {
        num[T->data[i].col]++;
    }
    position[1] = 1;
    for(i = 2;i <= T->cols;i++) {
        position[i] = position[i-1] + num[i-1]; //因为col有重复的，这样就可以确定目前我下一个col值的位置应该跨越
        //上一个col值的总个数
    }
    for(j = 1;j <= T->numbers;j++) {
        k = T->data[j].col;                //依次处理每一个col值
        i = position[k];                   //根据position数组确定此col值定位之后的位置，
        S.data[i].row = T->data[j].col;    //改变相应的值
        S.data[i].col = T->data[j].row;
        S.data[i].value = T->data[j].value;
        position[k]++;                     //若有重复col值，下一次应该得到的position值是上一次加一。
    }

}
void Transpose_coladd(TSMatrix *T)
{
    TSMatrix S;
    int i,j = 1,k,temp;
    S.cols = T->rows;
    S.rows = T->cols;
    S.numbers = T->numbers;
    for(k = 1;k <= T->cols;k++) {
        for(i = 1;i <= T->numbers;i++) {                 //从小到大每次找出一个col值的所有个数依次存S中。
            if(T->data[i].col == k) {                
                S.data[j].row = T->data[i].col;
                S.data[j].col = T->data[i].row;
                S.data[j].value = T->data[i].value;
                j++;
            }
            if(j > T->numbers) {
                break;
            }
        }
    }
    for(i = 1;i <= S.numbers;i++) {
        printf("%d %d %d\n",S.data[i].row,S.data[i].col,S.data[i].value);
    }
    ShowMatrix(S);

}
void Transpose_rowsadd(TSMatrix *T)               //行增加，直接交换即可，但是之后操作不方便
{
    int i,temp;
    temp = T->rows;
    T->rows = T->cols;
    T->cols = temp;
    for(i = 1;i < T->numbers+1;i++) {
        temp = T->data[i].row;
        T->data[i].row = T->data[i].col;
        T->data[i].col = temp;
    }
    for(i = 1;i < T->numbers+1;i++) {
        printf("%d %d %d\n",T->data[i].row,T->data[i].col,T->data[i].value);
    }

}
void ShowMatrix(TSMatrix TSM)
{
    int i,j;
    int matrix[TSM.rows+1][TSM.cols+1];
    for(i = 1;i <= TSM.rows;i++) {
        for(j = 1;j <= TSM.cols;j++) {
            matrix[i][j] = 0;
        }
    }
    for(i = 1;i <= TSM.numbers;i++) {
        matrix[TSM.data[i].row][TSM.data[i].col] = TSM.data[i].value;
    }
    printf("\n");
    for(i = 1;i <= TSM.rows;i++) {
        for(j = 1;j <= TSM.cols;j++) {
            printf("%-4d",matrix[i][j]);
        }
        printf("\n");
    }

}
void InitTSM(TSMatrix *T)
{
    int i;
    printf("请输入总元素个数:");
    scanf("%d",&T->numbers);
    printf("请输入总的行数:");
    scanf("%d",&T->rows);
    printf("请输入总列数:");
    scanf("%d",&T->cols);
    for(i = 1;i <= T->numbers;i++) {
        printf("请依次输入row,col,value:");
        scanf("%d %d %d",&T->data[i].row,&T->data[i].col,&T->data[i].value);
    }
}

int main(int argc,char *argv[])
{
    int i,j;
    TSMatrix TSM1,TSM2;
    InitTSM(&TSM);             //初始化矩阵
    ShowMatrix(TSM);           //通过三元组显示矩阵
    Transpose_rowsadd(&TSM);   //行递增转置
    Transpose_coladd(&TSM);    //列递增转置算法
    Transpose_once(&TSM);      //一次定位快速转置
    InitTSM(&TSM1);
    ShowMatrix(TSM1);
    InitTSM(&TSM2);
    ShowMatrix(TSM2);
    AddMatrix(&TSM1,&TSM2);      //矩阵的加法和减法
    MultiMatrix(TSM1,TSM2);       //矩阵的乘法
    return 0;
}
