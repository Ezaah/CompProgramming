#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_v(vector<ll> a) {
    for (auto x : a) {
        cout << x;
    }
    cout << endl;
}
ll M = 1e9 + 7;
ll mod_add(ll a, ll b, ll m = M) {
    if (a < m - b) {
        return a + b;
    }
    return a - (m - b);
}

ll mod_mul(ll a, ll b, ll m = M) {
    ll res = 0;
    while (b) {
        if (b % 2) {
            res = mod_add(a, res, m);
        }
        a = mod_add(a, a, m);
        b /= 2;
    }
    return res;
}

ll mod_sub(ll a, ll b, ll m = M) {
    if (a < b) {
        return a + (m - b);
    }
    return a - b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int tests;
    cin >> tests;
    while (tests--) {
        ll x;
        cin >> x;
        string seq;
        cin >> seq;

        vector<ll> s;
        for (ll i = 0; i < seq.size(); ++i) {
            s.push_back(seq[i] - '0');
        }

        ll ans = s.size();
        for (ll i = 0; i < x; ++i) {
            for (ll k = 1; k < s[i]; ++k) {
                if (s.size() >= x) {
                    break;
                }
                for (ll j = i + 1; j < ans; ++j) {
                    s.push_back(s[j]);
                }
            }

            ll clip = mod_sub(ans, i + 1);
            ans = mod_add(i + 1, mod_mul(clip, s[i]));
        }

        cout << ans << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
