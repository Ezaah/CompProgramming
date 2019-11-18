#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tests;
    cin >> tests;
    while (tests--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        vector<ll> b(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; ++i) {
            cin >> b[i];
        }

        bool impossible = 0;
        vector<ll> diffs(n);
        for (ll i = 0; i < n; ++i) {
            diffs[i] = b[i] - a[i];
        }

        ll delta = -1;
        vector<pair<ll, ll>> ranges;
        ll L = 0;
        while (L < n) {

            if (diffs[L] < 0) {
                impossible = 1;
                break;
            }

            if (diffs[L] == 0) {
                ++L;
                continue;
            }

            delta = diffs[L];

            ll R = L;
            while (R + 1 < n) {

                if (diffs[R + 1] != delta) {
                    break;
                }
                ++R;
            }

            ranges.push_back({L, R});
            L = R + 1;
        }

        if (ranges.size() > 1) {
            impossible = 1;
        }

        if (impossible) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
