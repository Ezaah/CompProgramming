#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        set<ll> ans;
        ans.insert(0);
        for (ll i = 1; i * i < n + 1; i++) {
            ans.insert(n / i);
            ans.insert(i);
        }

        cout << ans.size() << "\n";
        for (auto &elem : ans) {
            cout << elem << " ";
        }
        cout << "\n";
    }
}
