#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        sum += temp;
    }

    cout << ceil((double)abs(sum) / (double)x) << endl;
}
