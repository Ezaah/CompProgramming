#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

template <typename Weight>
class Graph
{
	std::vector<std::vector<std::pair<size_t, Weight>>> adj_list;

public:
	explicit Graph(size_t num_vertices) : adj_list(num_vertices) {}
	void add_edge(size_t u, size_t v, Weight w)
	{
		adj_list[u].push_back({v, w});
		adj_list[v].push_back({u, w});
	}

	size_t num_vertices() const { return adj_list.size(); }

	size_t degree(size_t v) const { return adj_list[v].size(); }

	const std::vector<std::pair<size_t, Weight>> &edges(size_t v) const
	{
		return adj_list[v];
	}
};

template <typename T, typename BinaryOp>
class segment_tree
{
	size_t num_elems{};
	BinaryOp op{};
	std::vector<T> tree{};

public:
	template <typename ForwardIt>
	void assign(ForwardIt first, ForwardIt last, BinaryOp comb = BinaryOp())
	{
		num_elems = std::distance(first, last);
		op = comb;
		tree.resize(2 * num_elems);
		if (!num_elems)
			return;
		std::copy(first, last, tree.begin() + num_elems);
		for (size_t i = num_elems - 1; i > 0; --i)
			tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
	}

	void modify(size_t pos, const T &new_value)
	{
		tree[pos += num_elems] = new_value;
		for (; pos > 1; pos >>= 1)
			tree[pos >> 1] = op(tree[pos], tree[pos ^ 1]);
	}

	T accumulate(size_t l, size_t r) const
	{
		T ans = at(l++);
		for (l += num_elems, r += num_elems; l < r; l >>= 1, r >>= 1)
		{
			if ((l & 1) != 0)
				ans = op(ans, tree[l++]);
			if ((r & 1) != 0)
				ans = op(ans, tree[--r]);
		}
		return ans;
	}

	const T &at(size_t pos) const
	{
		return tree[num_elems + pos];
	}

	size_t size() const
	{
		return num_elems;
	}
};

template <typename Weight, typename BinaryOp>
class heavy_light_decomposition
{

	std::vector<size_t> parent, depth;
	std::vector<size_t> head, chain_index, values_index;
	segment_tree<Weight, BinaryOp> stree;
	BinaryOp operation{};

public:
	template <typename Graph>
	heavy_light_decomposition(Graph &g, const size_t root)
	{
		const size_t num_vertices = g.num_vertices();
		// DFS Inits
		parent.resize(num_vertices);
		depth.resize(num_vertices);
		std::vector<size_t> subsizes(num_vertices, 1);
		std::vector<bool> visited(num_vertices);

		std::function<void(size_t)> dfs;
		dfs = [&](size_t u) {
			visited[u] = true;
			for (auto e : g.edges(u))
			{
				size_t child = e.first;
				if (visited[child])
					continue;
				depth[child] = depth[u] + 1;
				parent[child] = u;
				dfs(child);
				subsizes[u] += subsizes[child];
			}
		};
		dfs(root);

		// Decomposition Inits
		head.resize(num_vertices);
		chain_index.resize(num_vertices);
		values_index.resize(num_vertices);
		std::vector<Weight> values(num_vertices);
		size_t ptr = 0;
		size_t chain = 0;

		std::function<void(size_t, Weight, size_t)> decomposition;
		decomposition = [&](size_t u, Weight cost, size_t father) {
			chain_index[u] = chain;
			values_index[u] = ptr;
			values[ptr++] = cost;

			if (g.degree(u) == 1)
				return;

			size_t heavy_child, size = 0;
			Weight heavy_cost = Weight{0};
			for (auto e : g.edges(u))
			{
				size_t child = e.first;
				if (child != father && subsizes[child] > size)
				{
					size = subsizes[child];
					heavy_child = child;
					heavy_cost = e.second;
				}
			}
			head[heavy_child] = head[u];
			decomposition(heavy_child, heavy_cost, u);

			for (auto e : g.edges(u))
			{
				size_t child = e.first;
				if (child != father && child != heavy_child)
				{
					chain++;
					head[child] = child;
					decomposition(child, e.second, u);
				}
			}
		};
		decomposition(root, Weight{0}, root);

		// Segment Tree init
		stree.assign(values.begin(), values.end());
	}

	size_t lca(size_t u, size_t v) const
	{
		while (chain_index[u] != chain_index[v])
		{
			if (depth[head[u]] > depth[head[v]])
			{
				u = parent[head[u]];
			}
			else
			{
				v = parent[head[v]];
			}
		}
		return (depth[u] > depth[v]) ? v : u;
	}

	Weight query(const size_t u, const size_t v) const
	{
		const size_t middle = lca(u, v);

		std::function<Weight(size_t, size_t)> climb_chain;
		climb_chain = [&](size_t u, size_t v) {
			Weight ans = 0;
			while (true)
			{
				if (chain_index[u] == chain_index[v])
				{
					ans = operation(
						ans, stree.accumulate(values_index[v] + 1, values_index[u] + 1));
					break;
				}
				ans = operation(
					ans, stree.accumulate(values_index[head[u]], values_index[u] + 1));
				u = parent[head[u]];
			}
			return ans;
		};

		return operation(climb_chain(u, middle), climb_chain(v, middle));
	}
};

struct shallower
{
	const int &operator()(const int &lhs, const int &rhs) const
	{
		return lhs > rhs ? lhs : rhs;
	}
};

sizet mod_add(sizet a, sizet b, sizet m)
{
	if (a < m - b)
		return a + b;
	return a - (m - b);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet module = 1e9 + 7;
	sizet vertices;
	cin >> vertices;
	Graph<sizet> g(vertices);
	for (sizet i = 0; i < vertices - 1; ++i)
	{
		sizet u, v, w;
		cin >> u >> v >> w;
		g.add_edge(u - 1, v - 1, w);
	}

	heavy_light_decomposition<sizet, shallower> hld(g, 0);
	sizet sum = 0;
	for (sizet i = 0; i < vertices; ++i)
	{
		for (sizet j = i + 1; j < vertices; ++j)
		{
			sum = mod_add(sum, hld.query(i, j), module);
		}
	}

	cout << sum << endl;
}
