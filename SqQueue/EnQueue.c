#include "SqQueue.c"

int main()
{
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 7);

    QElemType e;
    DeQueue(&Q, &e);
    printf("%d", e);
}
