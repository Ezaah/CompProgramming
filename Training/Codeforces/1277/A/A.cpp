#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int tests;
    cin >> tests;

    while (tests--) {
        ll n;
        cin >> n;

        ll cnt = 0;

        for (ll i = 1; i < 10; ++i) {
            string val = to_string(i);
            while (stoll(val) <= n) {
                // cout << val << " " << n << endl;
                cnt++;
                val += to_string(i);
            }
        }

        cout << cnt << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
