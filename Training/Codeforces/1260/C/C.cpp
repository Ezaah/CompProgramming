#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll r, b, k;
        cin >> r >> b >> k;

        if (r > b) {
            swap(r, b);
        }

        ll values = ((2 * b - 1) / r) - (b / r);

        if (values >= k) {
            cout << "REBEL\n";
        } else {
            cout << "OBEY\n";
        }
    }
}
