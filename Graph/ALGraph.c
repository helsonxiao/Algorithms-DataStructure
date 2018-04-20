#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 10
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct GraphAdjList
{
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

void CreateALGraph (GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);

    // init vertexes
    for (i=0; i<G->numVertexes; i++)
    {
        printf("set NO.%d vertex name: ", i);
        scanf("%s", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }

    // insert edges
    for (k=0; k<G->numEdges; k++)
    {
        printf("输入边 vi - vj 上的顶点序号：\n");
        scanf("%d, %d", &i, &j);
        // insert j to i list
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        // insert i to j list
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}