#pragma once
#define MAX_VERTEX 30

typedef struct graphType
{
    int n;
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

void CreateGraph(graphType *g);
void InsertVertex(graphType *g, int v);
void InsertEdge(graphType *g, int u, int v);
void PrintAdjMatrix(graphType *g);