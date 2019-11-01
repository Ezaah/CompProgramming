#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long double n, m, x, y;
	cin >> n >> m >> x >> y;

	double a = (x / n + y / m) * 0.5;
	double b = (x + y) / (n + m);

	if (a == b)
	{
		cout << "C\n";
	}
	else if (a < b)
	{
		cout << "B\n";
	}
	else
	{
		cout << "A\n";
	}
}
