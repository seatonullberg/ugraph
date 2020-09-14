// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include "ugraph.h"

#include <stddef.h> /* size_t */
#include <stdlib.h> /* malloc */

#include "arraylist.h"

ugraph_t* ugraph_new() {
  ugraph_t* graph = malloc(sizeof(ugraph_t));
  graph->vertices = arraylist_new(0);
  return graph;
}

void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data) {
  /* connect u to v */
  ugraph_edge_t* uedge = malloc(sizeof(ugraph_edge_t));
  uedge->data = NULL;
  uedge->vindex = v;
  /* connect v to u */
  ugraph_edge_t* vedge = malloc(sizeof(ugraph_edge_t));
  vedge->data = NULL;
  vedge->vindex = u;

  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];

  arraylist_append(uvertex->edges, uedge);
  arraylist_append(vvertex->edges, vedge);
}

void ugraph_add_vertex(ugraph_t* graph, void* data) {
  ugraph_vertex_t* vertex = malloc(sizeof(ugraph_vertex_t));
  vertex->data = data;
  vertex->edges = arraylist_new(0);
  arraylist_append(graph->vertices, vertex);
}

size_t ugraph_ecount(ugraph_t* graph) {
  ugraph_vertex_t* vertex;
  size_t ne = 0;

  size_t i;
  size_t nv = ugraph_vcount(graph);
  for (i = 0; i < nv; i++) {
    vertex = (ugraph_vertex_t*)graph->vertices->data[i];
    ne += vertex->edges->length;
  }
  return ne / 2;
}

size_t ugraph_vcount(ugraph_t* graph) { return graph->vertices->length; }
