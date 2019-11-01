#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n;
	cin >> n;
	vector<sizet> values(n);
	for (sizet i = 0; i < n; ++i)
	{
		cin >> values[i];
	}
	unordered_map<sizet, pair<sizet, sizet>> bst;

	vector<sizet> depths;
	depths.push_back(1);
	bst[1] = make_pair(values[0], 1);
	for (sizet i = 1; i < n; ++i)
	{
		sizet p = 1;
		sizet depth = 1;
		while (p <= pow(2, p + 1) + 1)
		{
			//cout << "Value " << values[i] << " p = " << p << " depth = " << depth << endl;

			if (values[i] <= bst[p].first)
			{
				if (bst.find(2 * p) == bst.end())
				{
					depths.push_back(depth + 1);
					bst[2 * p] = make_pair(values[i], depth + 1);
					break;
				}
				else
				{
					depth++;
					p = 2 * p;
				}
			}
			else
			{
				if (bst.find(2 * p + 1) == bst.end())
				{
					depths.push_back(depth + 1);
					bst[2 * p + 1] = make_pair(values[i], depth + 1);
					break;
				}
				else
				{
					depth++;
					p = 2 * p + 1;
				}
			}
		}
	}

	for (auto &elem : depths)
	{
		cout << elem << " ";
	}
	cout << endl;
}
