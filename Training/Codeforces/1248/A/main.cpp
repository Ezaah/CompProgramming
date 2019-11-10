#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet tests;
	scanf("%lld", &tests);
	while (tests--)
	{
		sizet n, m;
		scanf("%lld", &n);
		vector<sizet> up(n);
		for (sizet i = 0; i < n; ++i)
		{
			scanf("%lld", &up[i]);
		}
		scanf("%lld", &m);
		vector<sizet> down(m);
		for (sizet i = 0; i < m; ++i)
		{
			scanf("%lld", &down[i]);
		}

		sizet up_evens = count_if(up.begin(), up.end(), [&](sizet i) { return i % 2 == 0; });
		sizet up_odd = n - up_evens;
		sizet down_evens = count_if(down.begin(), down.end(), [&](sizet i) { return i % 2 == 0; });
		sizet down_odd = m - down_evens;

		printf("%lld\n", up_evens * down_evens + up_odd * down_odd);
	}
}
