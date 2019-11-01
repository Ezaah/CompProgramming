#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

template <typename BinaryOp>
class segment_tree
{
	size_t num_elems{};
	BinaryOp op{};
	std::vector<sizet> tree{};

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

	void modify(size_t pos, const sizet &new_value)
	{
		tree[pos += num_elems] = new_value;
		for (; pos > 1; pos >>= 1)
			tree[pos >> 1] = op(tree[pos], tree[pos ^ 1]);
	}

	sizet accumulate(size_t l, size_t r) const
	{
		sizet ans = at(l++);
		for (l += num_elems, r += num_elems; l < r; l >>= 1, r >>= 1)
		{
			if ((l & 1) != 0)
				ans = op(ans, tree[l++]);
			if ((r & 1) != 0)
				ans = op(ans, tree[--r]);
		}
		return ans;
	}

	const sizet &at(size_t pos) const
	{
		return tree[num_elems + pos];
	}

	size_t size() const
	{
		return num_elems;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sizet cases = 1;
	while (true)
	{
		sizet n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else if (cases > 1)
		{
			cout << "\n";
		}

		vector<sizet> potentiometers(n);
		for (sizet i = 0; i < n; ++i)
		{
			cin >> potentiometers[i];
		}

		segment_tree<std::plus<sizet>> segtree;
		segtree.assign(potentiometers.begin(), potentiometers.end());

		string query;
		sizet i, j;
		cout << "Case " << cases << ":\n";
		while (true)
		{
			cin >> query;
			if (query == "END")
			{
				break;
			}
			cin >> i >> j;
			if (query == "M")
			{
				cout << segtree.accumulate(i - 1, j) << "\n";
			}
			else
			{
				segtree.modify(i - 1, j);
			}
		}
		cases++;
	}
}
