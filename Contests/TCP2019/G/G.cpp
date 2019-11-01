#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	cin >> n;
	vector<sizet> armies(n);
	for (sizet i = 0; i < n; ++i)
	{
		cin >> armies[i];
	}

	sort(armies.begin() + 1, armies.end());
}
