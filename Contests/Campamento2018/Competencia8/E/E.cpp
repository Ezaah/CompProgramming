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

template <typename Graph, typename Flow>
Flow edmonds_karp_max_flow(const Graph &g, const size_t source,
                           const size_t target,
                           const std::vector<size_t> &rev_edge,
                           const std::vector<Flow> &capacity,
                           std::vector<Flow> &residual,
                           vector<vector<size_t>> &paths) {

  static_assert(std::is_arithmetic<Flow>::value, "'Flow' must be arithmetic.");
  using edge_id = size_t;

  // last_bfs[v] stores the the last BFS tree that vertex v was part of.  Note
  // that the source vertex is present in all BFS trees as it is the root.
  std::vector<unsigned> last_bfs(g.num_vertices());
  std::vector<edge_id> pred(g.num_vertices(), SIZE_MAX);

  auto find_path = [&, source, target] {
    std::queue<size_t> bfs_queue;
    bfs_queue.push(source);
    const auto current_bfs = ++last_bfs[source];

    while (!bfs_queue.empty()) {
      const size_t curr = bfs_queue.front();
      bfs_queue.pop();
      for (const auto edge : g.out_edges(curr)) {
        const size_t child = g.target(edge);
        if (last_bfs[child] == current_bfs)
          continue; // Already in the tree.
        if (!residual[edge])
          continue; // Can't navigate through saturated edges.
        pred[child] = edge;
        if (child == target)
          return true;
        bfs_queue.push(child);
        last_bfs[child] = current_bfs;
      }
    }
    return false;
  };

  Flow total_flow = 0;
  residual = capacity;
  while (find_path()) {
    //	  cout << total_flow << " flow ! " << endl;
    Flow path_flow = std::numeric_limits<Flow>::max();
    vector<size_t> path;
    for (auto e = pred[target]; e != SIZE_MAX; e = pred[g.source(e)]) {
      //	    cout << g.source(e) << " " << g.target(e) <<endl;
      path_flow = std::min(path_flow, residual[e]);
    }
    for (auto e = pred[target]; e != SIZE_MAX; e = pred[g.source(e)]) {
      residual[e] -= path_flow;
      residual[rev_edge[e]] += path_flow;
      if (g.target(e) % 2 == 0)
        path.insert(path.begin(), g.target(e) / 2 + 1);
    }
    path.insert(path.begin(), 1);
    paths.push_back(path);
    total_flow += path_flow;
  }
  return total_flow;
}

inline std::vector<sizet> split(const std::string &str,
                                const std::string &sep) {
  std::vector<std::string> tokens;
  auto pos = str.find_first_not_of(sep);
  while (pos != std::string::npos) {
    auto end_pos = str.find_first_of(sep, pos + 1);
    tokens.emplace_back(str, pos, end_pos - pos);
    if (end_pos == std::string::npos)
      break;
    pos = str.find_first_not_of(sep, end_pos + 1);
  }

  vector<sizet> tok;
  for (auto &token : tokens) {
    tok.push_back(stoll(token));
  }
  return tok;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sizet cases = 1;
  string input;
  getline(cin, input);
  while (true) {
    vector<sizet> parameters = split(input, " ");
    undirected_graph graph(parameters[1] * 2);
    vector<sizet> capacity;
    vector<size_t> rev_edges;
    for (sizet i = 0; i < parameters[1]; ++i) {
      getline(cin, input);
      vector<sizet> roads = split(input, " ");
      for (auto &road : roads) {
        //	cout << "connecting " << i + parameters[1] <<" " <<road - 1
        //<<endl;
        auto e1 = graph.add_edge(2 * i + 1, 2 * (road - 1));
        auto e2 = graph.add_edge(2 * (road - 1), 2 * i + 1);
        capacity.push_back(1);
        capacity.push_back(0);
        rev_edges.push_back(e2);
        rev_edges.push_back(e1);
      }
      if(i == 0)
	      continue;
 //     	cout << "connecting " << 2*i << " " << 2*i +1 << endl;
      auto e1 = graph.add_edge(2 * i, 2 * i + 1);
      auto e2 = graph.add_edge(2 * i + 1, 2 * i);
      capacity.push_back(1);
      capacity.push_back(0);
      rev_edges.push_back(e2);
      rev_edges.push_back(e1);
    }
    auto e1 = graph.add_edge(0, 1);
    auto e2 = graph.add_edge(1, 0);
    capacity.push_back(parameters[0]);
    capacity.push_back(0);
    rev_edges.push_back(e2);
    rev_edges.push_back(e1);

    vector<sizet> residual;
    vector<vector<size_t>> paths;
    sizet flow = edmonds_karp_max_flow(graph, 1, 2, rev_edges, capacity,
                                       residual, paths);
   // cout << flow << endl;
    cout << "Case " << cases++ << ":\n";
    if (flow >= parameters[0]) {
      sort(paths.begin(), paths.end(),
           [](const vector<size_t> &a, const vector<size_t> &b) {
             if (a.size() == b.size()) {
               for (size_t i = 0; i < a.size(); ++i) {
                 if (a[i] > b[i]) {
                   return false;
                 }
               }
               return true;
             }
             return a.size() < b.size();
           });
      for (auto &path : paths) {
        if (!parameters[0])
          break;
        for (size_t i = 0; i < path.size(); ++i) {
          cout << path[i] << " ";
        }
        cout << "\n";
        --parameters[0];
      }
    } else {
      cout << "Impossible\n";
    }
    getline(cin, input);
    cout << "\n";
    if (input == "0 0") {
      break;
    }
  }
}
