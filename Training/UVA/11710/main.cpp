#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_list(vector<vector<pair<sizet, sizet>>> a)
{
	sizet i = 0;
	for (auto x : a)
	{
		cerr << i++ << ": ";
		for (auto y : x)
		{
			cerr << "{" << y.first << "," << y.second << "} ";
		}
		cerr << endl;
	}
	cerr << endl;
}

class disjoint_set
{
	std::unique_ptr<size_t[]> parent, rank;

public:
	explicit disjoint_set(size_t n) : parent(new size_t[n]), rank(new size_t[n])
	{
		for (size_t x = 0; x != n; ++x)
		{
			parent[x] = x;
			rank[x] = 0;
		}
	}
	size_t find_set(size_t x)
	{
		if (parent[x] != x)
			parent[x] = find_set(parent[x]);
		return parent[x];
	}

	bool union_set(size_t x, size_t y)
	{
		x = find_set(x);
		y = find_set(y);
		if (x == y)
			return false;

		if (rank[x] < rank[y])
		{
			parent[x] = y;
		}
		else if (rank[x] > rank[y])
		{
			parent[y] = x;
		}
		else
		{
			parent[y] = x;
			++rank[x];
		}
		return true;
	}
};

class undirected_graph
{
	std::vector<std::vector<size_t>> adj_edges;
	std::vector<std::pair<size_t, size_t>> edge_list;

public:
	explicit undirected_graph(size_t num_vertices) : adj_edges(num_vertices) {}

	size_t add_edge(size_t u, size_t v)
	{
		edge_list.emplace_back(u, v);
		const size_t edge_id = edge_list.size() - 1;
		adj_edges[u].push_back(edge_id);
		adj_edges[v].push_back(edge_id);
		return edge_id;
	}

	size_t num_vertices() const
	{
		return adj_edges.size();
	}
	size_t num_edges() const
	{
		return edge_list.size();
	}

	size_t source(size_t e) const
	{
		return edge_list[e].first;
	}
	size_t target(size_t e) const
	{
		return edge_list[e].second;
	}

	const std::vector<size_t> &out_edges(size_t v) const
	{
		return adj_edges[v];
	}
	const std::vector<size_t> &in_edges(size_t v) const
	{
		return adj_edges[v];
	}

	size_t degree(size_t v) const
	{
		return adj_edges[v].size();
	}
	size_t out_degree(size_t v) const
	{
		return degree(v);
	}
	size_t in_degree(size_t v) const
	{
		return degree(v);
	}
};

template <typename Graph, typename Weight>
std::vector<size_t>
kruskal_minimum_spanning_tree(const Graph &g,
							  const std::vector<Weight> &weight)
{
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

	for (const auto e : edges)
	{
		if (dset.union_set(g.source(e), g.target(e)))
		{
			tree_edges.push_back(e);
			if (tree_edges.size() == max_tree_edges)
				break;
		}
	}

	return tree_edges;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet vertices, edges;
	while (true)
	{
		cin >> vertices >> edges;
		if (vertices == 0)
		{
			break;
		}
		unordered_map<string, sizet> stations;
		for (sizet i = 0; i < vertices; ++i)
		{
			string name;
			cin >> name;

			stations[name] = i;
		}

		undirected_graph g(vertices);
		vector<sizet> edge_weight;
		for (sizet i = 0; i < edges; ++i)
		{
			string u, v;
			sizet w;
			cin >> u >> v >> w;
			g.add_edge(stations[u], stations[v]);
			edge_weight.push_back(w);
		}
		//print_list(adj_list);
		string origin;
		cin >> origin;

		vector<bool> visited(vertices);
		function<void(sizet)> dfs;
		dfs = [&](sizet v) {
			if (visited[v])
			{
				return;
			}

			visited[v] = 1;
			for (auto edge : g.out_edges(v))
			{
				sizet to = (g.source(edge) == v) ? g.target(edge) : g.source(edge);
				dfs(to);
			}
		};

		dfs(stations[origin]);

		bool unreacheable = 0;
		for (sizet i = 0; i < vertices; ++i)
		{
			if (!visited[i])

			{
				unreacheable = 1;
				break;
			}
		}

		if (unreacheable)
		{
			cout << "Impossible\n";
		}
		else
		{
			auto mst_edges = kruskal_minimum_spanning_tree(g, edge_weight);
			sizet sum = 0;
			for (auto edge : mst_edges)
			{
				sum += edge_weight[edge];
			}
			cout << sum << "\n";
		}
	}
}
