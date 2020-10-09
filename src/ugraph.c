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

#include "ugraph.h"

#include <stddef.h> /* size_t */
#include <stdlib.h> /* malloc */

#include <calg/arraylist.h>
#include <calg/compare-pointer.h>
#include <calg/hash-pointer.h>
#include <calg/hash-table.h>

ugraph_t* ugraph_new() {
  ugraph_t* graph = malloc(sizeof(ugraph_t));
  graph->vertices = arraylist_new(0);
  return graph;
}

void ugraph_vertex_t_free(ugraph_vertex_t* vertex) {
  hash_table_free(vertex->edges);
  free(vertex);
}

void ugraph_free(ugraph_t* graph) {
  ugraph_vertex_t* vertex;
  size_t i;

  /* iterate over each vertex */
  for (i = 0; i < ugraph_vcount(graph); i++) {
    vertex = (ugraph_vertex_t*)graph->vertices->data[i];
    ugraph_vertex_t_free(vertex);
    arraylist_remove(graph->vertices, i);
  }

  arraylist_free(graph->vertices);
  free(graph);
}

void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data) {
  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;

  /* access vertices */
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];

  /* connect u to v */
  hash_table_insert(uvertex->edges, vvertex, data);

  /* connect v to u */
  hash_table_insert(vvertex->edges, uvertex, data);
}

void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v) {
  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;

  /* access vertices */
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];

  /* remove v from u */
  hash_table_remove(uvertex->edges, vvertex);

  /* remove u from v */
  hash_table_remove(vvertex->edges, uvertex);
}

void* ugraph_edge_data(ugraph_t* graph, size_t u, size_t v) {
  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;

  /* access the vertices */
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];

  return hash_table_lookup(uvertex->edges, vvertex);
}

void ugraph_add_vertex(ugraph_t* graph, void* data) {
  ugraph_vertex_t* vertex = malloc(sizeof(ugraph_vertex_t));
  vertex->data = data;
  vertex->edges = hash_table_new(pointer_hash, pointer_equal);
  arraylist_append(graph->vertices, vertex);
}

void ugraph_remove_vertex(ugraph_t* graph, size_t v) {
  ugraph_vertex_t* vertex_outer;
  ugraph_vertex_t* vertex_inner;
  size_t i;

  /* remove the offending vertex */
  vertex_outer = (ugraph_vertex_t*)graph->vertices->data[v];
  ugraph_vertex_t_free(vertex_outer);
  arraylist_remove(graph->vertices, v);

  /* update all edges */
  for (i = 0; i < ugraph_vcount(graph); i++) {
    vertex_inner = (ugraph_vertex_t*)graph->vertices->data[i];
    hash_table_remove(vertex_inner->edges, vertex_outer);
  }
}

void* ugraph_vertex_data(ugraph_t* graph, size_t v) {
  ugraph_vertex_t* vertex;
  vertex = (ugraph_vertex_t*)graph->vertices->data[v];
  return vertex->data;
}

size_t ugraph_ecount(ugraph_t* graph) {
  ugraph_vertex_t* vertex;
  size_t i;
  size_t ne = 0;

  /* iterate over all vertices */
  for (i = 0; i < ugraph_vcount(graph); i++) {
    vertex = (ugraph_vertex_t*)graph->vertices->data[i];
    ne += hash_table_num_entries(vertex->edges);
  }
  return ne / 2;
}

size_t ugraph_vcount(ugraph_t* graph) { return graph->vertices->length; }
