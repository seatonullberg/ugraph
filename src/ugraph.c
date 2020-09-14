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

// void ugraph_free(ugraph_t* graph) {
//   ArrayList *edges;
//   ugraph_edge_t* edge;
//   size_t nv = ugraph_vcount(graph);

//   size_t i, j;
//   for (i = 0; i < nv; i++) {
//     edges = (ArrayList *)graph->vertices->data[i];
//     for (j = 0; j < edges->length; j++) {
//       edge = (ugraph_edge_t *)edges->data[j];
//       /* free the edge's associated data */
//       free(edge->data);
//     }
//   }
// }

void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data) {
  /* access vertices */
  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];
  /* connect u to v */
  ugraph_edge_t* uedge = malloc(sizeof(ugraph_edge_t));
  uedge->data = data;
  uedge->endpoint = v;
  /* connect v to u */
  ugraph_edge_t* vedge = malloc(sizeof(ugraph_edge_t));
  vedge->data = data;
  vedge->endpoint = u;
  /* push new edges onto appropriate vertices */
  arraylist_append(uvertex->edges, uedge);
  arraylist_append(vvertex->edges, vedge);
}

void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v) {
  size_t i;
  ArrayList *uedges;
  ugraph_edge_t* uedge;
  ArrayList *vedges;
  ugraph_edge_t* vedge;
  /* access vertices */
  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];
  /* remove v from u */
  uedges = uvertex->edges;
  for (i = 0; i < uedges->length; i++) {
    uedge = (ugraph_edge_t*)uedges->data[i];
    if (uedge->endpoint == v) {
      arraylist_remove(uedges, i);
      break;
    }
  }
  /* remove u from v */
  vedges = vvertex->edges;
  for (i = 0; i < vedges->length; i++) {
    vedge = (ugraph_edge_t*)vedges->data[i];
    if (vedge->endpoint == u) {
      arraylist_remove(vedges, i);
      break;
    }
  }
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
