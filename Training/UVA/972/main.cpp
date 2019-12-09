#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    ll n;
    vector<double> f(100);
    vector<double> g(100);
    while (cin >> n) {
        auto pos = f.begin();
        for (ll i = 0; i < n; ++i) {
            double val, len;
            cin >> val >> len;

            ll to = len * 10 + 0.5;

            fill(pos, pos + to, val);
            pos += to;
        }

        ll m;
        cin >> m;
        pos = g.begin();
        for (ll i = 0; i < m; ++i) {
            double val, len;
            cin >> val >> len;

            ll to = len * 10 + 0.5;

            fill(pos, pos + to, val);
            pos += to;
        }

        vector<double> h(100);
        for (ll i = 0; i < 100; ++i) {
            // cout << f[i] << " " << g[i] << endl;
            h[i] = max(f[i], g[i]);
        }

        double mini = *min_element(h.begin(), h.end());

        printf("%.3f\n", mini);
    }
}
