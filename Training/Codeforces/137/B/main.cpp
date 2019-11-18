#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<bool> elems(5001);
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        if (elems[x] || x > n) {
            cnt++;
        }
        elems[x] = 1;
    }

    cout << cnt << "\n";
}
