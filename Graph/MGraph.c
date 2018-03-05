#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph (MGraph *G)
{
    int i, j, k, w;
    printf("输入 numVertexes:\n");
    scanf("%d", &G->numVertexes);
    printf("输入 numEdges:\n");
    scanf("%d", &G->numEdges);

    // 输入顶点信息
    for (i=0; i<G->numVertexes; i++)
    {
        scanf(&G->vexs[i]);
    }

    // 矩阵初始化
    for (i=0; i<G->numVertexes; i++)
    {
        for (j=0; j<G->numVertexes; j++)
        {
            G->arc[i][j] = INFINITY;
        }
    }

    // 输入 (vi, vj) 信息
    for (k=0; k<G->numEdges; k++)
    {
        printf("请输入无向图的下标和权 i, j, w:\n");
        scanf("%d, %d, %d", i, j, w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

