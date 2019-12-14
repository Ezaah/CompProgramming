#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int tests;
    cin >> tests;
    while (tests--) {
        ll n;
        cin >> n;
        vector<ll> val(n);
        for (ll i = 0; i < n; ++i) {
            cin >> val[i];
        }

        sort(val.rbegin(), val.rend());

        set<ll> steps;
        for (ll i = 0; i < n; ++i) {
            while (val[i] % 2 == 0) {
                steps.insert(val[i]);
                val[i] >>= 1;
            }
        }

        cout << steps.size() << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
