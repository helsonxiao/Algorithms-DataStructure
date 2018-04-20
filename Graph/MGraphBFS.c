#include "MGraph.c"
#include "../SqQueue/SqQueue.c"
typedef int Boolean;
Boolean visited[MAXVEX];

void BFSTraverse(MGraph G)
{
    int i, j;
    SqQueue Q;
    InitQueue(&Q);

    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE;
    }

    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            EnQueue(&Q, i);
            while (QueueLength(Q))
            {
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++)
                {
                    if (G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = TRUE;
                        printf("%c ", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}