#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n, p;
	scanf("%lld%lld", &n, &p);
	vector<sizet> ready(n);
	for (sizet i = 0; i < n; ++i)
	{
		scanf("%lld", &ready[i]);
	}

	priority_queue<pair<sizet, sizet>, vector<pair<sizet, sizet>>, greater<pair<sizet, sizet>>> waitline;
	for (sizet i = 0; i < n; ++i)
	{
		waitline.push(make_pair(ready[i], i));
	}

	sizet t = 0;
	vector<sizet> waited(n);
	while (!waitline.empty())
	{
		auto person = waitline.top();
		waitline.pop();
		if (person.first >= t)
		{
			t = person.first;
		}
		else
		{
			waitline.push(make_pair(t, person.second));
			continue;
		}
		t += p;
		waited[person.second] = t;
	}

	for (sizet i = 0; i < n; ++i)
	{

		printf("%lld", waited[i]);
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
