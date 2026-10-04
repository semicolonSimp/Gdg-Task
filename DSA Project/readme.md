# Design Decisions

## Decision: Use Dijkstra instead of BFS

The campus graph contains weighted edges where each edge represents
distance or travel cost between two locations.

BFS is suitable for unweighted graphs, but it does not correctly
handle different edge weights.

Therefore, Dijkstra's algorithm was selected.

## Edge Case

If the destination cannot be reached from the selected starting
location, the system displays:

"No route exists."

## Graph Representation

An adjacency list was selected instead of an adjacency matrix
because the campus graph is expected to be sparse.