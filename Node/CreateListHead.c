#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Node.c"

void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node)); // 请求分配一个内存地址
    (*L)->next = NULL;
    for (i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

int main()
{
    int n = 2;
    LinkList list;
    CreateListHead(&list, n);
    LinkList p;
    p = list;
    int j = 0;
    while (j<n)
    {
        p = p->next;
        printf("%d\n", p->data);
        j++;
    }
}
