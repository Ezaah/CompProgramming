#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

std::random_device rd;
std::mt19937 g(rd());
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << "0\n";
        return 0;
    }
    vector<ll> p(r + c);
    iota(p.begin(), p.end(), 1);
    if (r > c) {
        reverse(p.begin(), p.end());
    }
    vector<vector<ll>> matrix(r, vector<ll>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            // cout << "(" << i << "," << j << ") = " << p[i] << "*" << p[j + r] << endl;
            matrix[i][j] = p[i] * p[j + r];
        }
    }

    for (auto v : matrix) {
        for (ll x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
