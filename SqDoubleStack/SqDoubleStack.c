#include <stdio.h>
#define MAXSIZE 10
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
