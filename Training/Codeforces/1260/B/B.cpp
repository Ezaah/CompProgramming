#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        if (a > b) {
            swap(a, b);
        }
        if ((a + b) % 3 == 0 && 2 * a >= b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
