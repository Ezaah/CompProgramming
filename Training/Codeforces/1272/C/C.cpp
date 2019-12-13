#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    string word;
    cin >> word;

    set<char> aval;
    for (int i = 0; i < k; ++i) {
        char x;
        cin >> x;
        aval.insert(x);
    }

    ll cnt = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        while (aval.count(word[j]) && j < n) {
            j++;
        }
        // cout << i << " " << j << endl;

        ll dis = j - i;
        cnt += dis * (dis + 1) / 2;
        i = j + 1;
    }

    cout << cnt << "\n";

    // #ifdef LOCAL_DEFINE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
}
