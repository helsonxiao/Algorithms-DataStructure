#include <stdio.h>
#include "struct.c"

void Merge(int SR[], int TR[], int i, int m, int n)
{
    int j, k, l;
    for (j = m + 1, k = i; i <= m && j <= n; k++)
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];

    if (i <= m)
        for (l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];

    if (j <= n)
        for (l = 0; l <= n - i; l++)
            TR[k + l] = SR[j + l];
}

void MSort(int SR[], int TR1[], int s, int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
        TR1[s] = SR[s];
    else
    {
        m = (s + t) / 2;
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m + 1, t);
        Merge(TR2, TR1, s, m, t);
    }
}

int main()
{
    SqList L = {
        {50, 10, 90, 30, 70, 40, 80, 60, 20},
        9,
    };

    MSort(L.r, L.r, 0, L.length - 1);
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.r[i]);
}
