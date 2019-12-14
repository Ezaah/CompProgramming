#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_array(vector<int> a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> l(n, 1);
    vector<int> r(n, 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 2; i > -1; --i) {
        if (a[i] < a[i + 1]) {
            l[i] = l[i + 1] + 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            r[i] = r[i - 1] + 1;
        }
    }
    // print_array(l);
    // print_array(r);
    int ans = *max_element(l.begin(), l.end());

    for (int i = 1; i + 1 < n; ++i) {
        if (a[i - 1] < a[i + 1])
            ans = max(ans, l[i + 1] + r[i - 1]);
    }

    cout << ans << "\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
