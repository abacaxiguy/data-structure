#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Undirected circular graph
// Representation:

//  A -- B
//  |   /
//  |  /
//  | /
//  C

int main(){
    graph *g = create_graph('A');
    add_neighbor(g, 'B');
    add_neighbor(g, 'C');

    graph *g2 = create_graph('B');
    add_neighbor(g2, 'A');
    add_neighbor(g2, 'C');

    graph *g3 = create_graph('C');
    add_neighbor(g3, 'A');
    add_neighbor(g3, 'B');

    print_graph(g);
    print_graph(g2);
    print_graph(g3);

    return 0;
}