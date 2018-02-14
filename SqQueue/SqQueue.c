#include <stdio.h>
#define MAXSIZE 10
typedef int QElemType;
typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
