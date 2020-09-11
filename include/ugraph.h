// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#ifndef UGRAPH_H
#define UGRAPH_H

#define CVECTOR_LOGARITHMIC_GROWTH

#include <stddef.h> // size_t

#include "cvector.h"

int my_function();

typedef struct ugraph_vertex_t ugraph_vertex_t;
typedef struct ugraph_edge_t ugraph_edge_t;
typedef struct ugraph_t ugraph_t;


/// Vertex type
struct ugraph_vertex_t {
    void* data;
    cvector_vector_type(ugraph_edge_t*) edges;
};

/// Edge type
struct ugraph_edge_t {
    void* data;
    ugraph_vertex_t* vertex;
};

/// Graph type
struct ugraph_t {
    cvector_vector_type(ugraph_vertex_t*) vertices;
};

/// Returns an empty graph
ugraph_t* ugraph_create();

/// Frees a graph's memory
void ugraph_destroy(ugraph_t* graph);

/// Adds an edge between vertices `u` and `v`
void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v);

/// Removes the edge between vertices `u` and `v`
void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v);

/// Returns the number of edges
size_t ugraph_ecount(ugraph_t* graph);

/// Adds a new vertex to the graph
void ugraph_add_vertex(ugraph_t* graph, void* data);

/// Removes vertex `u`
void ugraph_remove_vertex(ugraph_t* graph, size_t u);

/// Returns the number of vertices
size_t ugraph_vcount(ugraph_t* graph);

#endif