// Straight Insertion Sort
#include "struct.c"

void InsertSort (SqList *L)
{
    int i, j;
    for (i = 2; i < L->length; i++)
        if (L->r[i-1] > L->r[i])
        {
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j+1] = L->r[j];
            L->r[j+1] = L->r[0];
        }
}

int main()
{
    SqList L;
    int r[] = {0, 5, 3, 4, 6, 2};
    int length = 6;
    L.length = length;
    int i;
    for (i = 0; i < L.length; i++)
        L.r[i] = r[i];

    InsertSort(&L);
    return 0;
}
