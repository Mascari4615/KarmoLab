#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"

void CreateGraph(graphType *g);
{
    int i, j;
    g->n = 0;
    for (i = 0; i < MAX_VERTEX; i++)
    {
        for (j = 0; j < MAX_VERTEX; j++)
        {
            g->adjMatrix[i][j] = 0;
        }
    }
}
void InsertVertex(graphType *g, int v)
{
    if (((g->n) + 1) > MAX_VERTEX)
    {
        printf("\n 그래프 정점의 개수를 초과하였습니다");
        return;
    }
    if (v < (g->n))
        return;
    g->n++;
}
void InsertEdge(graphType *g, int u, int v)
{
    if (u >= g->n || v >= g->n)
    {
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }
    g->adjMatrix[u][v] = 1;
}
void PrintAdjMatrix(graphType *g)
{
    int i, j;
    for (i = 0; i < (g->n); i++)
    {
        printf("\n\t\t");
        for (j = 0; j < (g->n); j++)
        {
            printf("%2d", g->adjMatrix[i][j]);
        }
    }
}