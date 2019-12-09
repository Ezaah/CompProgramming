#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> flowers(n);
    for (int i = 0; i < n; ++i) {
        cin >> flowers[i];
    }

    sort(flowers.begin(), flowers.end());

    ll cntmin = 0;
    ll cntmax = 0;
    int diff = flowers.back() - flowers.front();
    for (int i = 0; i < n; ++i) {
        if (flowers[i] == flowers.front()) {
            cntmin++;
        }
    }

    for (int j = n - 1; j > -1; --j) {
        if (flowers[j] == flowers.back()) {
            cntmax++;
        }
    }
    ll cnt = cntmin * cntmax;
    if (cntmin == cntmax && cntmin == n) {
        cnt = cntmin * (cntmax - 1) / 2;
    }
    cout << diff << " " << cnt << "\n";
}
