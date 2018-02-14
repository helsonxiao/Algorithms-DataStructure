#include <stdio.h>
#include <stdlib.h>
typedef int QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
} LinkQueue;

#define OK 1
#define ERROR 0
#define OVERFLOW 0
typedef int Status;
