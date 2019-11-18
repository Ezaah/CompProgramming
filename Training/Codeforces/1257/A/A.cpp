//https://codeforces.com/contest/1257/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, x, a, b;
        cin >> n >> x >> a >> b;
        ll closer_n = max(a, b);
        ll closer_1 = min(a, b);

        while (closer_1 != 1 && x > 0) {
            x--;
            closer_1--;
        }

        while (closer_n != n && x > 0) {
            x--;
            closer_n++;
        }

        cout << closer_n - closer_1 << "\n";
    }
}
