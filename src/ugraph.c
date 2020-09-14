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

void ugraph_edge_t_free(ugraph_edge_t* edge) {
  free(edge);
}

void ugraph_vertex_t_free(ugraph_vertex_t* vertex) {
  ugraph_edge_t* edge;
  size_t i;
  for (i = 0; i < vertex->edges->length; i++) {
    edge = (ugraph_edge_t*)vertex->edges->data[i];
    ugraph_edge_t_free(edge);
  }
  arraylist_free(vertex->edges);
  free(vertex);
}

void ugraph_free(ugraph_t* graph) {
  ugraph_vertex_t* vertex;
  size_t nv = ugraph_vcount(graph);
  size_t i;
  for (i = 0; i < nv; i++) {
    vertex = (ugraph_vertex_t*)graph->vertices->data[i];
    ugraph_vertex_t_free(vertex);
  }
  arraylist_free(graph->vertices);
  free(graph);
}

void ugraph_add_edge(ugraph_t* graph, size_t u, size_t v, void* data) {
  /* access vertices */
  ugraph_vertex_t* uvertex;
  ugraph_vertex_t* vvertex;
  uvertex = (ugraph_vertex_t*)graph->vertices->data[u];
  vvertex = (ugraph_vertex_t*)graph->vertices->data[v];
  /* connect u to v */
  ugraph_edge_t* uedge = malloc(sizeof(ugraph_edge_t));
  uedge->data = data;
  uedge->endpoint = vvertex;
  /* connect v to u */
  ugraph_edge_t* vedge = malloc(sizeof(ugraph_edge_t));
  vedge->data = data;
  vedge->endpoint = uvertex;
  /* push new edges onto appropriate vertices */
  arraylist_append(uvertex->edges, uedge);
  arraylist_append(vvertex->edges, vedge);
}

void ugraph_remove_edge(ugraph_t* graph, size_t u, size_t v) {
  size_t i;
  ArrayList* uedges;
  ugraph_edge_t* uedge;
  ArrayList* vedges;
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
    if (uedge->endpoint == vvertex) {
      ugraph_edge_t_free(uedge);
      arraylist_remove(uedges, i);
      break;
    }
  }
  /* remove u from v */
  vedges = vvertex->edges;
  for (i = 0; i < vedges->length; i++) {
    vedge = (ugraph_edge_t*)vedges->data[i];
    if (vedge->endpoint == uvertex) {
      ugraph_edge_t_free(vedge);
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

void ugraph_remove_vertex(ugraph_t* graph, size_t v) {
  ugraph_edge_t* edge;
  ugraph_vertex_t* vertex;
  ugraph_vertex_t* _vertex;
  /* remove the offending vertex */
  vertex = (ugraph_vertex_t*)graph->vertices->data[v];
  ugraph_vertex_t_free(vertex);
  arraylist_remove(graph->vertices, v);
  /* update all edges */
  size_t i, j;
  for (i = 0; i < ugraph_vcount(graph); i++) {
    _vertex = (ugraph_vertex_t*)graph->vertices->data[i];
    for (j = 0; j < _vertex->edges->length; j++) {
      edge = (ugraph_edge_t*)_vertex->edges->data[j];
      /* TODO: break out a small function for this */
      if (edge->endpoint == vertex) {
        ugraph_edge_t_free(edge);
        arraylist_remove(_vertex->edges, j);
      }
    }
  }
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
