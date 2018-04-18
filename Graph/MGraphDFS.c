#include "MGraph.c"
typedef int Boolean;
Boolean visited[MAXVEX];

void DFS (MGraph G, int i)
{
    int j;
    visited[i] = 1;
    printf("visiting %c...\n", G.vexs[i]);
    for (j=0; j<G.numVertexes; j++)
    {
        if (G.arc[i][j] != INFINITY && !visited[j])
        {
            DFS(G, j);
        }
    }
}

void DFSTraverse (MGraph G)
{
    int i;
    for (i=0; i<G.numVertexes; i++)
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
    MGraph G;
    CreateMGraph(&G);
    DFSTraverse(G);
}
