#include <stdio.h>
#include <stdlib.h>
#include "Node.c"

Status ListInsert (LinkList *L, int i, ElemType e)
{
    int j = 1;
    LinkList p,s;
    p = *L;
    while (p && j<i) // 寻找第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    if (!p || j>i)
    {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node)); // 请求分配一个 Node 字节大小的内存地址
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

int main()
{
    LinkList list;
    Node n0, n1, n2;
    list = &n0;
    n0.next = &n1; // head node only has pointer area

    n1.data = 1;
    n1.next = &n2;
    n2.data = 2;
    n2.next = NULL;

    ElemType e = 5;
    int index = 2;
    ListInsert(&list, index, e);
    
    int j = 1;
    LinkList n;
    n = list->next;
    while (j < index)
    {
        n = n->next;
        j++;
    }
    printf("%d", n->data);
}
