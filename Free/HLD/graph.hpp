#include <bits/stdc++.h>

// Weighted undirected graph
template <typename Weight> class Graph {
  std::vector<std::vector<std::pair<size_t, Weight>>> adj_list;

public:
  explicit Graph(size_t num_vertices) : adj_list(num_vertices) {}
  void add_edge(size_t u, size_t v, Weight w) {
    adj_list[u].push_back({v, w});
    adj_list[v].push_back({u, w});
  }

  size_t num_vertices() const { return adj_list.size(); }

  size_t degree(size_t v) const { return adj_list[v].size(); }

  const std::vector<std::pair<size_t, Weight>> &edges(size_t v) const {
    return adj_list[v];
  }
};
