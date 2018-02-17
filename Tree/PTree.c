#include <stdio.h>
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct
{
    TElemType data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int r, n; // 根的位置，节点数
} PTree; 
