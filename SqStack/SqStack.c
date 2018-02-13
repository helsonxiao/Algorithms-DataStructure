#include <stdio.h>
#define MAXSIZE 5
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
