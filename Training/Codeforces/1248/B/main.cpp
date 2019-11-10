#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	scanf("%lld", &n);
	vector<sizet> sticks(n);
	for (sizet i = 0; i < n; ++i)
	{
		scanf("%lld", &sticks[i]);
	}

	sort(sticks.rbegin(), sticks.rend());
	sizet x = 0;
	sizet y = 0;
	for (sizet i = 0; i < n; ++i)
	{
		if (i < ceil((double)n / 2))
		{
			x += sticks[i];
		}
		else
		{
			y += sticks[i];
		}
	}

	printf("%lld\n", x * x + y * y);
}
