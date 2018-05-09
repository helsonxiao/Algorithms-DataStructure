#include <stdio.h>
#include "InsertSort.c"
#define MAX_LENGTH_INSERT_SORT 7

int Partition(SqList *L, int low, int high)
{
    int pivotkey = L->r[low];
    while (low < high)
    {
        // find number smaller than pivot
        while (low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high];

        // find number bigger than pivot
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low];
    }
    L->r[low] = pivotkey; // L->r[high] = pivotkey;
    return low; // return high;
}

void QSort(SqList *L, int low, int high)
{
    int m = low + (high - low) / 2;
    if (L->r[low] > L->r[high])
    {
        swap(L, low, high);
    }
    if (L->r[m] > L->r[high])
    {
        swap(L, m, high);
    }
    if (L->r[low] < L->r[m])
    {
        swap(L, m, low);
    }

    int pivot;
    if ((high-low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition(L, low, high);
            QSort(L, low, pivot);
            low = pivot + 1;
        }

        return;
    }

    InsertSort(L);
}

void QuickSort(SqList *L)
{
    QSort(L, 0, L->length - 1);
}

// int main()
// {
//     SqList L = {
//         {50, 10, 90, 30, 70, 40, 80, 60, 20},
//         9,
//     };

//     QuickSort(&L);
//     for (int i = 0; i < L.length; i++)
//         printf("%d ", L.r[i]);
// }