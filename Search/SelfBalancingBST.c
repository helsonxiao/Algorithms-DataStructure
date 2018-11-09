// This is self-balancing binary search tree
#include <stdio.h>
#define LH +1
#define EH 0
#define RH -1
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct BiTNode
{
    int data;
    int bf; // balance factor 平衡因子
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void R_Rotate(BiTree *P)
{
    BiTree L;
    L = (*P)->lchild;
    (*P)->lchild = L->rchild;
    L->rchild = (*P);
    *P = L;
}

void L_Rotate(BiTree *P)
{
    BiTree R;
    R = (*P)->rchild;
    (*P)->rchild = R->lchild;
    R->lchild = (*P);
    *P = R;
}

void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;

    switch (L->bf)
    {
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;

        case RH:
            Lr = L->rchild;
            switch (Lr->bf)
            {
                case LH:
                    (*T)->bf = L->bf = RH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            
            Lr->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }
}

void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild;

    switch (R->bf)
    {
        case RH:
            (*T)->bf = R->bf = EH;
            L_Rotate(T);
            break;

        case LH:
            Rl = R->lchild;

            switch (Rl->bf)
            {
                case LH:

                    break;

                case RH:

                    break;

                case EH:

                    break;
            }
    }
}
