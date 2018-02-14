#include "SqQueue.c"

Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return ERROR;
    }

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
    {
        return ERROR;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return OK;
}

int main()
{
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 7);

    QElemType e;
    DeQueue(&Q, &e);
    printf("%d", e);
}
