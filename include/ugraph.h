/*
MIT License

Copyright (c) 2020 Seaton Ullberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef UGRAPH_H
#define UGRAPH_H

#include <stddef.h> /* size_t */

#include "arraylist.h"
#include "hash-table.h"

/* forward declarations */
typedef struct ugraph_vertex_t ugraph_vertex_t;
typedef struct ugraph_t ugraph_t;

/** Vertex in a graph. */
struct ugraph_vertex_t {
  void* data;
  HashTable* edges;
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

/** Removes the edge between vertices `u` and `v`. */
void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v);

/** Returns the data associated with the edge between vertices `u` and `v`. */
void* ugraph_edge_data(ugraph_t* graph, size_t u, size_t v);

/** Adds a vertex. */
void ugraph_add_vertex(ugraph_t* graph, void* data);

/** Removes vertex `v`. */
void ugraph_remove_vertex(ugraph_t* graph, size_t v);

/** Return the data associated with vertex `v`. */
void* ugraph_vertex_data(ugraph_t* graph, size_t v);

/** Returns the number of edges in a graph. */
size_t ugraph_ecount(ugraph_t* graph);

/** Returns the number of vertices in a graph. */
size_t ugraph_vcount(ugraph_t* graph);

#endif /* UGRAPH_H */