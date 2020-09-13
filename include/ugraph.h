// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#ifndef UGRAPH_H
#define UGRAPH_H

#define CVECTOR_LOGARITHMIC_GROWTH

#include <stddef.h> /* size_t */

#include "cvector.h"

/** Edge between vertices with generic data. */
typedef struct {
    void* data;
    size_t vindex;
} ugraph_edge_t;

/** Vertex with generic data. */
typedef struct {
    void* data;
    cvector_vector_type(ugraph_edge_t*) edges;
} ugraph_vertex_t;

/** Undirected graph with generic data on vertices and edges. */
typedef struct {
    cvector_vector_type(ugraph_vertex_t*) vertices;
} ugraph_t;

/** Returns an empty graph. */
ugraph_t* ugraph_create();

/** Frees a graph's memory. */
void ugraph_destroy(ugraph_t* graph);

/** Adds an edge between vertices `u` and `v`. */
void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data);

/** Removes the edge between vertices `u` and `v`. */
void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v);

/** Returns the number of edges in a graph. */
size_t ugraph_ecount(ugraph_t* graph);

/** Adds a new vertex. */
void ugraph_add_vertex(ugraph_t* graph, void* data);

/** Removes vertex `u`. */
void ugraph_remove_vertex(ugraph_t* graph, size_t u);

/** Returns the number of vertices in a graph. */
size_t ugraph_vcount(ugraph_t* graph);

#endif