# ugraph

C89 undirected graph implementation.
`ugraph` exposes a simple yet flexible API for constructing and querying undirected graphs.
Each vertex and edge stores a `void *` field. 
This implementation supports a maximum of 1 edge per vertex pair.


## Installation

`ugraph` uses the [Meson](https://mesonbuild.com/) build system. 
Clone the code directly from source and Meson will handle the rest.

```
$ git clone https://github.com/seatonullberg/ugraph && cd ugraph
$ meson build && cd build
$ meson compile
$ meson test
$ meson install
```

For best performance replace `meson build` with `meson build --buildtype=release`.


## Example

This small example script showcases all of `ugraph`'s functionality.

```c
#include <assert.h>
#include <ugraph.h>

int main(int argc, char *argv[]) {
    // initialize an empty graph
    ugraph_t* graph = ugraph_new();

    // insert some vertices
    int vdata = 1;
    ugraph_insert_vertex(graph, &vdata);
    ugraph_insert_vertex(graph, &vdata);

    // count the number of vertices in the graph
    assert(ugraph_vcount(graph) == 2);

    // fetch data from a vertex
    assert(ugraph_get_vertex_data(graph, 0) == &vdata);

    // insert an edge between the vertices
    double edata = 2.5;
    ugraph_insert_edge(graph, 0, 1, &edata);

    // count the number of edges in the graph
    assert(ugraph_ecount(graph) == 1);

    // fetch data from an edge
    assert(ugraph_get_edge_data(graph, 0, 1) == &edata);

    // free the graph's memory
    ugraph_free(graph);

    return 0;
}
```
