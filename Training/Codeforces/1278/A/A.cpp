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
        string p, h;
        cin >> p >> h;

        vector<int> pfreq(256);
        for (char x : p) {
            pfreq[x]++;
        }
        bool found = 0;
        for (int i = 0; i < h.size(); ++i) {
            vector<int> hfreq = pfreq;
            for (int j = i; j < h.size(); ++j) {
                if (hfreq[h[j]] == 0) {
                    break;
                }

                hfreq[h[j]]--;
            }
            auto last = find_if(hfreq.begin(), hfreq.end(), [](int x) { return x != 0; });
            if (last == hfreq.end()) {
                found = 1;
                break;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
