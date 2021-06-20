#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType Vex[MaxVertexNum];
    // 邻接矩阵
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph, *Graph;

typedef struct {
    EdgeType data[MaxVertexNum];
    int front, rear;
} SQ, *SeqQueue;

void InitQueue(SeqQueue &Q);

bool IsEmpty_Queue(SeqQueue Q);

bool EnQueue(SeqQueue &Q, EdgeType data);

bool DeQueue(SeqQueue &Q, EdgeType &data);

int GetVertexPos(Graph G, EdgeType v);

int FirstNeighbor(Graph G, EdgeType v);

int NextNeighbor(Graph G, EdgeType v, EdgeType pre);

void BFSTraverse(Graph &G);

void BFS(Graph &G, EdgeType v);

void visit(EdgeType v);

void DFSTraverse(Graph &G);

void DFS(Graph &G, EdgeType v);
