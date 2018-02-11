#include "SqList.c"
#include <stdio.h>

Status ListDelete(SqList *L, int i)
{
    if (L->length == 0)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    if (i < L->length)
    {
        for (int k = i; k <= L->length - 2; i++)
        {
            L->data[k - 1] = L->data[k];
        }
    }

    L->length--;
    return OK;
}

int main()
{
    SqList list;
    list.length = 3;
    for (int i = 0; i < list.length; i++)
    {
        list.data[i] = i;
    }

    ElemType e;
    int t = ListDelete(&list, 2);
    printf("%d\n", list.length); // list.length == 2
    for (int i = 0; i < list.length; i++)
    {
        printf("%d\n", list.data[i]);
    }
}
