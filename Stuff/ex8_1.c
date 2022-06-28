#include <stdio.h>
#include "adjMatrix.h"

int main(void)
{
    int i;
    graphType* G1 = (graphType*)malloc(sizeof(graphType));
    graphType* G2 = (graphType*)malloc(sizeof(graphType));
    graphType* G3 = (graphType*)malloc(sizeof(graphType));
    graphType* G4 = (graphType*)malloc(sizeof(graphType));

    CreateGraph(G1);
    for (i = 0; i < 4; i++)
    {
        InsertVertex(G1, i);
    }
    InsertEdge(G1, 0, 3);
    InsertEdge(G1, 0, 1);
    InsertEdge(G1, 1, 3);
    InsertEdge(G1, 1, 2);
    InsertEdge(G1, 1, 0);
    InsertEdge(G1, 2, 3);
    InsertEdge(G1, 2, 1);
    InsertEdge(G1, 3, 2);
    InsertEdge(G1, 3, 1);
    InsertEdge(G1, 3, 0);

    CreateGraph(G2);
    for (i = 0; i < 3; i++)
    {
        InsertVertex(G2, i);
    }
    InsertEdge(G2, 0, 2);
    InsertEdge(G2, 0, 1);
    InsertEdge(G2, 1, 2);
    InsertEdge(G2, 1, 0);
    InsertEdge(G2, 2, 1);
    InsertEdge(G2, 2, 0);

    CreateGraph(G3);
    for (i = 0; i < 4; i++)
    {
        InsertVertex(G3, i);
    }
    InsertEdge(G3, 0, 3);
    InsertEdge(G3, 0, 1);
    InsertEdge(G3, 1, 3);
    InsertEdge(G3, 1, 2);
    InsertEdge(G3, 2, 3);
    

    CreateGraph(G4);
    for (i = 0; i < 3; i++)
    {
        InsertVertex(G4, i);
    }
    InsertEdge(G4, 0, 2);
    InsertEdge(G4, 0, 1);
    InsertEdge(G4, 1, 2);
    InsertEdge(G4, 1, 0);

    PrintAdjMatrix(G1);
    PrintAdjMatrix(G2);
    PrintAdjMatrix(G3);
    PrintAdjMatrix(G4);
}