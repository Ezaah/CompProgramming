#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_solution(vector<sizet> &a)
{
	cout << "YES\n";
	for (sizet i = 0; i < a.size(); ++i)
	{
		cout << a[i];
		if (i + 1 < a.size())
		{
			cout << " ";
		}
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n, a, b;
	cin >> n >> a >> b;

	sizet max_distance = b - a;
	sizet c = n % b;
	vector<sizet> values;
	if (c >= a)
	{

		values.push_back(c);
		for (sizet i = 0; i < n / b; ++i)
		{
			values.push_back(b);
		}
		print_solution(values);
		return 0;
	}
	sizet distance = a - c;
	if (distance <= max_distance)
	{

		sizet d = b - distance;
		if (n % d != 0)
		{
			values.push_back(a);
		}
		for (sizet i = 0; i < n / d; ++i)
		{
			values.push_back(d);
		}
		print_solution(values);
		return 0;
	}

	cout << "NO\n";
}
