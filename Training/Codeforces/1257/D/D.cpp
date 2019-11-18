//https://codeforces.com/contest/1257/problem/D
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
        vector<ll> monsters(n);
        for (ll i = 0; i < n; ++i) {
            cin >> monsters[i];
        }

        ll m;
        cin >> m;
        vector<ll> powers(m);
        vector<ll> endurance(m);
        for (ll i = 0; i < m; ++i) {
            cin >> powers[i] >> endurance[i];
        }

        bool impossible = 0;
        ll k = 0;
        ll days = 0;
        while (k != n) {
            ll max_k = 0;
            for (ll i = 0; i < m; ++i) {
                // ll acc_power = powers[i] * endurance[i];
                // ll j = k + endurance[i];
                // if (j > n) {
                //     j = n;
                // }
                // cout << "Querying (" << k << " " << j << ") for hero " << i << endl;
                // cout << "\t" << query(k, j) << " vs " << acc_power << endl;
                // if (query(k, j) <= acc_power) {
                //     max_k = max(max_k, endurance[i]);
                // }
                ll monsters_left = endurance[i];
                for (ll j = k; j < n; ++j) {

                    if (powers[i] < monsters[j] || monsters_left == 0) {

                        max_k = max(max_k, j);
                        break;
                    } else {

                        monsters_left--;
                        if (j + 1 == n) {
                            max_k = max(max_k, n);
                        }
                    }
                }
            }

            if (max_k == k) {
                impossible = 1;
                break;
            }

            days++;
            k = max_k;
        }

        if (impossible) {
            days = -1;
        }

        cout << days << endl;
    }
}
