/*************************************************************************
	> File Name: string.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Nov 2015 16:47:22 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char *StrAssign(char *);
void StrCopy(char **,char *);
void StrLength(char *,int *);
char *StrInsert(char *,int,char *);
char *StrDelete(char *,int,int);
int StrCompare(char *,char *);
void StrCat(char *,char *);
void SubString(char **,char *,int,int);
int StrIndex(char *,int,char *);
void StrReplace(char *,char *,char *);

void StrReplace(char *S,char *T,char *R)
{
    int num,numt;
    StrLength(T,&numt);
    char *W;
    while((num = StrIndex(S,0,T)) != -1)
    {
        W = StrDelete(S,num,numt);
        S = StrInsert(W,num,R);
    }
    printf("%s\n",S);
}
int StrIndex(char *S,int pos,char *T)
{
    int i,j,s;
    int num1,num2;
    StrLength(S,&num1);
    StrLength(T,&num2);
    for(i = pos;i < num1;i++) {
        for(s = i,j = 0;j < num2;j++,s++) {
            if(S[s] != T[j]) {
                break;
            }
        }
        if(j == num2) {
            return s-num2;
        }
    }
    return -1;
}
void SubString(char **T,char *S,int pos,int len)
{
    char data[len];
    int i,j = 0;
    for(i = pos;i < pos+len;i++) {
        data[j++] = S[i];
    }
    data[j] = '\0';
    *T = data;
}
void StrCat(char *S,char *T)
{
    int i,num,j = 0;
    StrLength(S,&num);
    char ch;
    char R[100];
    for(i = 0;i < num;i++) {
        R[i] = S[i];
    }
    while((ch = T[j++]) != '\0') {
        R[i++] = ch;
    }
    R[i] = '\0';
    printf("%s\n",R);

}
int StrCompare(char *S,char *T)
{
    int i,num1,num2;
    StrLength(S,&num1);
    StrLength(T,&num2);
    if(num1 < num2) {
        for(i = 0;i < num1;i++)
        {
            if(S[i] != T[i]) {
                return S[i]-T[i];
            }
        }
        return -1;
    }
    if(num1 > num2) {
        for(i = 0;i < num2;i++)
        {
            if(S[i] != T[i]) {
                return S[i]-T[i];
            }
        }
        return 1;
    }
    if(num1 == num2) {
        for(i = 0;i < num2;i++)
        {
            if(S[i] != T[i]) {
                return S[i]-T[i];
            }
        }
        return 0;
    }
}
char *StrDelete(char *S,int pos,int len)
{
    int i = 0,j = 0,num;
    StrLength(S,&num);
    char *R = (char *)malloc(100 * sizeof(char)); 
    char ch;
    for(i = 0;i < pos;i++) {
        R[i] = S[i];
    }
    j = pos+len;
    while((ch = S[j++]) != '\0') {
        R[i++] = ch;
    }
    R[i] = '\0';
    return R;
    
}
char *StrInsert(char *S,int pos,char *T)
{
    char ch;
    int i = 0,j = 0,k = 0;
    char *R = (char *)malloc(100 * sizeof(char)); 
    //此处是直接定义数组还是malloc呢，这还是有点讲究的，因为声明数组的话是在栈上，
    //当这个函数结束之后，栈的空间会被释放掉，也就是你如果将数组名return回去，那么如果那块内存空间目前没有人使用的话，你用返回
    //的数组名还是正常的，但是如果这块内存空间万一被别人使用，那么这将导致段错误，要是这块内存使用malloc开辟的，那么它就存在于堆
    //上，这样即使函数结束，也不影响。
    for(j = 0;j < pos;j++) {
        R[i++] = S[j];
    }
    while((ch = T[k++]) != '\0') {
        R[i++] = ch;
    }
    while((ch = S[j++]) != '\0') {
        R[i++] = ch;
    }
    R[i] = '\0';
    return R;
}
void StrLength(char *S,int *ret)
{
    char ch;
    int i = 0;
    while((ch = S[i++]) != '\0');
    *ret = i-1;
}
void StrCopy(char **S,char *chars)
{
    *S = chars;   
}
char *StrAssign(char *chars)
{
    char *S;
    S = chars;
    return S;
}


int main(int argc,char *argv[])
{
    int ret;
    char *T = "bo";
    char *S = "yangbodongbodongbodongbodong";
    char *R = "XXX";
    char *chars;
    S = StrAssign(chars);  //构建一个串S
    StrCopy(&S,chars);     //将chars串拷贝给S
    StrLength(S,&ret);     //ret的值就是数组的长度
    StrInsert(S,4,T);      //在串S的第四个字符前插入串T
    StrDelete(S,4,2);      //从串S中第四个字符开始删除两个字符。犯了一个错
                           //是不能将字符串当做数组来改变它的位置的元素值，可以获取值，但是不能将值改变,因为这是常量。
    ret = StrCompare(S,T); //比较两个字符串的大小
    StrCat(S,T);           //将字符串T连接到串S上
    SubString(&T,S,4,6);   //在S串中从4号元素处截取6个元素并且将它赋值给T
    ret = StrIndex(S,2,T); //从主串S串的下标为2开始，遇到T串完全匹配就返回第一个下标          
    StrReplace(S,T,R);     //将主串S中所有的串T都用R串替换掉。
    return 0;
}
