#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0

typedef char TElemType;
typedef struct
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

// 与书本程序略有不同，未使用指针链。
void CreateBiTree(BiTree T)
{
    TElemType ch;
    scanf("%c", &ch);
    if (ch=="#")
    {
        T = NULL;
    }

    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T)
    {
        exit(OVERFLOW);
    }
    (T)->data = ch;
    CreateBiTree((T)->lchild);
    CreateBiTree((T)->rchild);
}

int main()
{
    BiTree T;
    CreateBiTree(T);
}
