#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> values(n);
    for (ll i = 0; i < n; ++i) {
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    ll sum = 0;
    ll i = 1;
    for (ll val : values) {

        sum += abs(i - val);
        ++i;
    }

    cout << sum << "\n";
}
