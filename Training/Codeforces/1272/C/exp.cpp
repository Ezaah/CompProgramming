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

    int cnt = 0;
    vector<string> segments;
    for (int j = 0; j < n; ++j) {
        string sub = "";
        for (int i = j; i < n; ++i) {
            sub += word[i];
            segments.push_back(sub);
        }
    }
    for (string str : segments) {
        bool valid = 1;
        for (char chr : str) {
            if (aval.find(chr) == aval.end()) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    // #ifdef LOCAL_DEFINE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
}
