#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dist(int a, int b, int c) {
    return abs(a - b) + abs(a - c) + abs(b - c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int min_dist = std::numeric_limits<int>::max();

        min_dist = min(min_dist, dist(a, b, c));
        min_dist = min(min_dist, dist(a, b, c - 1));
        min_dist = min(min_dist, dist(a, b, c + 1));
        min_dist = min(min_dist, dist(a, b - 1, c));
        min_dist = min(min_dist, dist(a, b - 1, c - 1));
        min_dist = min(min_dist, dist(a, b - 1, c + 1));
        min_dist = min(min_dist, dist(a, b + 1, c));
        min_dist = min(min_dist, dist(a, b + 1, c - 1));
        min_dist = min(min_dist, dist(a, b + 1, c + 1));
        min_dist = min(min_dist, dist(a - 1, b, c));
        min_dist = min(min_dist, dist(a - 1, b, c - 1));
        min_dist = min(min_dist, dist(a - 1, b, c + 1));
        min_dist = min(min_dist, dist(a - 1, b - 1, c));
        min_dist = min(min_dist, dist(a - 1, b - 1, c - 1));
        min_dist = min(min_dist, dist(a - 1, b - 1, c + 1));
        min_dist = min(min_dist, dist(a - 1, b + 1, c));
        min_dist = min(min_dist, dist(a - 1, b + 1, c - 1));
        min_dist = min(min_dist, dist(a - 1, b + 1, c + 1));
        min_dist = min(min_dist, dist(a + 1, b, c));
        min_dist = min(min_dist, dist(a + 1, b, c - 1));
        min_dist = min(min_dist, dist(a + 1, b, c + 1));
        min_dist = min(min_dist, dist(a + 1, b - 1, c));
        min_dist = min(min_dist, dist(a + 1, b - 1, c - 1));
        min_dist = min(min_dist, dist(a + 1, b - 1, c + 1));
        min_dist = min(min_dist, dist(a + 1, b + 1, c));
        min_dist = min(min_dist, dist(a + 1, b + 1, c - 1));
        min_dist = min(min_dist, dist(a + 1, b + 1, c + 1));

        cout << min_dist << "\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
