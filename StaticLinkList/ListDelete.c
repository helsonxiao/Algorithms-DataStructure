#include "StaticLinkList.c"

Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }
    for (k = 1; k < i; k++)
    {
        j = L[k].cur; // elem to be deleted
    }
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}
