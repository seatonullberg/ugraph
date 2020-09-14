// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#ifndef UGRAPH_H
#define UGRAPH_H

#include <stddef.h> /* size_t */

#include "arraylist.h"

/** Edge between vertices in a graph. */
typedef struct {
  void* data;
  size_t vindex;
} ugraph_edge_t;

/** Vertex in a graph. */
typedef struct {
  void* data;
  ArrayList* edges;
} ugraph_vertex_t;

/** Undirected graph type. */
typedef struct {
  ArrayList* vertices;
} ugraph_t;

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