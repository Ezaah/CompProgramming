#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    ll tests;
    cin >> tests;
    while (tests--) {
        ll n;
        cin >> n;

        /*
    14*n + 20 >= x =>   n >= x/14 - 20/14
    14*n + 15 <= x =>   n <= x/14 - 15/14

*/

        ll res = n % 14;

        if (res <= 6 && res != 0 && n > 14) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
