#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int best = 1e9;
    for (int k = 0; k < m - n + 1; ++k) {
        best = min(best, p[k + n - 1] - p[k]);
    }
    cout << best << "\n";
}
