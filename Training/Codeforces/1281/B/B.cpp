#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(string a, string b) {

    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if (a[i] < b[i]) {
            return true;
        }
        if (a[i] > b[i]) {
            return false;
        }
    }
    if (b.substr(0, a.size()) == a && a != b) {
        return true;
    }

    return false;
}

string solve(string a) {
    int n = a.size();
    int k = 0;
    while (k < n) {
        int minv = 30;
        int posv = n;
        for (int i = k; i < n; ++i) {
            // cout << i << " " << a[i] - 'A' << " vs " << minv << " " << a[i] << endl;
            if (a[i] - 'A' <= minv) {
                posv = i;
                minv = a[i] - 'A';
            }
        }

        // cout << a[posv] << " " << a[k] << endl;
        if (posv == k || a[posv] == a[k]) {
            k++;
            continue;
        }

        swap(a[posv], a[k]);
        break;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int tests;
    cin >> tests;
    while (tests--) {
        string a, b;
        cin >> a >> b;

        if (!cmp(a, b)) a = solve(a);
        // cout << a << " " << b << endl;
        if (cmp(a, b)) {
            cout << a << "\n";
        } else {
            cout << "---\n";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
