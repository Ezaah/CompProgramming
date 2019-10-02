#include <bits/stdc++.h>

class directed_graph {
  std::vector<std::vector<size_t>> outedges, inedges;

public:
  directed_graph(size_t n_verts) : outedges(n_verts), inedges(n_verts) {}
  void add_edge(size_t src, size_t tgt) {
    outedges[src].push_back(tgt);
    inedges[tgt].push_back(src);
  }

  size_t num_vertices() const { return outedges.size(); }

  const std::vector<size_t> &out_edges(size_t v) const { return outedges[v]; }
  const std::vector<size_t> &in_edges(size_t v) const { return inedges[v]; }
};
template <typename Graph> std::vector<bool> dfs(Graph &g, size_t src) {
  const size_t num_vertices = g.num_vertices();
  std::vector<bool> visited(num_vertices);
  visited[src] = 1;

  std::function<void(size_t)> dfs_visit;
  dfs_visit = [&](size_t vert) {
    for (size_t u : g.out_edges(vert)) {
      if (visited[u])
        continue;
      visited[u] = 1;
      dfs_visit(u);
    }
  };
  dfs_visit(src);
  return visited;
}
size_t char2int(char letter) { return letter - 97; }
int main() {
  size_t edges, words;
  while (std::cin >> edges >> words) {
    directed_graph graph(26);
    for (size_t i = 0; i < edges; ++i) {
      char a, b;
      std::cin >> a >> b;
      graph.add_edge(char2int(a), char2int(b));
    }
    for (size_t i = 0; i < words; ++i) {
      std::string query, match;
      std::cin >> query >> match;
      bool not_breaked = 1;
      if (query.size() != match.size()) {
        std::cout << "no\n";
        continue;
      }
      not_breaked = 1;
      for (size_t k = 0; k < query.size(); ++k) {
        std::vector<bool> visited = dfs(graph, char2int(query[k]));
        if (!visited[char2int(match[k])]) {
          not_breaked = 0;
          std::cout << "no\n";
          break;
        }
      }
      if (not_breaked) {
        std::cout << "yes\n";
      }
    }
  }
}
