#include <stdio.h>

typedef enum {Link, Thread} PointerTag; // DEFAULT: Link==0, Thread==1
typedef char TElemType;
typedef struct
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

BiThrTree pre; // 上一次访问的结点
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// 中序线索化后，可根据线索遍历二叉树
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p; // 构建 root
    p = T->lchild; // 令"头节点的左孩子"指向 root

    // p 不指向头节点时，继续遍历
    while(p != T)
    {
        // 找到第一个结点(最左边的孩子)
        while(p->LTag == Link)
        {
            p = p->lchild;
        }
        printf("%c", p->data);

        // 根据线索，中序打印出它的后继结点们
        while(p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            printf("%c", p->data);
        }

        // 不断遍历，直到头节点
        p = p->rchild;
    }
}
