#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> cards(n);
    for (ll i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    for (ll i = n - 1; i > 0; --i) {
        // cout << "checking cards " << i << " and " << i - 1 << endl;
        if (cards[i - 1] >= cards[i]) {
            // cout << "Setting card " << i << " as inf" << endl;
            cards[i] = 14;
        }
    }

    cout << count_if(cards.begin(), cards.end(), [](ll x) { return x < 14; }) << "\n";
}
