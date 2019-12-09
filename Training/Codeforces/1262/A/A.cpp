#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_vector(vector<int> a) {
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;

        int maxi = 0;
        int mini = 1e9 + 1;
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            maxi = max(l, maxi);
            mini = min(r, mini);
        }
        cout << max(maxi - mini, 0) << "\n";
    }
}
