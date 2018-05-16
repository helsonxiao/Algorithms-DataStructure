#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T)
    {
        *p = f;
        return FALSE;
    }
    else if (key == T->data)
    {
        *p = T;
        return TRUE;
    }
    else if (key < T->data)
        return SearchBST(T->lchild, key, T, p);
    else
        return SearchBST(T->rchild, key, T, p);
}

Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;

        return TRUE;
    }

    return FALSE;
}

Status CreateBST(BiTree *T)
{
    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    for (i = 0; i < 10; i++)
        InsertBST(T, a[i]);

    return TRUE;
}

Status Delete(BiTree *p)
{
    BiTree q, s;
    if ((*p)->rchild == NULL)
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL)
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if (q != *p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);
    }
    return TRUE;
}

Status DeleteBST(BiTree *T, int key)
{
    if (!T)
        return FALSE;
    else
    {
        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}
