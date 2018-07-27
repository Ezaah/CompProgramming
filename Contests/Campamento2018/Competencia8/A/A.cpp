#include <bits/stdc++.h>
using namespace std;
typedef long long sizet;


/*
 * TLE :(
 * Posible optimizacion sin cambiar algoritmo: 
 * 	-> Hay muchas edges y muchos vertices (Asumo que la cantidad de edges es V^2, asique la opcion mas sensata es reducir los vertices)
 * 	-> En vez de tomar los intervalos de tiempo con un tamaño uno, hacerlos de forma que esten condensados.
 * 		-> Ej: Si tengo 2 intervalos (a, b) y (c, d) correspondientes a dos monos, Los puedo subdividir en intervalos en 4 casos:
 * 			-> Caso 1: b <= c. En ese caso los intervalos no se tocan y simplemente hago un vertice que cubra todo el intervalo (a,b) para que alimente al mono 1 (con un limite de b-a. Lo mismo para el intervalo (c,d).
 * 			-> Caso 2: a < c < b < d. En este caso los intervalos se solapan. Los puedo dividir en 3 intervalos (a, c), (c, b), (b, d). El intervalo (a,c) solo alimentara al mono 1,  el intervalo (b, d) solo al mono 2, y el intervalo (c, b) alimentara a ambos. (Se aplica la misma regla para la capacidad de las aristas).
 * 			-> Caso 3: (a, b) == (c, d). En ese caso ambos monos comparten totalmente todo el por lo que se hace un solo vertice para ese intervalo y que alimente a ambos monos.
 * 			-> Caso 4: (a, b) contenido en (c, d) o viceversa. En este caso se replica el caso 2 con los intervalos (a, c), (c, d), (d, b) alimentado a los monos correspondientes.
 *	-> En caso de que de TLE aun con esa optimizacion, habrá que buscar otro algoritmo que corra mas rapido de O(VE^2).
 * 
 * */

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

void debug_paths(sizet u, sizet v){
	cout << "connecting " << u << " with " << v << endl;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sizet n, m;
	sizet t = 0;
	while(cin >> n){
		t++;
		if(n == 0)
			break;
		cin >> m;
		vector<vector<sizet>> monkeys(n, vector<sizet>(3));
		sizet a = 1e9;
		sizet b = 0;
		for(sizet i = 0; i < n; ++i){
			cin >> monkeys[i][0] >> monkeys[i][1] >> monkeys[i][2];
			a = min(a, monkeys[i][1]);
			b = max(b, monkeys[i][2]);
		}

		directed_graph graph(2 + b-a + n);
		vector<size_t> rev_edges;
		vector<sizet> capacity;
		for(sizet i = 1; i <= b-a; ++i){
			auto e1 = graph.add_edge(0, i);
			auto e2 = graph.add_edge(i , 0);
			capacity.push_back(m);
			capacity.push_back(0);
			rev_edges.push_back(e2);
			rev_edges.push_back(e1);
		}
		vector<size_t> checkers(n);
		for(sizet i = 0; i < n ; i++){
			for(sizet k = monkeys[i][1] - a + 1; k < monkeys[i][2] - a + 1; ++k){ 
				auto e1 = graph.add_edge(k, b - a + i + 1);
				auto e2 = graph.add_edge(b - a + i + 1, k);
				capacity.push_back(1);
				capacity.push_back(0);
				rev_edges.push_back(e2);
				rev_edges.push_back(e1);
			}
			auto e1 = graph.add_edge(b - a + i + 1, b - a + n + 1);
			auto e2 = graph.add_edge(b - a + n + 1, b - a + i + 1);
			capacity.push_back(monkeys[i][0]);
			capacity.push_back(0);
			rev_edges.push_back(e2);
			rev_edges.push_back(e1);
			checkers[i] = e1;
		}

		vector<sizet> residual;
		edmonds_karp_max_flow(graph, 0, b - a + n + 1, rev_edges, capacity, residual);
		bool flag = 0;
		for(sizet i = 0; i < n; ++i){
			if(monkeys[i][0] - capacity[checkers[i]] + residual[checkers[i]]){
				flag = 1;
			}
		}
		if(flag){
			cout << "Case " << t << ": No\n";
			continue;
		}
		vector<vector<sizet>> times(b-a);
		for(sizet i = b - a + 1; i < graph.num_vertices() - 1; ++i){
			for(auto &edge : graph.in_edges(i)){
				if(capacity[edge] - residual[edge] == 1){
					times[graph.source(edge) - 1].push_back(i);
				}
			}
		}
		vector<vector<pair<sizet,sizet>>> drinkings(n);
		for(sizet i = 0; i < b-a; ++i){
			for(sizet k = 0; k < times[i].size(); k++){
				sizet monkey = times[i][k] - (b -a + 1);
				if(drinkings[monkey].size()){
					if(drinkings[monkey].back().second == a + i){
						drinkings[monkey].back().second++;
						continue;
					}
				}
				drinkings[monkey].push_back({a+i, a+i+1});
			}
		}
		cout << "Case " << t << ": Yes\n";
		for(auto &monkey : drinkings){
			cout << monkey.size();
			for(auto &time : monkey){
				cout << " ("<<time.first << "," << time.second << ")";
			}
			cout << "\n";
		}
	}
}
