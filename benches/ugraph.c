// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include "ubench.h"

#include "ugraph.h" 

#define N_ENTRIES 1000

UBENCH(ugraph_benches, add_vertices) {
    ugraph_t* graph = ugraph_new();
    int data = 0;
    size_t i;
    for (i = 0; i < N_ENTRIES; i++) {
        ugraph_add_vertex(graph, &data);
    }
    ugraph_free(graph);
}

UBENCH(ugraph_benches, add_remove_vertices) {
    ugraph_t* graph = ugraph_new();
    int data = 0;
    size_t i;
    for (i = 0; i < N_ENTRIES; i++) {
        ugraph_add_vertex(graph, &data);
    }
    for (i = N_ENTRIES; i > 0; i--) {
        ugraph_remove_vertex(graph, 0);
    }
    ugraph_free(graph);
}

UBENCH(ugraph_benches, add_vertices_with_edges) {
    ugraph_t* graph = ugraph_new();
    int data = 0;
    size_t i;
    for (i = 0; i < N_ENTRIES; i++) {
        ugraph_add_vertex(graph, &data);
    }
    for (i = 1; i < N_ENTRIES; i++) {
        ugraph_add_edge(graph, i, i - 1, &data);
    }
    ugraph_free(graph);
}

UBENCH(ugraph_benches, add_remove_vertices_with_edges) {
    ugraph_t* graph = ugraph_new();
    int data = 0;
    size_t i;
    for (i = 0; i < N_ENTRIES; i++) {
        ugraph_add_vertex(graph, &data);
    }
    for (i = 1; i < N_ENTRIES; i++) {
        ugraph_add_edge(graph, i, i - 1, &data);
    }
    for (i = N_ENTRIES; i > 0; i--) {
        ugraph_remove_vertex(graph, 0);
    }
    ugraph_free(graph);
}
