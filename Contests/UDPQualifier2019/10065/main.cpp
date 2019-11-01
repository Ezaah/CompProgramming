#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

double pi()
{
	return acos(-1);
}

template <typename BidirectionalIt>
BidirectionalIt make_convex_set(BidirectionalIt first, BidirectionalIt last,
								bool with_collinear_points)
{
	using point_t = typename BidirectionalIt::value_type;

	auto end = first;
	for (auto i = first; i != last; ++i)
	{
		auto is_clockwise = [&](const point_t &p0, const point_t &p1,
								const point_t &p2) {
			auto cross = [&](const point_t &p, const point_t &q) {
				return p.x * q.y - p.y * q.x;
			};

			return with_collinear_points ? cross(p1 - p0, p2 - p0) < 0
										 : cross(p1 - p0, p2 - p0) <= 0;
		};

		while (end - first >= 2 && is_clockwise(end[-2], end[-1], *i))
			--end;
		*end++ = std::move(*i);
	}
	return --end;
}

template <typename ForwardIt>
std::vector<typename std::iterator_traits<ForwardIt>::value_type>
convex_hull(ForwardIt first, ForwardIt last,
			bool with_collinear_points = false)
{
	std::size_t n = std::distance(first, last);
	using point_t = typename std::iterator_traits<ForwardIt>::value_type;

	std::vector<point_t> hull(2 * n);
	std::copy(first, last, hull.begin());
	auto middle =
		make_convex_set(hull.begin(), hull.begin() + n, with_collinear_points);
	std::reverse_copy(first, last, middle);
	hull.erase(make_convex_set(middle, middle + n, with_collinear_points),
			   hull.end());
	return hull;
}

struct Point
{
	sizet x;
	sizet y;
	bool operator<(const Point &other)
	{
		if (x == other.x)
		{
			return y < other.y;
		}
		return x < other.x;
	}
	friend Point operator-(const Point &p, const Point &q)
	{
		return {p.x - q.x, p.y - q.y};
	}

	friend Point operator+(const Point &p, const Point &q)
	{
		return {p.x + q.x, p.y + q.y};
	}

	Point operator*(const sizet k)
	{
		return {x * k, y * k};
	}
};

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

	sizet corners;
	sizet tests = 1;
	while (cin >> corners)
	{
		if (corners == 0)
		{
			break;
		}
		vector<Point> tile, tile_unsorted;
		for (sizet i = 0; i < corners; ++i)
		{
			sizet x, y;
			cin >> x >> y;
			tile.push_back({x, y});
			tile_unsorted.push_back({x, y});
		}
		sort(tile.begin(), tile.end());
		auto container = convex_hull(tile.begin(), tile.end());

		double tile_area = shoelace_area(tile_unsorted) / 2;
		double container_area = shoelace_area(container) / 2;

		double unused_area = container_area - tile_area;
		double percentage = 100 * unused_area / container_area;
		//printf("Tile: %.5f \t Container: %.5f \t Unused: %.5f\n", tile_area, container_area, unused_area);
		printf("Tile #%lli\nWasted Space = %.2f %%\n\n", tests, percentage);
		tests++;
	}
}
