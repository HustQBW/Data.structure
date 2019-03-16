// Example program
#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000

typedef float datatype;

typedef struct Node
{
    datatype data;
    Node *next;
} List;

List *Delete( int  i, List *PtrL ) {
	List  *p, *s;
	if ( i == 1 ) {   /* 若要删除的是表的第一个结点 */
		s = PtrL;    /*s指向第1个结点*/
		if (PtrL!=NULL)  PtrL = PtrL->Next; /*从链表中删除*/
		else return NULL;
		free(s);                /*释放被删除结点 */
		return PtrL;
	}
	p = FindKth( i-1, PtrL ); /*查找第i-1个结点*/
	if ( p == NULL ) {
		printf(“第%d个结点不存在”, i-1);     return NULL;
       } else  if ( p->Next == NULL ){
		printf(“第%d个结点不存在”, i);      return NULL;
       } else  {
		s = p->Next;             /*s指向第i个结点*/
		p->Next = s->Next;       /*从链表中删除*/
		free(s);               /*释放被删除结点 */
		return PtrL;
	}
}

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

int main()
{
    int i = 0;
    datatype x = 0;
    List* px;

    List* L = init();
    for (i=0; i<5; ++i)
    {
        insert(L, i+1, i*i);
    }
    printf("list len = %d\n", length(L) );
    print_list(L);

    insert(L, 3, 300);
    print_list(L);

    x = 9;
    px = find(x, L);
    if (px)
    {
        printf("%f is found, its next node is %f\n", px->data, px->next->data );
    }
    else
    {
        printf("%f is not found\n", x);
    }

    // printf("inverse it: ");
    // List* iL = inverse(L);
    // print_list(iL);

    return 1;
}
