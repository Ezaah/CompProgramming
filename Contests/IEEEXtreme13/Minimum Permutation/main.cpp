#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

void print_vector(vector<sizet> &a)
{
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

	sizet n, m;
	cin >> n >> m;
	vector<sizet> arr(n);

	for (sizet i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<sizet> set_perm(m);
	for (sizet i = 0; i < m; ++i)
	{
		cin >> set_perm[i];
	}
	sort(set_perm.begin(), set_perm.end());
	sizet i = 0;
	sizet j = 0;
	vector<sizet> output;
	while (i < n && j < m)
	{
		if (arr[i] < set_perm[j])
		{
			output.push_back(arr[i]);
			i++;
		}
		else
		{
			output.push_back(set_perm[j]);
			j++;
		}
	}
	if (i != n)
	{
		for (; i < n; ++i)
		{
			output.push_back(arr[i]);
		}
	}

	if (j != m)
	{
		for (; j < m; ++j)
		{
			output.push_back(set_perm[j]);
		}
	}
	print_vector(output);
}
