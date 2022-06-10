#pragma once
#define MAX_VERTEX 30

typedef struct graphNode
{
    int vertex;
    struct graphNode* link;
} graphNode;


typedef struct graphType
{
    int n;
    int adjList_H[MAX_VERTEX];
} graphType;

void CreateGraph(graphType *g);
void InsertVertex(graphType *g, int v);
void InsertEdge(graphType *g, int u, int v);
void PrintAdjList(graphType *g);