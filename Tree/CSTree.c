#include <stdio.h>
#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct
{
    TElemType data;
    struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;
