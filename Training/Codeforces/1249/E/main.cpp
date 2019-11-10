#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n, c;
	scanf("%lld%lld", &n, &c);

	vector<sizet> stairs(n - 1);
	vector<sizet> elevator(n - 1);
	for (sizet i = 0; i < n - 1; ++i)
	{
		scanf("%lld", &stairs[i]);
	}
	for (sizet i = 0; i < n - 1; ++i)
	{
		scanf("%lld", &elevator[i]);
	}

	vector<sizet> cost(n + 1, -1);
	cost[0] = 0;
	function<sizet(sizet)> dp;
	dp = [&](sizet i) {
		if (cost[i] != -1)
		{
			return cost[i];
		}
		printf("%lld : S[%lld] = %lld    E[%lld] = (%lld + %lld)\n", i, i - 1, stairs[i - 1], i - 1, elevator[i - 1], c);
		cost[i] = min(dp(i - 1) + stairs[i - 1], dp(i - 1) + c + elevator[i - 1]);
		return cost[i];
	};
	dp(n);
	for (sizet i = 0; i < n + 1; ++i)
	{
		printf("%lld ", cost[i]);
	}
	printf("\n");
}
