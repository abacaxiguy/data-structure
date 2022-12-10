#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int v[MAX][MAX];
    int n;
} Graph;

Graph createGraph();

void addEdge(Graph *g, int v1, int v2);

int adjacent(Graph g, int v1, int v2);

int getAdjacentVertices(Graph g, int vertex, int *output);

void dropGraph(Graph *g);

void printGraph(Graph g);

Graph createGraph() {
    Graph g;
    g.n = 0;
    int i, j;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            g.v[i][j] = 0;
    return g;
}

void addEdge(Graph *g, int v1, int v2) {
    if (v1 >= 0 && v1 < MAX && v2 >= 0 && v2 < MAX) {
        g->v[v1][v2] = 1;
        if (v1 != v2)
            g->v[v2][v1] = 1;
    }
}

int adjacent(Graph g, int v1, int v2) {
    if (v1 >= 0 && v1 < MAX && v2 >= 0 && v2 < MAX)
        return g.v[v1][v2];
    return 0;
}

int getAdjacentVertices(Graph g, int vertex, int *output) {
    if (vertex < 0 || vertex >= MAX)
        return 0;
    int i, total = 0;
    for (i = 0; i < MAX; i++)
        if (g.v[vertex][i] == 1)
            output[total++] = i;
    return total;
}

void dropGraph(Graph *g) {
    g->n = 0;
}

void printGraph(Graph g) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            printf("%d ", g.v[i][j]);
        printf("\n\n");
    }
}