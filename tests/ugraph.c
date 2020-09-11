// ugraph - C89 undirected graph implementation
// Copyright (C) Seaton Ullberg and contributors -- MIT license

#include "cvector.h"
#include "ugraph.h"
#include "utest.h"

UTEST(ugraph_tests, test_ugraph_add_vertex) {
    ugraph_t* graph = ugraph_create();
    ASSERT_EQ(ugraph_vcount(graph), 0);
    int* data = 0;
    ugraph_add_vertex(graph, data);
    ASSERT_EQ(ugraph_vcount(graph), 1);
}