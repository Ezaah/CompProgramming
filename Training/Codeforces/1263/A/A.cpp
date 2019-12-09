#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll r, g, b;
        cin >> r >> g >> b;

        ll sum = r + g + b;
        ll maxi = max({r, g, b});
        if (sum > 2 * maxi) {
            cout << sum / 2 << "\n";
        } else {
            cout << sum - maxi << "\n";
        }
    }
}
