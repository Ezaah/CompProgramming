#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet tests;
	cin >> tests;
	vector<sizet> cases;
	while (tests--)
	{
		sizet src_ones = 0;
		sizet tgt_ones = 0;
		sizet src_incog = 0;
		string source;
		string target;
		cin >> source >> target;

		for (sizet i = 0; i < (sizet)source.size(); i++)
		{
			if (source[i] == '1')
			{
				src_ones++;
			}
			else if (source[i] == '?')
			{
				src_incog++;
			}

			if (target[i] == '1')
			{
				tgt_ones++;
			}
		}
		sizet cnt = 0;
		// cout << src_ones << " " << tgt_ones << " " << src_incog << endl;
		if (src_ones > tgt_ones)
		{
			cases.push_back(-1);
			continue;
		}
		else if (src_ones == tgt_ones)
		{
			for (sizet i = 0; i < (sizet)source.size(); ++i)
			{
				if (target[i] == '1' && source[i] != target[i])
				{
					cnt++;
				}
			}
			cases.push_back(cnt + src_incog);
		}
		else
		{
			if (src_ones + src_incog >= tgt_ones)
			{
				for (sizet i = 0; i < (sizet)source.size(); ++i)
				{
					sizet max_incog = tgt_ones - src_ones;
					if (source[i] == '1' && target[i] != source[i])
					{
						cnt++;
					}
					else if (source[i] == '?' && target[i] == '1')
					{
						if (max_incog > 0)
						{
							max_incog--;
						}
						else
						{
							cnt++;
						}
					}
				}
			}
			else
			{
				for (sizet i = 0; i < (sizet)source.size(); ++i)
				{
					if (target[i] == '1' && source[i] == '0')
					{
						cnt++;
					}
				}
			}
			cases.push_back(cnt + src_incog);
		}
	}

	for (sizet i = 0; i < (sizet)cases.size(); ++i)
	{
		cout << "Case " << i + 1 << ": " << cases[i] << "\n";
	}
}
