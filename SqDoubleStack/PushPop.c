#include "SqDoubleStack.c"

Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2)
    {
        return ERROR;
    }

    if (stackNumber == 1)
    {
        S->data[++S->top1] = e;
    }
    else if (stackNumber == 2)
    {
        S->data[--S->top2] = e;
    }
    return OK;
}

Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (S->top1 == -1)
        {
            return ERROR;
        }
        *e = S->data[S->top1--];
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == MAXSIZE)
        {
            return ERROR;
        }
        *e = S->data[S->top2++];
    }

    return OK;
}

int main()
{
    SqDoubleStack stack;
    stack.top1 = -1;
    stack.top2 = MAXSIZE;
    int stack1 = 1, stack2 = 2;
    SElemType e;

    Push(&stack, 7, stack1);
    printf("%d is in stack\n", stack.data[stack.top1]);
    Push(&stack, 14, stack2);
    printf("%d is in stack\n", stack.data[stack.top2]);

    Pop(&stack, &e, stack1);
    printf("%d is out\n", e);
    Pop(&stack, &e, stack2);
    printf("%d is out\n", e);
}
