#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet queries;
	scanf("%lld", &queries);
	while (queries--)
	{
		sizet n;
		scanf("%lld", &n);
		vector<sizet> skills(n);
		for (sizet i = 0; i < n; ++i)
		{
			scanf("%lld", &skills[i]);
		}

		sort(skills.begin(), skills.end());

		vector<vector<sizet>> teams(1);
		teams[0].push_back(skills[0]);
		for (sizet i = 1; i < n; ++i)
		{
			sizet k = 0;
			while (k < (sizet)teams.size())
			{
				bool unfit = 0;
				for (sizet j = 0; j < (sizet)teams[k].size(); ++j)
				{
					if (abs(skills[i] - teams[k][j]) == 1)
					{
						unfit = 1;
						break;
					}
				}

				if (unfit)
				{
					k++;
				}
				else
				{
					teams[k].push_back(skills[i]);
					break;
				}
			}
			if (k == (sizet)teams.size())
			{
				teams.push_back(vector<sizet>(1, skills[i]));
			}
		}
		printf("%lld\n", (sizet)teams.size());

		// sizet teams = 1;
		// for (sizet i = 0; i < n - 1; ++i)
		// {
		// 	if (abs(skills[i] - skills[i - 1]) == 1)
		// 	{
		// 		teams++;
		// 	}
		// }

		// printf("%lld\n", teams);
	}
}
