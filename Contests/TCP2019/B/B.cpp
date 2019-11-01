#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

struct circle
{
	sizet x;
	sizet y;
	sizet r;
};

bool intersection(const circle &a, const circle &b)
{
	sizet distance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	if (distance <= (a.r + b.r) * (a.r + b.r) && distance >= (a.r - b.r) * (a.r - b.r))
	{
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	cin >> n;
	vector<circle> circles;
	for (sizet i = 0; i < n; ++i)
	{
		sizet h, k, r;
		cin >> h >> k >> r;
		circles.push_back({h, k, r});
	}

	bool intersected = 0;
	for (sizet i = 0; i < n; ++i)
	{
		for (sizet j = i + 1; j < n; ++j)
		{
			if (intersection(circles[i], circles[j]))
			{
				intersected = 1;
				break;
			}
		}
	}

	if (intersected)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "SI\n";
	}
}
