#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;

        vector<string> pins(n);
        set<string> used;
        for (int i = 0; i < n; ++i) {
            cin >> pins[i];
        }

        vector<string> ans(n);
        vector<pair<string, int>> repeated;
        int changes = 0;
        for (int i = 0; i < n; ++i) {
            if (used.find(pins[i]) == used.end()) {
                ans[i] = pins[i];
                used.insert(pins[i]);
                continue;
            } else {
                repeated.push_back({pins[i], i});
                changes++;
            }
        }

        for (auto &p : repeated) {
            string pin = p.first;
            int pos = p.second;
            for (int k = 0; k < 4; ++k) {
                int val = pin[k] - '0';

                string test = pin;
                bool found = 0;
                for (int j = 0; j < 10; ++j) {
                    if (j == val) {
                        continue;
                    }

                    test.replace(k, 1, to_string(j));
                    if (used.find(test) == used.end()) {
                        used.insert(test);
                        ans[pos] = test;
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        }

        cout << changes << "\n";
        for (auto &a : ans) {
            cout << a << "\n";
        }
    }
}
