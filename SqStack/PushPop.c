#include "SqStack.c"

Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

int main()
{
    SqStack stack;
    stack.top = -1;
    SElemType e = 7;

    Push(&stack, e);
    printf("%d is in stack\n", stack.data[stack.top]);

    Pop(&stack, &e);
    printf("%d is out", e);
}
