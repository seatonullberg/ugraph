// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include <stddef.h> // size_t

#include "cvector.h"
#include "ugraph.h"

ugraph_t* ugraph_create() {
    cvector_vector_type(ugraph_vertex_t*) v = NULL;
    ugraph_t* graph = malloc(sizeof(ugraph_t));
    graph->vertices = v;
    return graph;
}

void ugraph_add_vertex(ugraph_t* graph, void* data) {
    ugraph_vertex_t* vertex = malloc(sizeof(ugraph_vertex_t));
    vertex->data = data;
    cvector_vector_type(ugraph_edge_t*) e = NULL;
    vertex->edges = e;
    cvector_push_back(graph->vertices, vertex);
}

size_t ugraph_vcount(ugraph_t* graph) {
    return cvector_size(graph->vertices);
}