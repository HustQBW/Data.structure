#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    int data;
    struct node *next;
}node;
void josephu(node *head,int m);
void main()
{
    node *p=NULL;
    node *s=NULL;
    node *head=NULL;
    int n;
    printf("please input the number of people : n= \n");
    scanf("%d",&n);
    int m;
    printf("please input the max out number : m= \n");
    scanf("%d",&m);
    int* a;
    a=(int*)malloc(sizeof(int)*n);
    printf("please input the data \n");
    for(int j=0;j<n;j++)
        scanf("%d",&a[j]);
    int i;
    for(i=1;i<=n;i++)    //构建单循环链表
    {
        s=(node*)malloc(sizeof(node));
        s->num=n-i+1;
        s->data=a[n-i];
        s->next=NULL;
        if(i==1)
        {
            p=s;
        }
        s->next=head;
        head=s;
    }
    p->next=head;
    josephu(head,m);
}
void josephu(node *head,int m)
{
    int i;
    node *p=NULL;
    node *q=NULL;
    p=head;
    while(p->next!=p)
    {
        for(i=1;i<m;i++)
        {
            q=p;
            p=p->next;
        }
        printf("出队列的是%d号\n",p->num);
        m=p->data;
        q->next=p->next;
        p=q->next;
    }
    printf("最后出列的是%d号\n",p->num);
}
