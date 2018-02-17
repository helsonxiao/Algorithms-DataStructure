#include <stdio.h>
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct{
    int child;
    struct CTNode *next;
} CTNode, *ChildPtr;

typedef struct
{
    TElemType data;
    // combine parent tree and child tree
    // int parent;
    ChildPtr firstchild;
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;
} CTree;
