
#include "ListGraph.h"

void InitQueue(SeqQueue &Q) {
    Q->front = Q->rear = 0;
}

bool IsEmpty_Queue(SeqQueue Q) {
    if (Q->front == Q->rear) return true;
    return false;
}

bool EnQueue(SeqQueue &Q, EdgeType data) {
    if ((Q->rear + 1) % MaxVertexNum == Q->front) {
        return false;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MaxVertexNum;
    return true;
}

bool DeQueue(SeqQueue &Q, EdgeType &data) {
    if (IsEmpty_Queue(Q)) return false;
    data = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxVertexNum;
    return true;
}

int GetVertexPos(Graph G, EdgeType v) {
    for (int i = 0; i < G->vexnum; ++i) {
        if (G->Vex[i] == v) {
            return i;
        }
    }
    return -1;
}

int FirstNeighbor(Graph G, EdgeType v) {
    int p = GetVertexPos(G, v);
    if (p == -1) {
        return -1;
    }
    for (int i = 0; i < G->vexnum; ++i) {
        if (G->Edge[p][i] == 1) {
            return i;
        }
    }
    return -1;
}

int NextNeighbor(Graph G, EdgeType v, EdgeType pre) {
    int pv = GetVertexPos(G, v);
    int pw = GetVertexPos(G, pre);
    if (pv == -1 || pw == -1) {
        return -1;
    }
    for (int i = pw + 1; i < G->vexnum; ++i) {
        if (G->Edge[pv][i] == 1) {
            return i;
        }
    }
    return -1;
}

void visit(EdgeType v) {
    printf("%d ", v);
}

bool visited[MaxVertexNum];  // 已访问列表
SeqQueue Q = (SeqQueue) malloc(sizeof(SQ));

void BFSTraverse(Graph &G) {
    for (int i = 0; i < G->vexnum; ++i) {
        visited[i] = false;
    }
    InitQueue(Q);
    for (int i = 0; i < G->vexnum; ++i) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}


void BFS(Graph &G, EdgeType v) {
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);
    while (!IsEmpty_Queue(Q)) {
        DeQueue(Q, v);
        for (int w = FirstNeighbor(G, v); w > 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

void DFSTraverse(Graph &G) {
    for (int i = 0; i <G->vexnum; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i <G->vexnum; ++i) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

void DFS(Graph &G, EdgeType v) {
    visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}
