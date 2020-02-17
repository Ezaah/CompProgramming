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
        ll a, b;
        cin >> a >> b;
        ll cnt = 0;

        function<bool()> cmp;
        cmp = [&]() {
            ll sum = cnt * (cnt + 1) / 2;
            ll dif = abs(a - b);

            return sum < dif || (sum - dif) % 2 != 0;
        };
        while (cmp()) {
            cnt++;
        }
        cout << cnt << "\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
