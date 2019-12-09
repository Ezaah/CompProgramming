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

        vector<int> perm(n);
        vector<int> q(n);
        set<int> values;
        for (int i = 0; i < n; ++i) {
            cin >> q[i];
            values.insert(i + 1);
        }
        bool impossible = 0;

        for (int i = 0; i < n; ++i) {
            if (q[i] >= i + 1 && values.find(q[i]) != values.end()) {
                perm[i] = q[i];
                values.erase(q[i]);
            } else if (q[i] < i + 1) {
                impossible = 1;
            }
        }

        if (impossible) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (perm[i] == 0) {
                perm[i] = *values.begin();
                values.erase(*values.begin());
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << perm[i];
            if (i + 1 < n) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }
}
