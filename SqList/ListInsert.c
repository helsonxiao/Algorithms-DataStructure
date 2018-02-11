#include <stdio.h>
#include "SqList.c"

// 使用结构指针访问结构内的元素需用运算符 ->
// 将 e 插到顺序表索引为 i 的位置
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    if (i <= L->length)
    {
        for (k = L->length - 1; k >= i; k--)
        {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i] = e;
    L->length++;
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
    int t = ListInsert(&list, 3, 5);
    printf("%d\n%d", t, list.data[3]); // list.data[3] == 5
}
