# ugraph

C89 undirected graph implementation.

## Usage

`ugraph` exposes a simple yet flexible API for constructing and querying undirected graphs. Each vertex and edge can hold a `void *` field for users to store generic data directly in the graph. Edges between vertices are implemented as a `HashTable`. This design choice means that each pair of vertices may have 0 or 1 edges between them, but never more.

The [unit tests](tests/ugraph.c) and [benchmark suite](benches/ugraph.c) serve as examples of how to appropriately use the API.

The code can be built as a shared library by running `make shared` in the parent directory.