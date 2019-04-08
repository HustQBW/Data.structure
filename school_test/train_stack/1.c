#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;
int InitStack(SqStack *pS)
{
    pS->base=(int *)malloc(Maxsize*sizeof(int));
    pS->top=pS->base;
    pS->stacksize=Maxsize;
    return 1;
}
int Push(SqStack *pS,int e)
{
    *(pS->top)++=e;
    return 1;
}
int Pop(SqStack *pS,int *e)
{
    if(pS->top==pS->base)return 0;
    *e=*--pS->top;
    return 1;
}
int StackEmpty(SqStack *pS)
{
    if(pS->top==pS->base)return 1;
    else return 0;
}
void print(int b[],int n)
{
    int k;
    for(k=0;k<n;k++)
        printf("%d\t",b[k]);
    printf("\n");
}
void f(SqStack *pS,int a[],int b[],int p,int q,int n)
{
    if(p<n)
    {
        Push(pS,a[p]);
        f(pS,a,b,p+1,q,n);
        Pop(pS,&b[q]);
    }
    if(!StackEmpty(pS))
    {
        Pop(pS,&b[q]);
        f(pS,a,b,p,q+1,n);
        Push(pS,b[q]);
    }
    if(q>=n&&StackEmpty(pS))print(b,n);
}
void main()
{
    int i,n;
    int a[Maxsize],b[Maxsize];
    printf("please input the number n = \n");
    scanf("%d",&n);
    SqStack S;
    InitStack(&S);
    for(i=0;i<n;i++)
        a[i]=i+1;
    printf("the number is \n");
    f(&S,a,b,0,0,n);
}
