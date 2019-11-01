#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

struct Point
{
	double x;
	double y;
};

const double pi = std::acos(-1);

Point rotate(const Point &p, const double theta)
{
	return {
		p.x * std::cos(theta) - p.y * std::sin(theta),
		p.x * std::sin(theta) + p.y * std::cos(theta)};
}

double shoelace_area(const std::vector<Point> &poly)
{
	assert(poly.size() >= 3);
	using std::size_t;

	double sum = 0;
	const size_t n = poly.size();
	for (size_t i = 1; i + 1 < n; ++i)
		sum += poly[i].x * (poly[i + 1].y - poly[i - 1].y);
	sum += poly[0].x * (poly[1].y - poly[n - 1].y);
	sum += poly[n - 1].x * (poly[0].y - poly[n - 2].y);
	return std::abs(sum);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	sizet n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}

		std::vector<Point> vertices(n);
		std::vector<bool> poly(n);
		std::fill(poly.begin(), poly.begin() + m, true);
		Point original({1, 0});
		for (sizet i = 0; i < n; ++i)
		{
			double param;
			cin >> param;
			vertices[i] = rotate(original, 2.0 * pi * param);
		}

		double max_area = 0;
		do
		{
			vector<Point> polygon;
			for (sizet i = 0; i < n; ++i)
			{
				if (poly[i])
				{
					polygon.push_back(vertices[i]);
				}
			}
			max_area = std::max(max_area, shoelace_area(polygon) / 2.0);
		} while (std::prev_permutation(poly.begin(), poly.end()));

		printf("%.6f\n", max_area);
	}
}
