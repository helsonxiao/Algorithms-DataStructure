#include <stdio.h>
#include "Node.c"

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList p;
    p = *L; // 工作指针存放头结点地址
    int j = 1;
    while (p && j<i) // 获取第 i-1 个元素
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j>i)
    {
        return ERROR;
    }
    *e = p->next->data;
    p->next = p->next->next; // 删除 i 的指针
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

    ElemType e;
    int index = 2;
    ListDelete(&list, index, &e);

    printf("%d", e);
}
