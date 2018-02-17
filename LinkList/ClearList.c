#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Node.c"

void CreateListTail(LinkList *L, int n)
{
    LinkList p, rear;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node)); // 请求分配一个内存地址
    rear = *L;

    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
}

Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = *L;
    while (p->next)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

int main()
{
    LinkList list;
    int n = 5;
    CreateListTail(&list, n);
    LinkList p;
    p = list;
    int j = 0;
    while (j < n)
    {
        p = p->next;
        printf("%d\n", p->data);
        j++;
    }

    ClearList(&list);
    j = 0;
    while (j < n)
    {
        if (p->next)
        {
            p = p->next;
            printf("%d\n", p->data);
        }
        else
        {
            printf("no data\n");
        }
        j++;
    }
}