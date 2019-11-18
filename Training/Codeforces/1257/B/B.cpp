//https://codeforces.com/contest/1257/problem/B
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;

        queue<ll> dq;
        dq.push(x);
        bool found = 0;
        unordered_set<ll> used;
        while (!dq.empty()) {
            ll a = dq.front();
            dq.pop();
            if (used.find(a) != used.end()) {
                continue;
            } else {
                used.insert(a);
            }

            if (a == y) {
                found = 1;
                break;
            }

            if (a > y) {
                found = 1;
                break;
            }
            if (a > 1) {
                dq.push(a - 1);
            }
            if (a % 2 == 0) {
                dq.push(3 * a / 2);
            }
        }
        if (!found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
