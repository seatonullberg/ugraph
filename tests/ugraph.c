// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include "ugraph.h"

#include "utest.h"

UTEST(ugraph_tests, test_ugraph_new) {
  ugraph_t* graph = ugraph_new();
  ASSERT_EQ(ugraph_ecount(graph), 0);
  ASSERT_EQ(ugraph_vcount(graph), 0);
  ugraph_free(graph);
}

/* TODO: test adding same edge twice */
UTEST(ugraph_tests, test_ugraph_add_edge) {
  ugraph_t* graph = ugraph_new();
  int data = 0;
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_edge(graph, 0, 1, &data);
  ASSERT_EQ(ugraph_ecount(graph), 1);
  ugraph_free(graph);
}

/* TODO: test removing same edge twice */
UTEST(ugraph_tests, test_ugraph_remove_edge) {
  ugraph_t* graph = ugraph_new();
  int data = 0;
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_edge(graph, 0, 1, &data);
  ugraph_remove_edge(graph, 0, 1);
  ASSERT_EQ(ugraph_ecount(graph), 0);
  ugraph_free(graph);
}

UTEST(ugraph_tests, test_ugraph_add_vertex) {
  ugraph_t* graph = ugraph_new();
  ASSERT_EQ(ugraph_vcount(graph), 0);
  int data = 0;
  ugraph_add_vertex(graph, &data);
  ASSERT_EQ(ugraph_vcount(graph), 1);
  ugraph_free(graph);
}

UTEST(ugraph_tests, test_ugraph_remove_vertex) {
  ugraph_t* graph = ugraph_new();
  int data = 0;
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_edge(graph, 0, 1, &data);
  ugraph_add_edge(graph, 0, 3, &data);
  ugraph_add_edge(graph, 2, 1, &data);
  ugraph_add_edge(graph, 2, 3, &data);
  ugraph_add_edge(graph, 2, 4, &data);
  ugraph_remove_vertex(graph, 2);
  ASSERT_EQ(ugraph_ecount(graph), 2);
  ugraph_free(graph);
}