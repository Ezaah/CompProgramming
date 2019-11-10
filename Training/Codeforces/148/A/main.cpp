#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, l, m, n, d;

    cin >> k >> l >> m >> n >> d;

    vector<bool> dragons(d + 1, 0);
    for (ll i = 1; i <= d; ++i) {
        dragons[i] = dragons[i] || (i % k == 0);
        dragons[i] = dragons[i] || (i % l == 0);
        dragons[i] = dragons[i] || (i % m == 0);
        dragons[i] = dragons[i] || (i % n == 0);
    }

    cout << count(dragons.begin(), dragons.end(), true) << "\n";
}
