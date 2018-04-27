#include "struct.c"

void BubbleSort2 (SqList *L)
{
    int i, j;
    int flag = 1;

    for (i = 1; i < L->length && flag; i++)
    {
        flag = 0;
        for (j = L->length-1; j >= i; j--)
        {
            if (L->r[j] > L->r[j+1])
            {
                swap(L, j, j+1);
                flag = 1;
            }
        }
    }
}