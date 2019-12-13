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
        string sequence;
        cin >> sequence;

        map<char, int> cnt = {{'R', 0}, {'U', 0}, {'L', 0}, {'D', 0}};
        for (char cmd : sequence) {
            cnt[cmd]++;
        }

        int hor = min(cnt['L'], cnt['R']);
        int ver = min(cnt['U'], cnt['D']);

        if (hor == 0 && ver == 0) {
            cout << "0\n\n";
            continue;
        }

        if (hor == 0) {
            ver = 1;
        }
        if (ver == 0) {
            hor = 1;
        }
        string ans = "";
        for (int i = 0; i < hor; ++i) {
            ans += "L";
        }

        for (int i = 0; i < ver; ++i) {
            ans += "U";
        }

        for (int i = 0; i < hor; ++i) {
            ans += "R";
        }

        for (int i = 0; i < ver; ++i) {
            ans += "D";
        }

        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
