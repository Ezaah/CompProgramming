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

void debug_paths(sizet a, sizet b){
	cout << "connecting " << a << " with " << b << endl;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	map<char, sizet> computers = { {'0', 1}, {'1', 2}, {'2', 3},{'3', 4},{'4',5},{'5', 6},{'6', 7},  {'7', 8}, {'8', 9}, {'9', 10}};
	string input;
	while(getline(cin, input)){
		vector<string> inputs = { input};
		while(getline(cin, input)){
			if(input == ""){
				break;
			}
			inputs.push_back(input);
		}
		directed_graph graph(2 + 10 + inputs.size());
		vector<size_t> rev_edges;
		vector<sizet> capacity;
		map<char, sizet> process;
		for(sizet i = 0; i < inputs.size(); ++i){
			process[inputs[i][0]] = 11 + i;
			auto e1 = graph.add_edge(11 + i, graph.num_vertices() -1);
			auto e2 = graph.add_edge( graph.num_vertices() - 1, 11 + i);
			capacity.push_back(inputs[i][1] - '0');
			capacity.push_back(0);
			rev_edges.push_back(e2);
			rev_edges.push_back(e1);
			for(sizet k = 3; k < inputs[i].size() -1; ++k){
				e1 = graph.add_edge(computers[inputs[i][k]], 11 + i);
				e2 = graph.add_edge(11 + i, computers[inputs[i][k]]);
				capacity.push_back(1);
				capacity.push_back(0);
				rev_edges.push_back(e2);
				rev_edges.push_back(e1);
			}
		}

		for(sizet i = 1; i < 11; ++i){
		       auto e1 = graph.add_edge(0, i);
		       auto e2 = graph.add_edge(i, 0);
		       capacity.push_back(1);
		       capacity.push_back(0);
		       rev_edges.push_back(e2);
		       rev_edges.push_back(e1);
		}
		vector<sizet> residual;
		edmonds_karp_max_flow(graph, 0, graph.num_vertices() -1, rev_edges, capacity, residual);
		bool possible = 0;
		for(auto &value : process){
			for(auto &edge : graph.out_edges(value.second)){
				if(capacity[edge] && residual[edge] > 0)
					possible = 1;
			}
		}
		if(possible){
			cout << "!\n";
		}else{
			vector<char> assignations(10, '_');
			for(sizet i = 1; i < 11; ++i){
				for(auto &edge : graph.out_edges(i)){
					if(capacity[edge] && !residual[edge])
						assignations[i-1] = inputs[graph.target(edge) - 11][0];
				}
				cout << assignations[i-1];
			}
			cout << "\n";

		}


	}

}	
