#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;
struct point
{
	sizet x;
	sizet y;
};
bool operator<(const point &a, const point &b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

bool check_up(vector<sizet> &sides)
{
	if (sides[0] >= sides[3])
	{
		return false;
	}

	if (sides[1] != sides[2])
	{
		return false;
	}

	if (sides[0] != sides[1] || sides[0] != sides[2])
	{
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet h, w;
	cin >> h >> w;
	vector<vector<char>> table(h, vector<char>(w));

	for (sizet i = 0; i < h; ++i)
	{
		for (sizet j = 0; j < w; ++j)
		{
			cin >> table[i][j];
		}
	}
	map<point, bool> centers;
	vector<pair<sizet, sizet>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	function<void(sizet, sizet)> is_center;
	is_center = [&](sizet i, sizet j) {
		if (table[i][j] != '*')
		{
			return;
		}
		for (auto dir : directions)
		{
			if (table[i + dir.first][j + dir.second] != '*')
			{
				return;
			}
		}

		centers.emplace(point{i, j}, false);
	};
	for (sizet i = 1; i < h - 1; ++i)
	{
		for (sizet j = 1; j < w - 1; j++)
		{
			is_center(i, j);
		}
	}

	vector<vector<bool>> visited(h, vector<bool>(w));
	bool delete_center = 0;
	function<void(sizet, sizet)> explore_center;
	explore_center = [&](sizet x, sizet y) {
		if (visited[x][y])
		{
			return;
		}
		// cout << "Visiting (" << x << "," << y << ")" << endl;
		visited[x][y] = 1;

		for (auto &dir : directions)
		{
			sizet i = x + dir.first;
			sizet j = y + dir.second;

			if (i == -1 || i == h)
			{
				continue;
			}

			if (j == -1 || j == w)
			{
				continue;
			}

			if (table[i][j] == '.')
			{
				continue;
			}

			if (centers.find({i, j}) != centers.end() && !visited[i][j])
			{
				// cout << "Found center (" << i << "," << j << ") deleting it" << endl;
				delete_center = 1;
				centers.at({i, j}) = 1;
			}

			explore_center(i, j);
		}
		return;
	};

	for (auto &center : centers)
	{
		// cout << "Starting explore with center (" << center.first << "," << center.second << ")" << endl;
		explore_center(center.first.x, center.first.y);
		if (delete_center)
		{
			// cout << "Deleting center (" << center.first << "," << center.second << ")" << endl;
			center.second = 1;
			delete_center = 0;
		}
	}

	function<sizet(const point &, sizet)> count_direction;
	count_direction = [&](const point &center, sizet dirId) {
		sizet cnt = 0;
		sizet i = center.x + directions[dirId].first;
		sizet j = center.y + directions[dirId].second;
		while (i < h && j < w && i > -1 && j > -1)
		{
			//cout << "Visiting (" << i << " , " << j << ") with Direction " << dirId << endl;
			if (table[i][j] == '*')
			{
				cnt++;
			}
			else
			{
				break;
			}
			i += directions[dirId].first;
			j += directions[dirId].second;
		}
		return cnt;
	};

	sizet cross = 0;
	for (auto &center : centers)
	{
		if (center.second)
		{
			continue;
		}
		// cout << "Checking center (" << center.first << " , " << center.second << ")" << endl;
		vector<sizet> sides(4);
		for (sizet k = 0; k < 4; ++k)
		{
			sides[k] = count_direction(center.first, k);
		}

		if (check_up(sides))
		{
			cross++;
		}
	}

	cout << cross << "\n";
}
