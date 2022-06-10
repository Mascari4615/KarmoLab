#include <stdio.h>
#include "BFS.h"

int main(void)
{
    int i;
    graphType* G9 = (graphType*)malloc(sizeof(graphType));
    CreateGraph(G9);
    for (i = 0; i < 7; i++)
    {
        InsertVertex(G9, i);
    }
    InsertEdge(G9, 0, 2);
    InsertEdge(G9, 0, 1);
    InsertEdge(G9, 1, 4);
    InsertEdge(G9, 1, 3);
    InsertEdge(G9, 1, 0);
    InsertEdge(G9, 2, 4);
    InsertEdge(G9, 2, 0);
    InsertEdge(G9, 3, 6);
    InsertEdge(G9, 3, 1);
    InsertEdge(G9, 4, 6);
    InsertEdge(G9, 4, 2);
    InsertEdge(G9, 4, 1);
    InsertEdge(G9, 5, 6);
    InsertEdge(G9, 6, 5);
    InsertEdge(G9, 6, 4);
    InsertEdge(G9, 6, 3);

    PrintAdjList(G9);
    BFS_adjList(G9, 0);
}