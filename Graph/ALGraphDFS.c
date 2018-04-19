#include "ALGraph.c"
typedef int Boolean;
Boolean visited[MAXVEX];

void DFS(GraphAdjList G, int i)
{
    EdgeNode *p = G.adjList[i].firstedge;
    visited[i] = 1;
    printf("visiting %c...\n", G.adjList[i].data);
    while (p)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex);
        }
        p = p -> next;
    }
}

void DFSTraverse(GraphAdjList G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = 0;
    }

    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            DFS(G, i);
        }
    }
}

int main()
{
    GraphAdjList G;
    CreateALGraph(&G);
    DFSTraverse(G);
}
