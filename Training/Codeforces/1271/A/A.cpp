#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int cost = 0;
    if (e > f) {
        int suits = min(a, d);
        cost += e * suits;
        a -= suits;
        d -= suits;

        if (d != 0) {
            suits = min({b, c, d});
            cost += f * suits;
        }
    } else {
        int suits = min({b, c, d});
        cost += f * suits;
        b -= suits;
        c -= suits;
        d -= suits;

        if (d != 0) {
            suits = min(a, d);
            cost += e * suits;
        }
    }
    cout << cost << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
