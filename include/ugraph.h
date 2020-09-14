// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#ifndef UGRAPH_H
#define UGRAPH_H

#include <stddef.h> /* size_t */

#include "arraylist.h"

/* forward declarations */
typedef struct ugraph_edge_t ugraph_edge_t;
typedef struct ugraph_vertex_t ugraph_vertex_t;
typedef struct ugraph_t ugraph_t;

/** Edge between vertices in a graph. */
struct ugraph_edge_t {
  void* data;
  ugraph_vertex_t* endpoint;
};

/** Vertex in a graph. */
struct ugraph_vertex_t {
  void* data;
  ArrayList* edges;
};

/** Undirected graph type. */
struct ugraph_t {
  ArrayList* vertices;
};

/** Returns an empty graph. */
ugraph_t* ugraph_new();

/** Frees a graph's memory. */
void ugraph_free(ugraph_t* graph);

/** Adds an edge between vertices `u` and `v`. */
void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data);

/** Removes an edge between vertices `u` and `v`. */
void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v);

/** Adds a vertex. */
void ugraph_add_vertex(ugraph_t* graph, void* data);

/** Removes vertex `v`. */
void ugraph_remove_vertex(ugraph_t* graph, size_t v);

/** Returns the number of edges in a graph. */
size_t ugraph_ecount(ugraph_t* graph);

/** Returns the number of vertices in a graph. */
size_t ugraph_vcount(ugraph_t* graph);

#endif