#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	scanf("%d", &n);
	vector<int> perm(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &perm[i]);
	}

	int obj = n + 1;

	for (sizet i = 0; i < n; ++i)
	{
		printf("%d", obj - perm[i]);
		if (i + 1 < n)
		{
			printf(" ");
		}
	}
	printf("\n");
}
