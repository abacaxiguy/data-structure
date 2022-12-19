#include <stdio.h>
#include <stdlib.h>

// weighted graph
typedef struct no {
    int vertice;
    int peso;
    struct no *prox;
} No;

typedef struct lista {
    No *cabeca;
} Lista;

typedef struct grafo {
    int vertices;
    Lista *lista;
} Grafo;

Grafo *cria_grafo(int vertices) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
    grafo->vertices = vertices;
    grafo->lista = (Lista *) malloc(vertices * sizeof(Lista));
    for (int i = 0; i < vertices; i++) {
        grafo->lista[i].cabeca = NULL;
    }
    return grafo;
}

void adiciona_aresta(Grafo *grafo, int vertice1, int vertice2, int peso) {
    No *no = (No *) malloc(sizeof(No));
    no->vertice = vertice2;
    no->peso = peso;
    no->prox = grafo->lista[vertice1].cabeca;
    grafo->lista[vertice1].cabeca = no;
}

void imprime_grafo(Grafo *grafo) {
    No *no;
    for (int i = 0; i < grafo->vertices; i++) {
        no = grafo->lista[i].cabeca;
        printf("%c: ", i+65);
        while (no != NULL) {
            printf("%c(%d) -> ", no->vertice+65, no->peso);
            no = no->prox;
        }
        printf("NULL\n");
    }
}