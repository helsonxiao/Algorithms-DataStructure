#include <stdio.h>
#include "SqList.c"

// 引用调用才可以修改实际参数的值，传入元素 e 的地址来修改元素
// 获取顺序表索引为 i 的元素值
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i];
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
    int t = GetElem(list, 2, &e);
    printf("%d\n%d", t, e); // e == 2
}
