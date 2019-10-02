#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;


double dist(pair<double, double>& a, pair<double, double>& b){
	return sqrt( (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second) );
}
class disjoint_set {
  std::unique_ptr<size_t[]> parent, rank;

public:
  /// \brief Constructs a disjoint-set object.
  ///
  /// Creates \p n elements indexed with integers from \c 0 to <tt>n - 1</tt>.
  /// Initially, each element belongs to a singleton set (make-set is done for
  /// each of them).
  ///
  /// \param n The number of elements to be used.
  ///
  /// \par Complexity
  /// Linear in the number of elements.
  ///
  explicit disjoint_set(size_t n) : parent(new size_t[n]), rank(new size_t[n]) {
    for (size_t x = 0; x != n; ++x) {
      parent[x] = x;
      rank[x] = 0;
    }
  }

  /// \brief Finds the representative element of the set containing \p x.
  ///
  /// \param x Member of the set to be searched.
  ///
  /// \returns The index of the representative element of the searched set.
  ///
  /// \par Complexity
  /// The amortized complexity is constant.
  ///
  size_t find_set(size_t x) {
    if (parent[x] != x)
      parent[x] = find_set(parent[x]);
    return parent[x];
  }

  /// \brief Merges the set containing \p x with the set containing \p y.
  ///
  /// \param x Member of the first set.
  /// \param y Member of the second set.
  ///
  /// \returns \c true if \p x and \p y were part of different sets so an union
  /// was made. Otherwise \c false.
  ///
  /// \par Complexity
  /// The amortized complexity is constant.
  ///
  bool union_set(size_t x, size_t y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y)
      return false;

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else if (rank[x] > rank[y]) {
      parent[y] = x;
    } else {
      parent[y] = x;
      ++rank[x];
    }
    return true;
  }
};
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

  size_t num_vertices() const {
    return adj_edges.size();
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
    return adj_edges[v];
  }
  const std::vector<size_t>& in_edges(size_t v) const {
    return adj_edges[v];
  }

  size_t degree(size_t v) const {
    return adj_edges[v].size();
  }
  size_t out_degree(size_t v) const {
    return degree(v);
  }
  size_t in_degree(size_t v) const {
    return degree(v);
  }
};

template <typename Graph, typename Weight>
std::vector<size_t>
kruskal_minimum_spanning_tree(const Graph& g,
                              const std::vector<Weight>& weight) {
  const size_t num_vertices = g.num_vertices();
  if (num_vertices == 0)
    return {};

  std::vector<size_t> edges(g.num_edges());
  std::iota(edges.begin(), edges.end(), size_t{0});

  std::sort(edges.begin(), edges.end(),
            [&](size_t lhs, size_t rhs) { return weight[lhs] < weight[rhs]; });

  disjoint_set dset(num_vertices);

  const size_t max_tree_edges = num_vertices - 1;
  std::vector<size_t> tree_edges;
  tree_edges.reserve(max_tree_edges);

  for (const auto e : edges) {
    if (dset.union_set(g.source(e), g.target(e))) {
      tree_edges.push_back(e);
      if (tree_edges.size() == max_tree_edges)
        break;
    }
  }

  return tree_edges;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sizet tests;
	cin >> tests;
	while(tests--){
		sizet n;
		cin >> n;
		vector<pair<double, double>> points;
		for(sizet i = 0; i < n; ++i){
			double x, y;
			cin >> x >> y;
			points.push_back({x,y});
		}
		undirected_graph graph(n);
		vector<double> weights;
		for(sizet i = 0; i < n; ++i){
			for(sizet j = i+1; j < n; ++j){
				graph.add_edge(i, j);
				weights.push_back(dist(points[i], points[j]));
			}
		}

		vector<size_t> dists = kruskal_minimum_spanning_tree(graph, weights);
		double sum = 0;
		for(auto& edge : dists){
			sum+=weights[edge];
		}
		printf("%.2f\n", sum);
		if(tests > 0){
			printf("\n");
		}

	}
}
