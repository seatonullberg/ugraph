// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include "cvector.h"
#include "ugraph.h"
#include "utest.h"

UTEST(ugraph_tests, test_ugraph_new) {
    ugraph(int, int) *graph = ugraph_new(int, int);
    ASSERT_EQ(1, 1);
}

UTEST(ugraph_tests, test_ugraph_add_vertex) {
    ugraph(int, int) *graph = ugraph_new(int, int);
    ASSERT_EQ(ugraph_vcount(graph), 0);
    int* data = 0;
    ugraph_add_vertex(graph, data, int, int);
    ASSERT_EQ(ugraph_vcount(graph), 1);
}

// UTEST(ugraph_tests, test_ugraph_add_edge) {
//     ugraph_t* graph = ugraph_new();
//     ASSERT_EQ(ugraph_ecount(graph), 0);
//     int* data = 0;
//     ugraph_add_vertex(graph, data);
//     ugraph_add_vertex(graph, data);
//     ugraph_add_edge(graph, 0, 1, data);
//     ASSERT_EQ(ugraph_ecount(graph), 1);
// }