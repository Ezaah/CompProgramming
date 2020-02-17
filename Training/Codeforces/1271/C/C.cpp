#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;

    Point operator+(pair<int, int> d) {
        return {x + d.first, y + d.second};
    }
};

ll dist(Point &a, Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    ll n;
    cin >> n;

    Point school;
    cin >> school.x >> school.y;

    vector<pair<Point, ll>> students(n);
    for (ll i = 0; i < n; ++i) {
        cin >> students[i].first.x >> students[i].first.y;
        students[i].second = dist(students[i].first, school);
    }

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    Point best;
    ll maxd = 0;
    ;

    for (pair<int, int> d : dir) {
        Point tent = school + d;
        ll cnt = 0;
        for (ll i = 0; i < n; ++i) {
            if (dist(tent, students[i].first) <= students[i].second) {
                cnt++;
            }
        }

        if (cnt > maxd) {
            best = tent;
            maxd = cnt;
        }
    }
    cout << maxd << "\n";
    cout << best.x << " " << best.y << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
