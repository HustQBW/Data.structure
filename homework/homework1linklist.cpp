#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000

typedef float datatype;

typedef struct Node
{
    datatype data;
    Node *next;
} List;

List *init()
{
    List *L = (List *)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

int length(List *L)
{
    List *p = L;
    int j = 0;
    while (p)
    {
        p = p->next;
        ++j;
    }
    return j;
}


List *find(datatype x, List *L)
{
    List *p = L;
    while ( p!=NULL && p->data != x)
    {
        p = p->next;
    }
    return p;
}

List *findkth(int k, List *L)
{
    List *p = L;
    int i = 1;
    while (p != NULL && i < k)
    {
        p = p->next;
        ++i;
    }

    if ( i == k )
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

List * insert(List *L, int i, datatype x)
{
    List *p, *s;

    if (i==1)
    {
        s = (List *) malloc( sizeof(List) );
        s->data = x;
        s->next = L;
        return s;
    }

    p = findkth(i-1, L);
    if ( NULL == p )
    {
        printf("out of range\n");
        return NULL;
    }
    else
    {
        s = (List *) malloc( sizeof(List) );
        s->data = x;
        s->next = p->next;
        p->next = s;
        return L;
    }
}

void print_list(List *L)
{
    List *p = L;
    while (NULL != p)
    {
        printf("%f ", p->data);
        if (p->next != NULL)
        {
            printf("-> ");
        }
        p = p->next;
    }

    printf("\n");
}

List* inverse(List *L)
{
    List *p = L;
    List *q = NULL;
    List *head = NULL;

    while (p)
    {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }

    return head;
}
List *Delete(List *L,int i)
{
    List *p,*s;
    if(i==1)
    {
        s=L;
        if(L!=NULL)
        {
            L=L->next;
            return L;
        }
        else
            return NULL;
    }
    p=findkth(i-1,L);
    if(p==NULL)
    {
        printf("the deleted node is out of range!\n");
        return NULL;
    }
    else if(p->next==NULL)
    {
        printf("node does not exist!\n");
        return NULL;
    }
    else
    {
        s=(List *) malloc(sizeof(List));
        s=p->next;
        p->next=s->next;
        free(s);
        return L;
    }

}
int main()
{
    int i = 0;
    datatype x = 0;
    List* px;

    List* L = init();
    for (i=0; i<5; ++i)
    {
        L=insert(L, i+1, i*i);
    }
    printf("list len = %d\n", length(L) );
    print_list(L);

    L=Delete(L,1);
    print_list(L);

    return 1;
}
