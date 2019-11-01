#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

template <typename T>
void print_matrix(vector<vector<T>> &a)
{
	for (auto x : a)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> r(n + 1);
	vector<int> c(n + 1);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &r[i + 1]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &c[i + 1]);
	}

	vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	vector<vector<int>> component(n + 1, vector<int>(n + 1, -1));
	int curr_component = 1;

	function<void(int, int)> dfs;
	dfs = [&](int i, int j) {
		if (component[i][j] != -1)
		{
			return;
		}
		component[i][j] = curr_component;
		for (auto &dir : dirs)
		{
			int x = i + dir.first;
			int y = j + dir.second;
			if (x > n || x == 0)
			{
				continue;
			}

			if (y > n || y == 0)
			{
				continue;
			}

			if ((r[x] + c[y]) % 2 == 0)
			{
				dfs(x, y);
			}
		}
	};

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{

			if ((r[i] + c[j]) % 2 == 0)
			{
				dfs(i, j);
				++curr_component;
			}
			else
			{
				component[i][j] = 0;
			}
		}
	}

	while (q--)
	{
		int i, j, h, k;
		scanf("%d%d%d%d", &i, &j, &h, &k);
		if (component[i][j] == component[h][k])
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
}
