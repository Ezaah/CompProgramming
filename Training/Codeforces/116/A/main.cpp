#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll sum = 0;
    ll max_capacity = -1;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        sum += b - a;
        max_capacity = max(max_capacity, sum);
    }

    cout << max_capacity << endl;
}
