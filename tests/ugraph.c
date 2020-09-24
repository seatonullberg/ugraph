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

#include "utest.h"

UTEST(ugraph_tests, test_ugraph_new) {
  ugraph_t* graph = ugraph_new();
  ASSERT_EQ(ugraph_ecount(graph), 0);
  ASSERT_EQ(ugraph_vcount(graph), 0);
  ugraph_free(graph);
}

UTEST(ugraph_tests, test_ugraph_add_edge) {
  ugraph_t* graph = ugraph_new();
  int data = 0;
  ugraph_add_vertex(graph, &data);
  ugraph_add_vertex(graph, &data);
  ugraph_add_edge(graph, 0, 1, &data);
  ASSERT_EQ(ugraph_ecount(graph), 1);
  ASSERT_EQ(ugraph_edge_data(graph, 0, 1), &data);
  ugraph_free(graph);
}

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
  ASSERT_EQ(ugraph_vertex_data(graph, 0), &data);
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