#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    ll n, m;
    cin >> n >> m;

    vector<ll> a(m + 1), b(m + 1);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[x]++;
    }

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        b[x]++;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
