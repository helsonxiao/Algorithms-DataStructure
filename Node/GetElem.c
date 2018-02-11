#include "Node.c"
#include <stdio.h>

Status GetElem (LinkList L, int i , ElemType *e)
{
    int j = 1;
    LinkList p;
    p = L->next;
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
    n0.data = 0;
    n0.next = &n1;
    n1.data = 1;
    n1.next = &n2;
    n2.data = 2;
    n2.next = NULL;
    list = &n0;

    int e;
    int t = GetElem(list, 2, &e);
    printf("%d\n%d", t, e);
}
