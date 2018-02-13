#include <stdio.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (i)
    {
        space[0].cur = space[i].cur;
    }

    return i;
}

void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while (i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}
