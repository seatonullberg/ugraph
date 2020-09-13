// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include <stddef.h> // size_t

#include "cvector.h"
#include "ugraph.h"

// ugraph_t* ugraph_new() {
//     cvector_vector_type(ugraph_vertex_t*) v = NULL;
//     ugraph_t* graph = malloc(sizeof(ugraph_t));
//     graph->vertices = v;
//     return graph;
// }

// void ugraph_add_vertex(ugraph_t* graph, void* data) {
//     ugraph_vertex_t* vertex = malloc(sizeof(ugraph_vertex_t));
//     vertex->data = data;
//     cvector_vector_type(ugraph_edge_t*) e = NULL;
//     vertex->edges = e;
//     cvector_push_back(graph->vertices, vertex);
// }

// void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data) {
//     /* Connect u to v. */
//     ugraph_edge_t* uedge = malloc(sizeof(ugraph_edge_t));
//     uedge->data = data;
//     uedge->vindex = v;
//     /* Connect v to u. */
//     ugraph_edge_t* vedge = malloc(sizeof(ugraph_edge_t));
//     vedge->data = data;
//     vedge->vindex = u;

//     cvector_push_back(graph->vertices[u]->edges, uedge);
//     cvector_push_back(graph->vertices[v]->edges, vedge);
// }

// size_t ugraph_ecount(ugraph_t* graph) {
//     size_t ne = 0;

//     size_t i;
//     size_t nv = ugraph_vcount(graph);
//     for (i = 0; i < nv; i++) {
//         ne += cvector_size(graph->vertices[i]->edges);
//     }
//     return ne / 2;
// }

// size_t ugraph_vcount(ugraph_t* graph) {
//     return cvector_size(graph->vertices);
// }