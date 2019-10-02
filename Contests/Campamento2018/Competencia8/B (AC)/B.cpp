#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;

class directed_graph {
  std::vector<std::vector<size_t>> outedges, inedges;
  std::vector<std::pair<size_t, size_t>> edge_list;

public:
  explicit directed_graph(size_t n_verts)
      : outedges(n_verts), inedges(n_verts) {}

  size_t add_edge(size_t src, size_t tgt) {
    edge_list.emplace_back(src, tgt);
    const size_t edge_id = edge_list.size() - 1;
    outedges[src].push_back(edge_id);
    inedges[tgt].push_back(edge_id);
    return edge_id;
  }

  size_t num_vertices() const {
    return outedges.size();
  }
  size_t num_edges() const {
    return edge_list.size();
  }

  size_t source(size_t e) const {
    return edge_list[e].first;
  }
  size_t target(size_t e) const {
    return edge_list[e].second;
  }

  const std::vector<size_t>& out_edges(size_t v) const {
    return outedges[v];
  }
  const std::vector<size_t>& in_edges(size_t v) const {
    return inedges[v];
  }

  size_t out_degree(size_t v) const {
    return outedges[v].size();
  }
  size_t in_degree(size_t v) const {
    return inedges[v].size();
  }
};

template <typename Graph, typename Flow>
Flow edmonds_karp_max_flow(const Graph& g, const size_t source,
                           const size_t target,
                           const std::vector<size_t>& rev_edge,
                           const std::vector<Flow>& capacity,
                           std::vector<Flow>& residual) {

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
    Flow path_flow = std::numeric_limits<Flow>::max();
    for (auto e = pred[target]; e != SIZE_MAX; e = pred[g.source(e)]) {
      path_flow = std::min(path_flow, residual[e]);
    }
    for (auto e = pred[target]; e != SIZE_MAX; e = pred[g.source(e)]) {
      residual[e] -= path_flow;
      residual[rev_edge[e]] += path_flow;
    }
    total_flow += path_flow;
  }
  return total_flow;
}

template <typename Graph, typename Flow>
Flow min_st_cut(const Graph& g, const size_t source, const size_t target,
                const std::vector<size_t>& rev_edge,
                const std::vector<Flow>& capacity,
                std::vector<bool>& source_side) {

  std::vector<Flow> residual;
  const auto max_flow =
      edmonds_karp_max_flow(g, source, target, rev_edge, capacity, residual);

  source_side.assign(g.num_vertices(), false);
  std::stack<size_t> stack;

  source_side[source] = true;
  stack.push(source);
  while (!stack.empty()) {
    const size_t current = stack.top();
    stack.pop();
    for (const auto edge : g.out_edges(current)) {
      const size_t neighbor = g.target(edge);
      if (source_side[neighbor])
        continue; // Already discovered.
      if (!residual[edge])
        continue; // Can't navigate through saturated edges.
      source_side[neighbor] = true;
      stack.push(neighbor);
    }
  }
  return max_flow;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sizet vertices, edges;
	cin >> vertices >> edges;
	while(true){
		if(vertices == 0 && edges == 0){
			break;
		}

		directed_graph graph(vertices);
		vector<size_t> rev_edges;
		vector<sizet> capacity;
		for(sizet i = 0; i < edges; ++i){
			sizet a, b, c;
			cin >> a >> b >> c;
			b--; a--;
			auto e1 = graph.add_edge(a, b);
			auto e2 = graph.add_edge(b, a);
			capacity.push_back(c);
			capacity.push_back(0);
			rev_edges.push_back(e2);
			rev_edges.push_back(e1);

			e1 = graph.add_edge(b, a);
			e2 = graph.add_edge(a, b);
			capacity.push_back(c);
			capacity.push_back(0);
			rev_edges.push_back(e2);
			rev_edges.push_back(e1);
		}

		vector<bool> source_side;
		min_st_cut(graph, 0, 1, rev_edges, capacity, source_side);

		for(sizet edge = 0; edge < graph.num_edges(); edge +=2){
			if(source_side[graph.source(edge)] && !source_side[graph.target(edge)]){
				cout << graph.source(edge) + 1 << " " << graph.target(edge) + 1 << "\n";
			}
		}
		cin >> vertices >> edges;
		if(vertices != 0  && edges != 0){
			cout << "\n";
		}
	}
}
