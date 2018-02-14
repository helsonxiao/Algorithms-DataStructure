#include "LinkQueue.c"

Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
    {
        exit(OVERFLOW);
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;

    return OK;
}

Status DeQueue (LinkQueue *Q, QElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR;
    }
    QueuePtr p;
    p = Q->front->next; // first node behind head node
    *e = p->data;
    Q->front->next = p->next;

    if (Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

// int main()
// {
//     LinkQueue Q;
//     int s = EnQueue(&Q, 7);
//     printf("%d", s);

//     QElemType e;
//     DeQueue(&Q, &e);
//     printf("%d", e);
// }
