#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> tasks(m);
    for (ll i = 0; i < m; ++i) {
        cin >> tasks[i];
    }

    ll sum = 0;
    ll pos = 1;
    for (ll i = 0; i < m; ++i) {

        if (tasks[i] < pos) {
            sum += n - pos + 1;
            pos = 1;
        }

        sum += tasks[i] - pos;
        pos = tasks[i];
    }

    cout << sum << "\n";
}
