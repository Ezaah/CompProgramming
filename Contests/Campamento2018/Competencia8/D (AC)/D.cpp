#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

class undirected_graph {
  std::vector<std::vector<size_t>> adj_edges;
  std::vector<std::pair<size_t, size_t>> edge_list;

public:
  explicit undirected_graph(size_t num_vertices) : adj_edges(num_vertices) {}

  size_t add_edge(size_t u, size_t v) {
    edge_list.emplace_back(u, v);
    const size_t edge_id = edge_list.size() - 1;
    adj_edges[u].push_back(edge_id);
    adj_edges[v].push_back(edge_id);
    return edge_id;
  }

  size_t num_vertices() const { return adj_edges.size(); }
  size_t num_edges() const { return edge_list.size(); }

  size_t source(size_t e) const { return edge_list[e].first; }
  size_t target(size_t e) const { return edge_list[e].second; }

  const std::vector<size_t> &out_edges(size_t v) const { return adj_edges[v]; }
  const std::vector<size_t> &in_edges(size_t v) const { return adj_edges[v]; }

  size_t degree(size_t v) const { return adj_edges[v].size(); }
  size_t out_degree(size_t v) const { return degree(v); }
  size_t in_degree(size_t v) const { return degree(v); }
};

template <typename Graph>
std::size_t hopcroft_karp_maximum_matching(const Graph &g) {
  // Note: pair_of can be used to query the selected pairs.
  const size_t num_vertices = g.num_vertices();
  const size_t nil = num_vertices; // The null vertex
  std::vector<size_t> pair_of(num_vertices, nil);
  std::vector<size_t> dist(num_vertices + 1);
  std::vector<size_t> set_a, set_b;

  auto separate_vertices = [&] {
    std::vector<signed char> color(num_vertices);
    std::function<void(size_t)> dfs_visit;
    dfs_visit = [&](const size_t u) {
      color[u] == 1 ? set_a.push_back(u) : set_b.push_back(u);
      for (const auto e : g.out_edges(u)) {
        const size_t v = (u == g.source(e)) ? g.target(e) : g.source(e);
        if (color[v])
          continue;
        color[v] = -color[u];
        dfs_visit(v);
      }
    };
    for (size_t v = 0; v < num_vertices; ++v) {
      if (color[v] != 0)
        continue;
      color[v] = 1;
      dfs_visit(v);
    }
  };
  auto bfs = [&] {
    std::queue<size_t> q;
    for (const size_t a : set_a) {
      if (pair_of[a] == nil) {
        dist[a] = 0;
        q.push(a);
      } else
        dist[a] = SIZE_MAX;
    }
    dist[nil] = SIZE_MAX;
    while (!q.empty()) {
      const size_t a = q.front();
      q.pop();
      if (dist[a] >= dist[nil])
        continue;
      for (const auto e : g.out_edges(a)) {
        const size_t b = (a == g.source(e)) ? g.target(e) : g.source(e);
        if (dist[pair_of[b]] != SIZE_MAX)
          continue;
        dist[pair_of[b]] = dist[a] + 1;
        q.push(pair_of[b]);
      }
    }
    return dist[nil] != SIZE_MAX;
  };
  std::function<bool(size_t)> dfs = [&](const size_t a) {
    if (a == nil)
      return true;
    for (const auto e : g.out_edges(a)) {
      const auto b = (a == g.source(e)) ? g.target(e) : g.source(e);
      if (dist[pair_of[b]] != dist[a] + 1)
        continue;
      if (!dfs(pair_of[b]))
        continue;
      pair_of[b] = a;
      pair_of[a] = b;
      return true;
    }
    dist[a] = SIZE_MAX;
    return false;
  };

  separate_vertices();
  size_t num_matching = 0;
  while (bfs()) {
    for (const size_t a : set_a)
      if (pair_of[a] == nil && dfs(a))
        ++num_matching;
  }
  return num_matching;
}

struct student {
  sizet height;
  char gender;
  string music;
  string sport;
};

bool can_be(student &a, student &b) {
  return !(abs(a.height - b.height) > 40 || a.gender == b.gender ||
           a.music != b.music || a.sport == b.sport);
}

void debug_paths(sizet a, sizet b) {
  cout << "connecting " << a << " with " << b << endl;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sizet cases;
  cin >> cases;
  while (cases--) {
    sizet students;
    cin >> students;
    vector<student> males;
    vector<student> females;
    undirected_graph graph(students);
    for (sizet i = 0; i < students; ++i) {
      sizet height;
      char gender;
      string music, sport;
      cin >> height >> gender >> music >> sport;
      if (gender == 'M')
        males.push_back({height, gender, music, sport});
      else
        females.push_back({height, gender, music, sport});
    }

    for (sizet i = 0; i < males.size(); ++i) {
      for (sizet j = 0; j < females.size(); ++j) {
        if (can_be(males[i], females[j])) {
          //  debug_paths(i, males.size() + j);
          graph.add_edge(i, males.size() + j);
        }
      }
    }

    cout << students - hopcroft_karp_maximum_matching(graph) << "\n";
  }
}
