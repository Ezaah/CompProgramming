#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_vector(vector<sizet> &a)
{
	for (auto x : a)
	{
		printf("%lld ", x);
	}
	printf("\n\n");
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet queries;
	scanf("%lld", &queries);
	while (queries--)
	{
		sizet n;
		scanf("%lld", &n);
		vector<vector<sizet>> adj_list(n);
		for (sizet i = 0; i < n; ++i)
		{
			sizet v;
			scanf("%lld", &v);
			adj_list[i].push_back(v - 1);
		}

		vector<bool> visited(n);
		vector<sizet> days(n);
		vector<sizet> in_loop;
		function<void(sizet, sizet)> dfs;
		dfs = [&](sizet vertex, sizet dist) {
			if (visited[vertex])
			{

				for (auto v : in_loop)
				{

					days[v] = dist;
				}
				return;
			}

			visited[vertex] = 1;
			in_loop.push_back(vertex);

			for (auto v : adj_list[vertex])
			{

				dfs(v, dist + 1);
			}
		};

		for (sizet i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				in_loop.clear();
				dfs(i, 0);
			}
		}

		for (sizet i = 0; i < n; ++i)
		{
			printf("%lld", days[i]);
			if (i + 1 < n)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
}
