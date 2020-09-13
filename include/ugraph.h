// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#ifndef UGRAPH_H
#define UGRAPH_H

#define CVECTOR_LOGARITHMIC_GROWTH

#include <stddef.h>  // size_t

#include "cvector.h"

/** Representation of an edge between vertices. */
#define ugraph_edge(T)     \
  struct ugraph_edge_##T { \
    T data;                \
    size_t vindex;         \
  }

#define ugraph_edge_new(T)                                                 \
  ({                                                                       \
    struct ugraph_edge_##T* edge = malloc(sizeof(struct ugraph_edge_##T)); \
    edge;                                                                  \
  })

/** Representation of a vertex. */
#define ugraph_vertex(T)                                \
  struct ugraph_vertex_##T {                            \
    T data;                                             \
    cvector_vector_type(struct ugraph_edge_##T*) edges; \
  }

#define ugraph_vertex_new(T)                                             \
  ({                                                                     \
    ugraph_vertex(T) *vertex = malloc(sizeof(struct ugraph_vertex_##T)); \
    vertex;                                                              \
  })

/** Representation of an undirected graph. */
#define ugraph(E, V)                                         \
  struct ugraph_##EV {                                       \
    const char* etype;                                       \
    const char* vtype;                                       \
    cvector_vector_type(struct ugraph_vertex_##V*) vertices; \
  }

/** Returns an empty graph. */
#define ugraph_new(E, V)                                            \
  ({                                                                \
    struct ugraph_##EV* graph = malloc(sizeof(struct ugraph_##EV)); \
    graph->etype = #E;                                              \
    graph->vtype = #V;                                              \
    graph;                                                          \
  })

#define ugraph_add_vertex(graph, data, E, V)           \
  ({                                                   \
    ugraph_vertex(V)* vertex = ugraph_vertex_new(V);   \
    cvector_vector_type(ugraph_edge(E)*) edges = NULL; \
    vertex->edges = edges;                             \
    vertex->data = data;                               \
    cvector_push_back(graph->vertices, vertex);        \
  })

#define ugraph_vcount(graph) (cvector_size(graph->vertices))

// /** Frees a graph's memory. */
// void ugraph_free(ugraph_t* graph);

// /** Adds an edge between vertices `u` and `v` with associated data. */
// void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data);

// /** Removes the edge between vertices `u` and `v`. */
// void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v);

// /** Adds a new vertex with associated data. */
// void ugraph_add_vertex(ugraph_t* graph, void* data);

// /** Removes vertex `u`. */
// void ugraph_remove_vertex(ugraph_t* graph, size_t u);

// /** Returns the number of edges. */
// size_t ugraph_ecount(ugraph_t* graph);

// /** Returns the number of vertices. */
// size_t ugraph_vcount(ugraph_t* graph);

#endif