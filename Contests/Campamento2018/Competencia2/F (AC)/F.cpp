#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

class DGraph {
  vector<vector<pair<sizet, sizet>>> adj_list;

public:
  DGraph(const sizet num_vertices) : adj_list(num_vertices) {}

  void add_edge(const sizet u, const sizet v, const sizet w) {
    adj_list[u].push_back({v, w});
    adj_list[v].push_back({u, w});
  }

  const sizet num_vertices() { return adj_list.size(); }
  vector<pair<sizet, sizet>> edges(const sizet u) { return adj_list[u]; }
};

vector<pair<sizet, sizet>> dijkstra(sizet origin, DGraph &g) {
  const sizet num_vertices = g.num_vertices();
  vector<pair<sizet, sizet>> distances(num_vertices, {1e13, -1});
  vector<bool> visited(num_vertices, 0);
  distances[origin] = {0, -1};
  priority_queue<pair<sizet, sizet>, vector<pair<sizet, sizet>>,
                 greater<pair<sizet, sizet>>>
      pq;
  pq.push({0, origin});

  while (!pq.empty()) {
    sizet u = pq.top().second;
    pq.pop();
    if (visited[u]) {
      continue;
    }
    visited[u] = 1;
    for (auto edge : g.edges(u)) {
      const sizet v = edge.first;
      const sizet w = edge.second;
      if (distances[v].first > distances[u].first + w) {
        distances[v] = {distances[u].first + w, u};
        pq.push({distances[v].first, v});
      }
    }
  }

  return distances;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sizet vertices, edges;
  cin >> vertices >> edges;
  DGraph graph(vertices);
  for (sizet i = 0; i < edges; ++i) {
    sizet u, v, w;
    cin >> u >> v >> w;
    graph.add_edge(--u, --v, w);
  }

  vector<pair<sizet, sizet>> distances = dijkstra(0, graph);
  sizet vertex = vertices - 1;
  vector<sizet> answer;

  if (distances[vertex].second != -1) {
    answer.push_back(vertex + 1);
  } else {
    answer.push_back(-1);
    vertex = -1;
  }
  while (vertex != -1) {
    if (vertex != 0) {
      answer.push_back(distances[vertex].second + 1);
    }
    vertex = distances[vertex].second;
  }

  for (sizet i = answer.size() - 1; i >= 0; --i) {
    cout << answer[i];
    if (i != 0)
      cout << " ";
  }
  cout << "\n";
}
