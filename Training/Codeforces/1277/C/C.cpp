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
        string text;
        cin >> text;

        vector<ll> pos;
        ll i = 0;
        while (i != text.npos) {
            i = text.find("twone", i);
            if (i == text.npos) {
                break;
            }
            text[i + 2] = '?';
            pos.push_back(i + 3);
        }
        i = 0;
        while (i != text.npos) {
            i = text.find("one", i);
            if (i == text.npos) {
                break;
            }
            text[i + 1] = '?';
            pos.push_back(i + 2);
        }

        i = 0;
        while (i != text.npos) {
            i = text.find("two", i);
            if (i == text.npos) {
                break;
            }
            text[i + 1] = '?';
            pos.push_back(i + 2);
        }
        cout << pos.size() << "\n";
        for (ll x : pos) {
            cout << x << " ";
        }
        cout << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
