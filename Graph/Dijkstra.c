#include "MGraph.c"
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

void ShortestPath_Dijkstra (MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    int final[MAXVEX];
    for (v = 0; v < G.numVertexes; v++)
    {
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0; // P[v] is v's previous index/station
    }
    (*D)[v0] = 0;
    final[v0] = 1; // v0 is resolved

    for (v = 1; v < G.numVertexes; v++)
    {
        min = INFINITY;
        for (w = 0; w < G.numVertexes; w++)
        {
            if (!final[w] && (*D)[w] < min)
            {
                min = (*D)[w];
                k = w;
            }
        }
        final[k] = 1; // vk is resolved

        for (w = 0; w < G.numVertexes; w++)
        {
            if (!final[w] && (G.arc[k][w] + min) < (*D)[w])
            {
                (*D)[w] = G.arc[k][w] + min;
                (*P)[w] = k;
            }
        }
    }
}