#include "ALGraph.c"
#include "../SqQueue/SqQueue.c"
typedef int Boolean;
Boolean visited[MAXVEX];

void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    SqQueue Q;
    InitQueue(&Q);

    for (i = 0; i < GL.numVertexes; i++)
    {
        visited[i] = FALSE;
    }

    for (i = 0; i < GL.numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", GL.adjList[i].data);
            EnQueue(&Q, i);
            while (QueueLength(Q))
            {
                DeQueue(&Q, &i);
                p = GL.adjList[i].firstedge;
                while (p)
                {
                    if (!visited[p->adjvex])
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL.adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main()
{
    GraphAdjList G;
    CreateALGraph(&G);
    BFSTraverse(G);
}