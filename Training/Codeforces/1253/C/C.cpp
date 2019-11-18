#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> sweets(n);
    for (ll i = 0; i < n; ++i) {
        cin >> sweets[i];
    }

    sort(sweets.begin(), sweets.end());

    vector<ll> sugar(n);

    for (ll i = 0; i < n; ++i) {
        ll cnt = 1;
        ll taken = 0;
        for (ll j = i; j > -1; --j, taken++) {
            if (taken == m) {
                cnt++;
                taken = 0;
            }
            // cout << i << " " << sweets[j] << "*" << cnt << endl;
            sugar[i] += sweets[j] * (cnt);
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << sugar[i];
        if (i + 1 < n) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
}
