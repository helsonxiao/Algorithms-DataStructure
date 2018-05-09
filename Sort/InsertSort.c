// Straight Insertion Sort
#include "struct.c"

void InsertSort (SqList *L)
{
    int i, j, tmp;
    for (i = 1; i < L->length; i++)
        if (L->r[i-1] > L->r[i])
        {
            tmp = L->r[i];
            for (j = i - 1; L->r[j] > tmp; j--)
                L->r[j+1] = L->r[j];
                
            L->r[j+1] = tmp;
        }
}

// int main()
// {
//     SqList L = {
//         {5, 3, 4, 6, 2},
//         5
//     };

//     InsertSort(&L);

//     int i;
//     for (i = 0; i < L.length; i++)
//         printf("%d ", L.r[i]);
// }
