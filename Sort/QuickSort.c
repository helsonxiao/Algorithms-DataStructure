#include <stdio.h>
#include "struct.c"

int Partition(SqList *L, int low, int high)
{
    int pivotkey = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        swap(L, low, high);
        while (low < high && L->r[low] <= pivotkey)
            low++;
        swap(L, low, high);
    }
    return low;
}

void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high);
        QSort(L, low, pivot);
        QSort(L, pivot + 1, high);
    }
}

void QuickSort(SqList *L)
{
    QSort(L, 0, L->length - 1);
}

int main()
{
    SqList L = {
        {50, 10, 90, 30, 70, 40, 80, 60, 20},
        9,
    };

    QuickSort(&L);
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.r[i]);
}