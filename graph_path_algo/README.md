ChatGPT Summary
---

# Overview
This C++ program implements a directed graph and uses the Floyd-Warshall algorithm to compute the shortest paths between all pairs of vertices. The graph is flexible, allowing for weighted edges and potential future enhancements like custom distance functions, handling self-loops, and supporting multiple edges between the same vertices.

# Key Features
- **Graph Representation**: The graph is stored as an adjacency list using nested unordered maps, which efficiently handles sparse connections between vertices.
- **Directed vs. Undirected**: The graph can be initialized as either directed or undirected, with the adjacency list automatically reflecting this choice.
- **Shortest Path Calculation**: The Floyd-Warshall algorithm is implemented to compute the shortest paths. It updates a distance matrix iteratively, considering every possible path between vertex pairs to ensure the minimum distance is found.
- **Adjacency Matrix Generation**: An adjacency matrix is created from the adjacency list, with distances initialized to infinity (or a large value) and self-distances set to zero. This matrix serves as the basis for the Floyd-Warshall algorithm.
- **Extensibility**: The code is designed with future enhancements in mind, including the ability to handle more complex graph structures and distance calculations.

# Performance
- **Adjacency Matrix**:
  - Time Complexity: O(`V^2`) to initialize and populate the matrix.
  - Space Complexity: O(`V^2`) to store the matrix.
- **Floyd-Warshall Algorithm**:
  - Time Complexity: O(`V^3`) due to the triple nested loop structure, iterating over all vertex pairs.
  - Space Complexity: O(`V^2`) for the distance matrix used in the algorithm.

# Usage Considerations
- The current implementation is best suited for small to medium-sized graphs due to the O(`V^3`) time complexity of the Floyd-Warshall algorithm.
- Future enhancements could include custom distance functions and more efficient handling of larger graphs.
