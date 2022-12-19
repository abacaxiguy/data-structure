#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// find the vertex with the smallest distance
int menor_distancia(int *distancia, int *visitado, int vertices) {
    int menor = -1;
    for (int i = 0; i < vertices; i++) {
        if (!visitado[i] && (menor == -1 || distancia[i] < distancia[menor])) {
            menor = i;
        }
    }
    return menor;
}

// find the shortest path where it goes through all vertices, doesn't matter the order
void dijkstra(Grafo *grafo, int origem) {
    int *distancia = (int *) malloc(grafo->vertices * sizeof(int));
    int *visitado = (int *) malloc(grafo->vertices * sizeof(int));
    int *anterior = (int *) malloc(grafo->vertices * sizeof(int));
    for (int i = 0; i < grafo->vertices; i++) {
        distancia[i] = 1000000;
        visitado[i] = 0;
        anterior[i] = -1;
    }
    distancia[origem] = 0;
    for (int i = 0; i < grafo->vertices; i++) {
        int u = menor_distancia(distancia, visitado, grafo->vertices);
        visitado[u] = 1;
        No *no = grafo->lista[u].cabeca;
        while (no != NULL) {
            if (!visitado[no->vertice] && distancia[u] + no->peso < distancia[no->vertice]) {
                distancia[no->vertice] = distancia[u] + no->peso;
                anterior[no->vertice] = u;
            }
            no = no->prox;
        }
    }
    for (int i = 0; i < grafo->vertices; i++) {
        printf("Distancia de %c para %c: %d\n", origem+65, i+65, distancia[i]);
        printf("Caminho: %c", i+65);
        int j = i;
        while (anterior[j] != -1) {
            printf(" <- %c", anterior[j]+65);
            j = anterior[j];
        }
        printf("\n\n");
    }
}

int main()
{
    // A = 0 - 65, B = 1 - 66, C = 2 - 67,
    // D = 3 - 68, E = 4 - 69, F = 5 - 70,
    // G = 6 - 71, H = 7 - 72

    Grafo *grafo = cria_grafo(8);
    adiciona_aresta(grafo, 0, 1, 9);
    adiciona_aresta(grafo, 0, 2, 3);
    adiciona_aresta(grafo, 0, 4, 8);
    adiciona_aresta(grafo, 0, 5, 3);
    adiciona_aresta(grafo, 0, 6, 4);
    adiciona_aresta(grafo, 1, 2, 10);
    adiciona_aresta(grafo, 1, 5, 6);
    adiciona_aresta(grafo, 2, 3, 6);
    adiciona_aresta(grafo, 2, 5, 4);
    adiciona_aresta(grafo, 2, 6, 5);
    adiciona_aresta(grafo, 2, 7, 7);
    adiciona_aresta(grafo, 3, 4, 6);
    adiciona_aresta(grafo, 3, 7, 3);
    adiciona_aresta(grafo, 4, 7, 5);
    imprime_grafo(grafo);
    dijkstra(grafo, 0);
    return 0;
}