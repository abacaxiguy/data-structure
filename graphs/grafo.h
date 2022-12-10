#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char info;
    struct node *next;
} node;

typedef struct graph{
    char vortex;
    node **neighbors;
} graph;

node *create_linked_list(char info){
    node *list = (node *) malloc(sizeof(node));
    list->info = info;
    list->next = NULL;

    return list;
}

node *add_linked_list(node *list, char info){
    if (list == NULL) return create_linked_list(info);
    list->next = add_linked_list(list->next, info);

    return list;
}

graph *create_graph(char vortex)
{
    graph *g = (graph *) malloc(sizeof(graph));
    g->vortex = vortex;
    g->neighbors = NULL;
}

void add_neighbor(graph *g, char vortex)
{
    if (g->neighbors == NULL) {
        g->neighbors = (node **) malloc(sizeof(node *));
        g->neighbors[0] = create_linked_list(vortex);
    } else {
        int i = 0;
        while (g->neighbors[i] != NULL) i++;
        g->neighbors = (node **) realloc(g->neighbors, (i + 1) * sizeof(node *));
        g->neighbors[i] = create_linked_list(vortex);
    }
}

void print_graph(graph *g){
    int i = 0;
    printf("%c -> ", g->vortex);
    while (g->neighbors[i] != NULL) {
        printf("%c ", g->neighbors[i]->info);
        i++;
    }
    printf("\n");
}