#include <stdio.h>
#include <stdlib.h>
typedef int SElemType;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
