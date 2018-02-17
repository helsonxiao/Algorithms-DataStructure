#include "Node.c"
#include <stdio.h>

Status GetElem (LinkList L, int i , ElemType *e)
{
    int j = 1;
    LinkList p;
    p = L->next; // first node
    while (p && j<i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

int main()
{
    LinkList list;
    Node n0, n1, n2;
    list = &n0;
    n0.next = &n1;

    n1.data = 1;
    n1.next = &n2;
    n2.data = 2;
    n2.next = NULL;

    ElemType e;
    int index = 2;
    GetElem(list, index, &e);
    printf("%d", e);
}
